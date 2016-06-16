<?php
/**
 * @file
 * event_listing_fixed_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function event_listing_fixed_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_only_date_with_year';
  $strongarm->value = 'd.m.y | l';
  $export['date_format_only_date_with_year'] = $strongarm;

  return $export;
}
