<?php

/**
 * @file
 * Kultuurikava pages.
 */


/**
 * Single event.
 * 
 * @param int $event_id
 *   event id
 * 
 * @return array
 *   single event array
 */
function kultuurikava_event_detail($event_id) {

  $event_data = kultuurikava_get_event_data($event_id);
  if(isset($event_data) && !empty($event_data)) {
     $output = theme('kultuurikava_event_detail', array('event' => $event_data));
  }
  else {
    $output = t('No event found');
  }
  
  return $output;

}
