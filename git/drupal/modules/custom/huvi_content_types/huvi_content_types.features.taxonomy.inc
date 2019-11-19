<?php

/**
 * @file
 * huvi_content_types.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function huvi_content_types_taxonomy_default_vocabularies() {
  return array(
    'toimumiskoht' => array(
      'name' => 'Toimumiskoht',
      'machine_name' => 'toimumiskoht',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'base_i18n_mode' => 0,
      'base_language' => 'und',
    ),
  );
}
