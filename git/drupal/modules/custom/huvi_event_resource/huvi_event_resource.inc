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
  return (object) array(
      'status' => 'OK',
      'response' => $response_text,
  );
}

function huvi_event_resource_add_event($data) {
  global $user;
  $requered_fields = array('name', 'description', 'type');

  // Requered fields checking
  foreach ($requered_fields as $field_name)
    if (!isset($data[$field_name]) || empty($data[$field_name]))
      return services_error('Requered field ' . $field_name . ' is missing', 406);

  if (!isset($data['active']) || !in_array($data['active'], array(0, 1)))
    return services_error('Requered field active is missing', 406);
  // Check if the node exists already
  if (isset($data['id']) && !empty($data['id'])) {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'event')
      ->fieldCondition('field_id', 'value', $data['id'], '=')
      ->fieldCondition('field_source', 'value', 1, '=')
      ->execute();

    // Node exists, load the entity
    if ($result) {
      foreach ($result['node'] as $key => $val) {
        $entity_load = entity_load('node', array($key));
        foreach ($entity_load as $ekey => $eval) {
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
  } else {
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



  foreach ($fields as $event_item => $field) {
    if (isset($data[$event_item])) {
      switch ($event_item) {
        case 'images':
          $files = array();
          foreach ($data[$event_item] as $key => $val) {
            if ($file = huvi_event_resource_file_upload($val['filename'], $val['url'])) {
              $files[] = array('fid' => $file->fid);
            }
          }
          $w->{$field}->set($files);
          break;
        case 'schedule':
          if (!empty($entity->field_schedule['und'])) {
            $s_values = array();
            foreach ($entity->field_schedule['und'] as $s_key => $s_val) {
              $s_values[] = $s_val['value'];
              unset($entity->field_schedule['und'][$s_key]);
            }
            if (!empty($s_values)) {
              entity_delete_multiple('field_collection_item', $s_values);
            }
          }
          foreach ($data[$event_item] as $key => $val) {
            $schedule_item = entity_create('field_collection_item', array('field_name' => 'field_schedule'));
            $schedule_item->setHostEntity('entity', $entity);
            $schedule_wrapper = entity_metadata_wrapper('field_collection_item', $schedule_item);
            $timezone = "Europe/Tallinn";
            if (isset($val['start_time'])) {
              if (isset($val['timezone']))
                $timezone = $val['timezone'];
              $start_time = new DateTime($val['start_time'], new DateTimeZone($timezone));
              if (isset($val['end_time']))
                $end_time = new DateTime($val['end_time'], new DateTimeZone($timezone));

              $schedule_wrapper->field_schedule_date[0]->set(array(
                'value' => $start_time->format('U'),
                'value2' => isset($end_time) ? $end_time->format('U') : null,
                'rrule' => isset($val['rrule']) ? $val['rrule'] : ""
              ));
            }
            $city_area = isset($val['city_area']) ? $val['city_area'] : $data['city_area'];
            $place = isset($val['place']) ? $val['place'] : $data['place'];
            $toimumiskoht = isset($val['place']) ? $val['toimumiskoht'] : $data['toimumiskoht'];
            if (isset($city_area) && $city_id = huvi_event_resource_get_city_id($city_area))
              $schedule_wrapper->field_schedule_city_id->set($city_id);
            $schedule_wrapper->field_schedule_place->set($place);
            if (isset($toimumiskoht) && $toimumiskoht = taxonomy_get_term_by_name($toimumiskoht, 'toimumiskoht'))
              $schedule_wrapper->field_schedule_toimumis->set(key($toimumiskoht));
          }
          break;
        case 'korraldaja':
          if (!empty($entity->field_korraldaja['und'])) {
            $s_values = array();
            foreach ($entity->field_korraldaja['und'] as $s_key => $s_val) {
              $s_values[] = $s_val['value'];
              unset($entity->field_korraldaja['und'][$s_key]);
            }
            if (!empty($s_values)) {
              entity_delete_multiple('field_collection_item', $s_values);
            }
          }
          foreach ($data[$event_item] as $key => $val) {
            $korraldaja_item = entity_create('field_collection_item', array('field_name' => 'field_korraldaja'));
            $korraldaja_item->setHostEntity('entity', $entity);
            $korraldaja_wrapper = entity_metadata_wrapper('field_collection_item', $korraldaja_item);

            if (isset($val['name']))
              $korraldaja_wrapper->field_korraldaja_nimi->set($val['name']);
            if (isset($val['phone']))
              $korraldaja_wrapper->field_korraldaja_kontakttelefon->set($val['phone']);
            if (isset($val['email']))
              $korraldaja_wrapper->field_korraldaja_e_post->set($val['email']);
          }
          break;
        case 'description':
        case 'pre_description':
          $w->{$field}->value->set($data[$event_item]);
          break;
        case 'ticketurl':
          $ticket_urls = array();
          foreach ($data[$event_item] as $key => $val) {
            $ticket_urls[] = $val;
          }
          if (!empty($ticket_urls)) {
            $w->{$field}->set($ticket_urls);
          }
          break;
        case 'type':
          if (isset($data['type']) && in_array($data['type'], array('huvitegevus', 'uritus')))
            $w->{$field}->set($data[$event_item]);
          else {
            return services_error('Invalid event type value. Event_id: ' . $data['id'], 406);
          }
          break;
        case 'active':
          $w->{$field}->set(!(bool) $data['active']);
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
  if (isset($data['categories'])) {
    $field_name = 'field_categories_event';
    if (isset($data['type']) && $data['type'] == 'huvitegevus') {
      $field_name = 'field_categories_activity';
    }
    $categories = array();
    foreach ($data['categories'] as $category_id) {
      $categories[] = $category_id;
    }
    if (!empty($categories)) {
      $w->{$field_name}->set($categories);
    }
  }
  $w->field_source->set(1); //1 - rest_service
  $w->save();
  return $w->getIdentifier();
}

function huvi_event_resource_event_to_node_fields() {
  $return = array(
    'id' => 'field_id',
    'name' => 'title',
    'excerpt' => 'field_excerpt',
    'description' => 'field_description',
    'active' => 'field_unpublish',
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

function huvi_event_resource_file_upload($filename, $url) {
  if (GetImageSize($url)) {
    $image = file_get_contents($url); // string
    $file = file_save_data($image, 'public://' . $filename, FILE_EXISTS_REPLACE);
    return $file;
  } else
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

/**
 * Get city_id
 *
 * @return array $city
 *
 */
function huvi_event_resource_get_city_by_id($city_id) {
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
  return $cities[$city_id];
}

/**
 * Get activity category by id;
 * $event_type: uritus or huvitegevus
 *
 * @return string $category
 *
 */
function huvi_event_resource_category_by_id($id, $event_type) {
  $categories = array(
    'huvitegevus' => array(
      0 => 'Muusika',
      1 => 'Kunst, käsitöö',
      2 => 'Tantsimine',
      3 => 'Sport, liikumine',
      4 => 'Tehnika',
      5 => 'Keeleõpe',
      6 => 'Koolitused, kursused',
      7 => 'Lapsele',
      8 => 'Varia'
    ),
    'uritus' => array(
      0 => 'Muusika',
      1 => 'Etendused',
      2 => 'Näitus, muuseum',
      3 => 'Mess, laat',
      4 => 'Sport',
      5 => 'Kino',
      6 => 'Pidu, klubid',
      7 => 'Lapsele',
      8 => 'Varia'
    )
  );
  return $categories[$event_type][$id];
}

function _eventresource_index($parameters) {
  $events = array();
  $query_result = huvi_event_resource_get_events($parameters);

  foreach ($query_result as $key => $node) {
    $node_event = node_load($node->nid);
    $event = huvi_event_resource_node_to_event($node_event);
    $events[]['event'] = $event;
  }

  return array('events' => $events);
}

function huvi_event_resource_get_events($parameters) {
  $query = db_select('node', 'n')
    ->distinct()
    ->fields('n', array('nid'));
  $query->innerJoin('field_data_field_schedule', 's', 'n.nid = s.entity_id');

  if (isset($parameters['type'])) {
    $query->innerJoin('field_data_field_type', 't', 'n.nid = t.entity_id');
    $query->condition('t.field_type_value', $parameters['type'], 'IN');
  }
  if (isset($parameters['is_free']) && array_pop($parameters['is_free']) == 1) {
    $query->innerJoin('field_data_field_isfree', 'f', 'n.nid = f.entity_id');
    $query->condition('f.field_isfree_value', 1);
  }
  if (isset($parameters['event_category']) && isset($parameters['activity_category'])) {
    $query->leftJoin('field_data_field_categories_event', 'ev_cat', 'n.nid = ev_cat.entity_id');
    $query->leftJoin('field_data_field_categories_activity', 'ac_cat', 'n.nid = ac_cat.entity_id');
    $or = db_or();
    $or->condition('ev_cat.field_categories_event_value', $parameters['event_category'], 'IN');
    $or->condition('ac_cat.field_categories_activity_value', $parameters['activity_category'], 'IN');
    $query->condition($or);
  } else if (isset($parameters['event_category'])) {
    $query->leftJoin('field_data_field_categories_event', 'ev_cat', 'n.nid = ev_cat.entity_id');
    $query->condition('ev_cat.field_categories_event_value', $parameters['event_category'], 'IN');
  } else if (isset($parameters['activity_category'])) {
    $query->leftJoin('field_data_field_categories_activity', 'ac_cat', 'n.nid = ac_cat.entity_id');
    $query->condition('ac_cat.field_categories_activity_value', $parameters['activity_category'], 'IN');
  }
  if (isset($parameters['keywords'])) {
    $query->innerJoin('field_data_field_description', 'd', 'n.nid = d.entity_id');
    $query->where("LOWER(CONCAT_WS(d.field_description_value, ' ', n.title)) LIKE :q", array(':q' => '%' . strtolower(array_pop($parameters['keywords'])) . '%'));
  }

  $field_schedule_keys = array();
  $entity_query = new EntityFieldQuery();
  $entity_query->entityCondition('entity_type', 'field_collection_item')
    ->fieldCondition('field_schedule_date', 'value', time(), '>=');
  if (isset($parameters['linnaosa'])){
    $entity_query->fieldCondition('field_schedule_city_id', 'value', $parameters['linnaosa'], 'IN');
  }
  $entity_query_result = $entity_query->execute();
  if (!empty($entity_query_result['field_collection_item'])) {
    $field_schedule_keys = array_keys($entity_query_result['field_collection_item']);
  }


  $query->condition('field_schedule_value', $field_schedule_keys, 'IN');
  $query->condition('n.type', 'event')
    ->condition('n.status', 1);
  $result = $query->execute()->fetchAll();
  return $result;
}

/**
 * Convert node to proper event fields displayed on the event node template page
 *
 * @param object $node
 *   Event node to be converted to the event array
 *
 * @return array $e
 *   Event data for showing in the event template on the node page
 */
function huvi_event_resource_node_to_event($node) {
  $n = $node;
  $e = array();
  $fields = huvi_event_resource_event_to_node_fields();


  foreach ($fields as $event => $field) {
    switch ($event) {
      case 'name':
        $e[$event] = $n->{$field};
        break;

      case 'korraldaja'://Korraldaja fields
        if (isset($n->{$field}['und'])) {
          foreach ($n->{$field}['und'] as $key => $val) {
            if (isset($val['value'])) {
              $collections = entity_load('field_collection_item', array($val['value']));

              foreach ($collections as $c) {
                //get korraldaja name
                if (isset($c->field_korraldaja_nimi['und'])) {
                  foreach ($c->field_korraldaja_nimi['und'] as $korraldaja_key => $nimi) {
                    if (isset($nimi['value'])) {
                      $korraldaja_nimi = $nimi['value'];
                      $e[$event][$event_key]["name"] = $korraldaja_nimi;
                    }
                  }
                }
                //get korraldaja phone
                if (isset($c->field_korraldaja_kontakttelefon['und'])) {
                  foreach ($c->field_korraldaja_kontakttelefon['und'] as $korraldaja_key => $kontakttelefon) {
                    if (isset($kontakttelefon['value'])) {
                      $korraldaja_kontakttelefon = $kontakttelefon['value'];
                      $e[$event][$event_key]["phone"] = $korraldaja_kontakttelefon;
                    }
                  }
                }
                //get korraldaja epost
                if (isset($c->field_korraldaja_e_post['und'])) {
                  foreach ($c->field_korraldaja_e_post['und'] as $korraldaja_key => $e_post) {
                    if (isset($e_post['email'])) {
                      $korraldaja_e_post = $e_post['email'];
                      $e[$event][$event_key]["email"] = $korraldaja_e_post;
                    }
                  }
                }
              }
            }
          }
        }
        break;

      case 'schedule':
        if (isset($n->{$field}['und'])) {
          $date_format = 'd.m.Y H:i';
          $short_date_format = 'd.m.Y';
          foreach ($n->{$field}['und'] as $key => $val) {
            if (isset($val['value'])) {
              $collections = entity_load('field_collection_item', array($val['value']));
              foreach ($collections as $key => $c) {
                if (isset($c->field_schedule_date['und'])) {
                  $date = array_shift($c->field_schedule_date['und']);
                  $start_date = $date['value'];
                  if (isset($date['value2'])) {
                    $end_date = $date['value2'];
                  }
                  $e[$event][$key] = array();
                  if (date('H:i', $start_date) == '23:55')
                    $e[$event][$key]['start_time'] = format_date($start_date, 'custom', $short_date_format);
                  else
                    $e[$event][$key]['start_time'] = format_date($start_date, 'custom', $date_format);

                  if (isset($end_date) && $start_date != $end_date) {
                    $e[$event][$key]['end_time'] = format_date($end_date, 'custom', $date_format);
                  }
                  if ($date['rrule'])
                    $e[$event][$key]['rrule'] = $date['rrule'];
                  if ($date['timezone'])
                    $e[$event][$key]['timezone'] = $date['timezone'];
                  $city_area = huvi_event_resource_get_city_by_id($c->field_schedule_city_id['und'][0]['value']);
                  // var_dump($city_area);
                  if (isset($city_area))
                    $e[$event][$key]['city_area'] = $city_area;
                  $toimumiskoht = $c->field_schedule_toimumis['und'][0]['taxonomy_term']->name;
                  if (!empty($toimumiskoht)) {
                    $e[$event][$key]['place'] = $toimumiskoht;
                  }
                }
              }
            }
          }
        }
        break;
      case 'ticketurl':
        if (isset($n->{$field}['und'])) {
          foreach ($n->{$field}['und'] as $key => $url) {
            $url_parse = parse_url($url['value']);
            if (!isset($url_parse['host'])) {
              $url_parse = explode('/', $url_parse['path']);
              $url_host = $url_parse[0];
              $url['value'] = 'http://' . $url['value'];
            } else {
              $url_host = $url_parse['host'];
            }
            if (substr($url_host, 0, strlen('www.')) == 'www.') {
              $url_host = substr($url_host, strlen('www.'));
            }
            $e[$event][$key] = $url['value'];
          }
        }
        break;
      case 'images':
        if (isset($n->{$field}['und']))
          foreach ($n->{$field}['und'] as $val)
            $e['images'][] = file_create_url($val['uri']);
        break;
      case 'active':
        if (isset($n->{$field}['und'])) {
          if (isset($n->{$field}['und'][0]['value'])) {
            $e[$event] = !(bool) $n->{$field}['und'][0]['value'];
          }
        }
        break;

      default:
        if (isset($n->{$field}['und'])) {
          if (isset($n->{$field}['und'][0]['value'])) {
            $e[$event] = $n->{$field}['und'][0]['value'];
          }
        }
        break;
    }
  }
  if (isset($n->field_categories_activity['und']))
    foreach ($n->field_categories_activity['und'] as $val)
      $e['categories'][] = $val['value'];

  if (isset($n->field_categories_event['und']))
    foreach ($n->field_categories_event['und'] as $val) {
      $e['categories'][] = huvi_event_resource_category_by_id($val['value'], $n->field_type['und'][0]['value']);
    }
  $e['url'] = url('node/'. $n->nid ,  array('absolute' => TRUE));
  return $e;
}
