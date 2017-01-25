<?php
/**
 * @file
 * huvi_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function huvi_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function huvi_content_types_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function huvi_content_types_image_default_styles() {
  $styles = array();

  // Exported image style: 900x200.
  $styles['900x200'] = array(
    'label' => '920x200',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 920,
          'height' => 200,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function huvi_content_types_node_info() {
  $items = array(
    'event' => array(
      'name' => t('üritus/huvitegevus'),
      'base' => 'node_content',
      'description' => t('Üritused ja huvitegevused sisestatud käsitsi või automaatselt imporditud Kultuurikava.ee lehelt.'),
      'has_title' => '1',
      'title_label' => t('Pealkiri'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
