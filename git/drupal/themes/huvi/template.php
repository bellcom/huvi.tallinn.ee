<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * huvi theme.
 */

/**
 * Implements theme_omega_layout_alter().
 *
 * @param string $layout
 *   layout
 */
function huvi_omega_layout_alter(&$layout) {

  if ((arg(0) == 'uritus' || arg(0) == 'huvitegevus') && is_numeric(arg(1))) {
    $layout = 'single';
  }

  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $nid = arg(1);
    $node = node_load($nid);
    if (isset($node) && $node->type == 'event') {
      $layout = 'single';
    }
  }

  // Landing layout.
  if (arg(0) == 'landing') {
    $layout = 'landing';
  }
}

function huvi_views_pre_render(&$view) {
  if ($view->name == 'event_listing_fixed') {
     foreach($view->result as $r => $result) {
     if (date('H:i', $result->field_data_field_schedule_date_field_schedule_date_value) == '00:00')
       $all_day_events[] = $result; 
     else
        $rows[date('d.m.y', $result->field_data_field_schedule_date_field_schedule_date_value)][] = $result;         
    }
    foreach ($all_day_events as $date => $row) {
       $rows[date('d.m.y', $row->field_data_field_schedule_date_field_schedule_date_value)][] = $row;
    }
    
    $new_result = Array();
    
    foreach ($rows as $row) 
      foreach ($row as $result)
           $new_result[] = $result;   
    $view->result = $new_result;
  }
}
