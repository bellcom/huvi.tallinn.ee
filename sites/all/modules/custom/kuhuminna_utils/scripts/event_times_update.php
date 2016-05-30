<?php

/**
 * Chenged event time from 00:00 to 23:59.
 */
$nids = db_select('node', 'n')
  ->fields('n', array('nid'))
  ->condition('n.type', 'event')
  ->execute()
  ->fetchCol();

foreach ($nids as $nid) {
  $node = node_load($nid);
//var_dump($node->nid);
  $items = field_get_items('node', $node, 'field_schedule');

  foreach ($items as $item) {

    // var_dump($node->field_schedule['und'][0]['value']);
    $field_collection = field_collection_field_get_entity($item);
     if (!is_object($field_collection->hostEntity()))       continue;
    if (is_array($field_collection->field_schedule_date['und'])) {
      foreach ($field_collection->field_schedule_date['und'] as $id => $value) {
        if (
          date('H:i', $field_collection->field_schedule_date['und'][$id]['value']) == '00:00' &&
          ($field_collection->field_schedule_date['und'][$id]['value'] == $field_collection->field_schedule_date['und'][$id]['value2'])) {
          $date = date_create();

          date_timestamp_set($date, $value['value']);
          $date->setTime(23, 55);
          $field_collection->field_schedule_date['und'][$id]['value'] = $date->getTimestamp();
          $field_collection->field_schedule_date['und'][$id]['value2'] = $date->getTimestamp();
          
        }
      }
    
     $field_collection->save();
    //var_dump($field_collection->hostEntity);
    }
     //
 
  }
}