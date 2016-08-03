<?php
/**
 * @file
 * huvi_event_resource.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function huvi_event_resource_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}


