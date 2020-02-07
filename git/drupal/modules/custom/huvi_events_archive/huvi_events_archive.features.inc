<?php

/**
 * @file
 * huvi_events_archive.features.inc
 */

/**
 * Implements hook_views_api().
 */
function huvi_events_archive_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_custom_pub_defaults().
 */
function huvi_events_archive_custom_pub_defaults() {
  $options = array();
  // Exported option: archive
  $options['archive'] = array(
    'type' => 'archive',
    'name' => t('Archive'),
    'node_types' => array(
      'event' => t('üritus/huvitegevus'),
    ),
  );

  return $options;
}
