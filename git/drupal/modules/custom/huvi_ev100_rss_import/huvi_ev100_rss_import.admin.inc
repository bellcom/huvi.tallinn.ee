<?php

/**
 * @file
 * Kultuurikava Admin pages.
 */

/**
 * Basic huvi_ev100_rss_import API settings form.
 */
function huvi_ev100_rss_import_settings_form($form, &$form_state) {

  $form['huvi_ev100_rss_url'] = array(
    '#type' => 'textfield',
    '#title' => t('EV100 RSS feeds URL'),
    '#default_value' => variable_get('huvi_ev100_rss_url', ''),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}