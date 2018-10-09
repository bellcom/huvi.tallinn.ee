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

  // Exported permission: 'create field_excerpt'.
  $permissions['create field_excerpt'] = array(
    'name' => 'create field_excerpt',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_hasimage'.
  $permissions['create field_hasimage'] = array(
    'name' => 'create field_hasimage',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_id'.
  $permissions['create field_id'] = array(
    'name' => 'create field_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_image_url'.
  $permissions['create field_image_url'] = array(
    'name' => 'create field_image_url',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_map_latlng'.
  $permissions['create field_map_latlng'] = array(
    'name' => 'create field_map_latlng',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_map_markers'.
  $permissions['create field_map_markers'] = array(
    'name' => 'create field_map_markers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pre_description'.
  $permissions['create field_pre_description'] = array(
    'name' => 'create field_pre_description',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'create field_source'.
  $permissions['create field_source'] = array(
    'name' => 'create field_source',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_video_url'.
  $permissions['create field_video_url'] = array(
    'name' => 'create field_video_url',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_excerpt'.
  $permissions['edit field_excerpt'] = array(
    'name' => 'edit field_excerpt',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_hasimage'.
  $permissions['edit field_hasimage'] = array(
    'name' => 'edit field_hasimage',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_id'.
  $permissions['edit field_id'] = array(
    'name' => 'edit field_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_image_url'.
  $permissions['edit field_image_url'] = array(
    'name' => 'edit field_image_url',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_map_latlng'.
  $permissions['edit field_map_latlng'] = array(
    'name' => 'edit field_map_latlng',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_map_markers'.
  $permissions['edit field_map_markers'] = array(
    'name' => 'edit field_map_markers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pre_description'.
  $permissions['edit field_pre_description'] = array(
    'name' => 'edit field_pre_description',
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

  // Exported permission: 'edit field_source'.
  $permissions['edit field_source'] = array(
    'name' => 'edit field_source',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_video_url'.
  $permissions['edit field_video_url'] = array(
    'name' => 'edit field_video_url',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_excerpt'.
  $permissions['edit own field_excerpt'] = array(
    'name' => 'edit own field_excerpt',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_hasimage'.
  $permissions['edit own field_hasimage'] = array(
    'name' => 'edit own field_hasimage',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_id'.
  $permissions['edit own field_id'] = array(
    'name' => 'edit own field_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_image_url'.
  $permissions['edit own field_image_url'] = array(
    'name' => 'edit own field_image_url',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_map_latlng'.
  $permissions['edit own field_map_latlng'] = array(
    'name' => 'edit own field_map_latlng',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_map_markers'.
  $permissions['edit own field_map_markers'] = array(
    'name' => 'edit own field_map_markers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pre_description'.
  $permissions['edit own field_pre_description'] = array(
    'name' => 'edit own field_pre_description',
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

  // Exported permission: 'edit own field_source'.
  $permissions['edit own field_source'] = array(
    'name' => 'edit own field_source',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_video_url'.
  $permissions['edit own field_video_url'] = array(
    'name' => 'edit own field_video_url',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_excerpt'.
  $permissions['view field_excerpt'] = array(
    'name' => 'view field_excerpt',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_hasimage'.
  $permissions['view field_hasimage'] = array(
    'name' => 'view field_hasimage',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_id'.
  $permissions['view field_id'] = array(
    'name' => 'view field_id',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_image_url'.
  $permissions['view field_image_url'] = array(
    'name' => 'view field_image_url',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_map_latlng'.
  $permissions['view field_map_latlng'] = array(
    'name' => 'view field_map_latlng',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_map_markers'.
  $permissions['view field_map_markers'] = array(
    'name' => 'view field_map_markers',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pre_description'.
  $permissions['view field_pre_description'] = array(
    'name' => 'view field_pre_description',
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

  // Exported permission: 'view field_source'.
  $permissions['view field_source'] = array(
    'name' => 'view field_source',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_video_url'.
  $permissions['view field_video_url'] = array(
    'name' => 'view field_video_url',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_excerpt'.
  $permissions['view own field_excerpt'] = array(
    'name' => 'view own field_excerpt',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_hasimage'.
  $permissions['view own field_hasimage'] = array(
    'name' => 'view own field_hasimage',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_id'.
  $permissions['view own field_id'] = array(
    'name' => 'view own field_id',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_image_url'.
  $permissions['view own field_image_url'] = array(
    'name' => 'view own field_image_url',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_map_latlng'.
  $permissions['view own field_map_latlng'] = array(
    'name' => 'view own field_map_latlng',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_map_markers'.
  $permissions['view own field_map_markers'] = array(
    'name' => 'view own field_map_markers',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pre_description'.
  $permissions['view own field_pre_description'] = array(
    'name' => 'view own field_pre_description',
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

  // Exported permission: 'view own field_source'.
  $permissions['view own field_source'] = array(
    'name' => 'view own field_source',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_video_url'.
  $permissions['view own field_video_url'] = array(
    'name' => 'view own field_video_url',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
