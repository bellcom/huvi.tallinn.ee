<?php
/**
 * @file
 * huvi_tallinn_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function huvi_tallinn_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer facebook tracking pixels'.
  $permissions['administer facebook tracking pixels'] = array(
    'name' => 'administer facebook tracking pixels',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facebook_tracking_pixel',
  );

  return $permissions;
}
