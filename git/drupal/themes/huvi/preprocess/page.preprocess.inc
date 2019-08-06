<?php

/**
 * Implements hook_preprocess_page().
 */
function huvi_preprocess_page(&$variables) {
  // Hide page title
  $variables['show_title'] = FALSE;


  $section = kuhuminna_utils_get_section();
  $front_url = url('<front>');

  if($section == 'events') {
    $front_url = url('events');

    $switcher_link_options = array(
      'attributes' => array(
        'class' => array(
          'activities-link', 'ribbon'
        ),
      )
    );
    $switcher_link = l('Vaata ka huvitegevusi', 'huvitegevused', $switcher_link_options);
  }

  if($section == 'activities') {
    $front_url = url('activities');

    $switcher_link_options = array(
      'attributes' => array(
        'class' => array(
          'events-link', 'ribbon'
        ),
      )
    );
    $switcher_link = l('Vaata ka üritusi', 'uritused', $switcher_link_options);

  }

  $variables['switcher_link'] = $switcher_link;
  $variables['front_url'] = $front_url;


  // Show only either 3 small banner views or 1 big banner view at random
  $ads_small = array(
    9, 10
  );
  $ads_big = array(
    7, 8
  );
  if (rand(0, 1)) {
    $ads_array = $ads_big;
  }
  else {
    $ads_array = $ads_small;
  }
  foreach($ads_array as $ad_id) {
    unset($variables['page']['highlighted']['views_advertisement-block_' . $ad_id]);
  }

  drupal_add_js(drupal_get_path('theme', 'huvi') . '/js/footer.js', array('scope' => 'footer'));
  
  if ((arg(0) == 'uritused' || arg(0) == 'huvitegevused')){
     drupal_add_css(drupal_get_path('theme', 'huvi') . '/libraries/daterangepicker/dist/daterangepicker.min.css');
     drupal_add_js(drupal_get_path('theme', 'huvi') . '/libraries/daterangepicker/moment.min.js');
     drupal_add_js(drupal_get_path('theme', 'huvi') . '/libraries/daterangepicker/dist/jquery.daterangepicker_huvi.min.js');
     drupal_add_js(drupal_get_path('theme', 'huvi') . '/js/daterangepicker.custom.languges.js');
 }
 drupal_add_js(array('geolocation_googlemaps' => array('geolocation_googlemaps_api_key' => variable_get('geolocation_googlemaps_api_key', ''))), array('type' => 'setting'));
}
