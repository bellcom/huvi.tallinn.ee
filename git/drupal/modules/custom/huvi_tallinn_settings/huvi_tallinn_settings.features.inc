<?php
/**
 * @file
 * huvi_tallinn_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function huvi_tallinn_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
