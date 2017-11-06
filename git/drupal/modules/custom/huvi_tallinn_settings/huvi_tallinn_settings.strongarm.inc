<?php
/**
 * @file
 * huvi_tallinn_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function huvi_tallinn_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_tracking_pixel_aggregation';
  $strongarm->value = 1;
  $export['facebook_tracking_pixel_aggregation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_tracking_pixel_path';
  $strongarm->value = 'public://facebook_tracking_pixel';
  $export['facebook_tracking_pixel_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_tracking_pixel_roles_administrator';
  $strongarm->value = 1;
  $export['facebook_tracking_pixel_roles_administrator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_tracking_pixel_roles_anonymous_user';
  $strongarm->value = 0;
  $export['facebook_tracking_pixel_roles_anonymous_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_tracking_pixel_roles_authenticated_user';
  $strongarm->value = 0;
  $export['facebook_tracking_pixel_roles_authenticated_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_tracking_pixel_roles_manager';
  $strongarm->value = 0;
  $export['facebook_tracking_pixel_roles_manager'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_tracking_pixel_visibility_roles';
  $strongarm->value = '1';
  $export['facebook_tracking_pixel_visibility_roles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_abtext';
  $strongarm->value = '';
  $export['hide_submit_abtext'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_atext';
  $strongarm->value = '';
  $export['hide_submit_atext'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_hide_fx';
  $strongarm->value = 1;
  $export['hide_submit_hide_fx'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_hide_text';
  $strongarm->value = 'Processing...';
  $export['hide_submit_hide_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_indicator_style';
  $strongarm->value = 'zoom-in';
  $export['hide_submit_indicator_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_method';
  $strongarm->value = 'disable';
  $export['hide_submit_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_reset_time';
  $strongarm->value = '0';
  $export['hide_submit_reset_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_spinner_color';
  $strongarm->value = '#000';
  $export['hide_submit_spinner_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_spinner_lines';
  $strongarm->value = '12';
  $export['hide_submit_spinner_lines'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'monolog_channel_profiles';
  $strongarm->value = array(
    'watchdog' => 'rotating_log',
  );
  $export['monolog_channel_profiles'] = $strongarm;

  return $export;
}
