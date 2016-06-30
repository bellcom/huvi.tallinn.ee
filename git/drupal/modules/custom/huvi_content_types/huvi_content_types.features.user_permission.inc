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

  // Exported permission: 'create field_korraldaja_kontakttelefon'.
  $permissions['create field_korraldaja_kontakttelefon'] = array(
    'name' => 'create field_korraldaja_kontakttelefon',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'manager' => 'manager',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_korraldaja_nimi'.
  $permissions['create field_korraldaja_nimi'] = array(
    'name' => 'create field_korraldaja_nimi',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_schedule_place'.
  $permissions['create field_schedule_place'] = array(
    'name' => 'create field_schedule_place',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_korraldaja_kontakttelefon'.
  $permissions['edit field_korraldaja_kontakttelefon'] = array(
    'name' => 'edit field_korraldaja_kontakttelefon',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_korraldaja_nimi'.
  $permissions['edit field_korraldaja_nimi'] = array(
    'name' => 'edit field_korraldaja_nimi',
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

  // Exported permission: 'edit own field_korraldaja_kontakttelefon'.
  $permissions['edit own field_korraldaja_kontakttelefon'] = array(
    'name' => 'edit own field_korraldaja_kontakttelefon',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_korraldaja_nimi'.
  $permissions['edit own field_korraldaja_nimi'] = array(
    'name' => 'edit own field_korraldaja_nimi',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'view field_korraldaja_kontakttelefon'.
  $permissions['view field_korraldaja_kontakttelefon'] = array(
    'name' => 'view field_korraldaja_kontakttelefon',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_korraldaja_nimi'.
  $permissions['view field_korraldaja_nimi'] = array(
    'name' => 'view field_korraldaja_nimi',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'view own field_korraldaja_kontakttelefon'.
  $permissions['view own field_korraldaja_kontakttelefon'] = array(
    'name' => 'view own field_korraldaja_kontakttelefon',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_korraldaja_nimi'.
  $permissions['view own field_korraldaja_nimi'] = array(
    'name' => 'view own field_korraldaja_nimi',
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
