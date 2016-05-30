<?php

/**
 * Implements hook_preprocess_page().
 */
function huvi_preprocess_html(&$variables) {

  $section = kuhuminna_utils_get_section();

  if ($section == 'events') {
    $color_scheme_class = 'orange-scheme';
  }

  if ($section == 'activities') {
    $color_scheme_class = 'blue-scheme';
  }

  $variables['classes_array'][] = $color_scheme_class;
	
  drupal_add_css('http://fonts.googleapis.com/css?family=Open+Sans:300italic,400italic,700italic,400,700,300', array('type' => 'external'));
  drupal_add_css('http://fonts.googleapis.com/css?family=Roboto:400,400italic,700', array('type' => 'external'));
	
}
