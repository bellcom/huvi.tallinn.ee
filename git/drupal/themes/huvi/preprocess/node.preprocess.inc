<?php

/**
 * Implements hook_preprocess_node().
 */
function huvi_preprocess_node(&$vars) {
  $node = $vars['node'];

  // Content type specific preprocessings.
  if ($node->type == 'advertisement') {
    huvi_preprocess_node_advertisement($vars);
  }
   if ($node->type == 'event'){
     drupal_add_js(drupal_get_path('theme', 'huvi') . '/js/huvi.subevents.filters.js');
     drupal_add_css(drupal_get_path('theme', 'huvi') . '/libraries/daterangepicker/dist/daterangepicker.min.css');
     drupal_add_js(drupal_get_path('theme', 'huvi') . '/libraries/daterangepicker/moment.min.js');
     drupal_add_js(drupal_get_path('theme', 'huvi') . '/libraries/daterangepicker/dist/jquery.daterangepicker_huvi.min.js');
     drupal_add_js(drupal_get_path('theme', 'huvi') . '/js/daterangepicker.custom.languges.js');
 }

}


/**
 * Advertisement node preprocessing.
 *
 * @param array &$vars
 *   variables to be preprocessed
 */
function huvi_preprocess_node_advertisement(&$vars) {
  $node = $vars['node'];

  // Banner preprocessing.
  if ($vars['view_mode'] == 'banner' || $vars['view_mode'] == 'banner_big') {
    $banner_classes = array('banner');

    // Link.
    $link = '';
    if (isset($node->field_adv_link[LANGUAGE_NONE]) && !empty($node->field_adv_link[LANGUAGE_NONE])) {
      $link_attributes = array();
      $link_attributes = $node->field_adv_link[LANGUAGE_NONE][0]['attributes'];
      $link_attributes['class'] = array('banner-link');

      $link = l('link', $node->field_adv_link[LANGUAGE_NONE][0]['url'], array('attributes' => $link_attributes));

    }

    // Default size.
    $size = 'large';
    if (isset($node->field_adv_size[LANGUAGE_NONE]) && !empty($node->field_adv_size[LANGUAGE_NONE])) {
      $size = $node->field_adv_size[LANGUAGE_NONE][0]['value'];
    }

    $banner_classes[] = $size . '-banner';
    $vars['link'] = $link;
    $vars['banner_classes'] = implode(' ', $banner_classes);

  }

}
