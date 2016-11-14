<?php
/**
 * @file
 * huvi_tallinn_settings.monolog.inc
 */

/**
 * Implements hook_default_monolog_profiles().
 */
function huvi_tallinn_settings_default_monolog_profiles() {
  $export = array();

  $profile = new stdClass();
  $profile->disabled = FALSE; /* Edit this to true to make a default profile disabled initially */
  $profile->api_version = 1;
  $profile->name = 'rotating_log';
  $profile->options = array(
    'handlers' => array(
      'rotating_file_handler_warning' => array(
        'weight' => '1',
        'label' => 'Rotating File Handler Warning',
        'level' => '300',
        'bubble' => '1',
        'filepath' => 'public://monolog/warning_log.log',
        'max_files' => '60',
        'handler' => 'rotating_file',
      ),
      'rotating_file_handler_notice' => array(
        'weight' => '1',
        'label' => 'Rotating File Handler Notice',
        'level' => '250',
        'bubble' => '1',
        'filepath' => 'public://monolog/notice_log.log',
        'max_files' => '60',
        'handler' => 'rotating_file',
      ),
    ),
    'label' => 'rotating log',
  );
  $export['rotating_log'] = $profile;

  return $export;
}
