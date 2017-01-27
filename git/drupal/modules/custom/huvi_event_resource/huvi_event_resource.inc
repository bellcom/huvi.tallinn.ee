<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function _eventresource_create($data) {
  $response_text = array();
 foreach ($data['events'] as $key => $event) {
  $nid = huvi_event_resource_add_event($event);
  $response_text[] = 'Event ' . $event['id'] . ' was saved into node ' . $nid;

 }
  return (object)array(
      'status' => 'OK',
      'response' => $response_text,
    );
}
function huvi_event_resource_add_event($data) {
  global $user;
  $requered_fields = array ('name', 'description', 'type');

  // Requered fields checking
  foreach ($requered_fields as $field_name)
    if (!isset($data[$field_name]) || empty($data[$field_name]))
        return services_error('Requered field ' . $field_name . ' is missing', 406);

   if (!isset($data['active']) || !in_array($data['active'], array(0, 1)))
        return services_error('Requered field active is missing', 406);
   // Check if the node exists already
   if (isset($data['id']) && !empty($data['id'])){
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
     ->entityCondition('bundle', 'event')
     ->fieldCondition('field_id', 'value', $data['id'], '=')
     ->execute();

   // Node exists, load the entity
   if($result) {
     foreach($result['node'] as $key => $val) {
       $entity_load = entity_load('node', array($key));
       foreach($entity_load as $ekey => $eval) {
         $entity = $eval;
       }
     }
   }
   // Node doesn't exist yet, create a new entity
   else {
   $values = array(
       'type' => 'event',
       'uid' => $user->uid,
       'comment' => 0,
       'promote' => 0,
       'language' => 'et',
     );
   $entity = entity_create('node', $values);
   }
  }
  else {
     //*ID is missing. Create new node
    $values = array(
      'type' => 'event',
      'uid' => $user->uid,
      'comment' => 0,
      'promote' => 0,
      'language' => 'et',
    );
    $entity = entity_create('node', $values);
  }

  $w = entity_metadata_wrapper('node', $entity);
  $fields = huvi_event_resource_event_to_node_fields();



  foreach($fields as $event_item => $field) {
    if(isset($data[$event_item])) {
      switch($event_item) {
        case 'images':
           $files= array();
         foreach($data[$event_item] as $key => $val) {
          if($file = huvi_event_resource_file_upload($val['filename'], $val['url'])){
            $files[]=array('fid'=>$file->fid);
          }
         }
         $w->{$field}->set($files);
         break;
        case 'schedule':
          if(!empty($entity->field_schedule['und'])) {
            $s_values = array();
            foreach($entity->field_schedule['und'] as $s_key => $s_val) {
              $s_values[] = $s_val['value'];
              unset($entity->field_schedule['und'][$s_key]);
            }
            if(!empty($s_values)) {
              entity_delete_multiple('field_collection_item', $s_values);
            }
          }
          foreach($data[$event_item] as $key => $val) {
            $schedule_item = entity_create('field_collection_item', array('field_name' => 'field_schedule'));
            $schedule_item->setHostEntity('entity', $entity);
            $schedule_wrapper = entity_metadata_wrapper('field_collection_item', $schedule_item);
            $timezone = "Europe/Tallinn";
            if(isset($val['start_time'])) {
              if (isset($val['timezone']))
                $timezone = $val['timezone'];
              $start_time = new DateTime($val['start_time'], new DateTimeZone($timezone));
              if(isset($val['end_time']))
                $end_time = new DateTime($val['end_time'], new DateTimeZone($timezone));

              $schedule_wrapper->field_schedule_date[0]->set(array(
                  'value' =>  $start_time->format('U'),
                  'value2' => isset($end_time) ? $end_time->format('U'): null,
                  'rrule' => isset($val['rrule'])? $val['rrule'] : ""
                ));

            }
            $city_area = isset($val['city_area']) ? $val['city_area'] : $data['city_area'];
            $place = isset($val['place']) ? $val['place'] : $data['place'];
            $toimumiskoht = isset($val['place']) ? $val['toimumiskoht'] : $data['toimumiskoht'];
            if (isset($city_area) && $city_id = huvi_event_resource_get_city_id($city_area) )
              $schedule_wrapper->field_schedule_city_id->set($city_id);
            $schedule_wrapper->field_schedule_place->set($place);
            if (isset($toimumiskoht) && $toimumiskoht = taxonomy_get_term_by_name($toimumiskoht, 'toimumiskoht'))
             $schedule_wrapper->field_schedule_toimumis->set(key($toimumiskoht));
          }
          break;
        case 'korraldaja':
          if(!empty($entity->field_korraldaja['und'])) {
            $s_values = array();
            foreach($entity->field_korraldaja['und'] as $s_key => $s_val) {
              $s_values[] = $s_val['value'];
              unset($entity->field_korraldaja['und'][$s_key]);
            }
            if(!empty($s_values)) {
              entity_delete_multiple('field_collection_item', $s_values);
            }
          }
          foreach($data[$event_item] as $key => $val) {
            $korraldaja_item = entity_create('field_collection_item', array('field_name' => 'field_korraldaja'));
            $korraldaja_item->setHostEntity('entity', $entity);
            $korraldaja_wrapper = entity_metadata_wrapper('field_collection_item', $korraldaja_item);

            if(isset($val['name']))
                $korraldaja_wrapper->field_korraldaja_nimi->set($val['name']);
            if(isset($val['phone']))
                $korraldaja_wrapper->field_korraldaja_kontakttelefon->set($val['phone']);
            if(isset($val['email']))
                $korraldaja_wrapper->field_korraldaja_e_post->set($val['email']);

          }
          break;
        case 'description':
        case 'pre_description':
          $w->{$field}->value->set($data[$event_item]);
        break;
        case 'ticketurl':
          $ticket_urls = array();
          foreach($data[$event_item] as $key => $val) {
            $ticket_urls[] = $val;
          }
          if(!empty($ticket_urls)) {
            $w->{$field}->set($ticket_urls);
          }
          break;
        case 'type':
          if(isset($data['type']) && in_array($data['type'], array('huvitegevus','uritus')))
            $w->{$field}->set($data[$event_item]);
         else {
            return services_error('Invalid event type value. Event_id: ' . $data['id'], 406);
         }
         break;
         case 'active':
           $w->{$field}->set(!(bool)$data['active']);
          break;
        case 'city':
        case 'place':
        case 'toimumiskoht':
          break;
        case 'id':
          if (!empty($data[$event_item]))
            $w->{$field}->set($data[$event_item]);
          break;
        default:
          $w->{$field}->set($data[$event_item]);
          break;
      }
    }
  }
  if(isset($data['categories'])){
   $field_name = 'field_categories_event';
   if(isset($data['type']) && $data['type'] == 'huvitegevus') {
     $field_name = 'field_categories_activity';
   }
   $categories = array();
   foreach($data['categories'] as $category_id) {
        $categories[] = $category_id;
   }
   if(!empty($categories)) {
      $w->{$field_name}->set($categories);
   }
  }

  $w->save();
  return $w->getIdentifier();
}
function huvi_event_resource_event_to_node_fields() {
  $return = array(
    'id' => 'field_id',
    'name' => 'title',
    'excerpt' => 'field_excerpt',
    'description' => 'field_description',
    'active' =>	'field_unpublish',
    'korraldaja' => 'field_korraldaja',
    'images' => 'field_gallery',
    'hasimage' => 'field_hasimage',
    'image_url' => 'field_image_url',
    'video' => 'field_video_url',
    'pre_description' => 'field_pre_description',
    'map_latlng' => 'field_map_latlng',
    'map_markers' => 'field_map_markers',
    'type' => 'field_type',
    'ticketurl' => 'field_tickets',
    'schedule' => 'field_schedule',
    'isfree' => 'field_isfree',

  );
  return $return;
}

function huvi_event_resource_file_upload($filename, $url){
if (GetImageSize($url)) {
  $image = file_get_contents($url); // string
  $file = file_save_data($image, 'public://'.$filename,FILE_EXISTS_REPLACE);
  return $file;
}
else
  return FALSE;
}

/**
 * Get city_id
 *
 * @return array $return
 *
 */
function huvi_event_resource_get_city_id($city) {
  $cities = array(
    2944187 => "Haabersti",
    2944191 => "Kesklinn",
    2944189 => "Kristiine",
    2944190 => "Lasnamäe",
    2944193 => "Mustamäe",
    2944194 => "Nõmme",
    2920234 => "Pirita",
    2944195 => "Põhja-Tallinn"
  );
   return array_search($city, $cities);
}
