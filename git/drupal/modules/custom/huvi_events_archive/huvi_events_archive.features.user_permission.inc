<?php

/**
 * @file
 * huvi_events_archive.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function huvi_events_archive_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access archived events'.
  $permissions['access archived events'] = array(
    'name' => 'access archived events',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'huvi_events_archive',
  );

  // Exported permission: 'edit_custom_pub_archive'.
  $permissions['edit_custom_pub_archive'] = array(
    'name' => 'edit_custom_pub_archive',
    'roles' => array(),
    'module' => 'custom_pub',
  );

  return $permissions;
}
