<?php
/**
 * @file
 * huvi_content_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function huvi_content_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_schedule_place'.
  $permissions['create field_schedule_place'] = array(
    'name' => 'create field_schedule_place',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_schedule_place'.
  $permissions['edit field_schedule_place'] = array(
    'name' => 'edit field_schedule_place',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_schedule_place'.
  $permissions['edit own field_schedule_place'] = array(
    'name' => 'edit own field_schedule_place',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_schedule_place'.
  $permissions['view field_schedule_place'] = array(
    'name' => 'view field_schedule_place',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_schedule_place'.
  $permissions['view own field_schedule_place'] = array(
    'name' => 'view own field_schedule_place',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
