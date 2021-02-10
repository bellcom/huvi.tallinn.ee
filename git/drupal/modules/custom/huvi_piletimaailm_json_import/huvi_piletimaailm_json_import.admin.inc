<?php

/**
 * @file
 * Admin page.
 */

/**
 * Basic huvi_piletimaailm_json_import API settings form.
 */
function huvi_piletimaailm_json_import_settings_form($form, &$form_state) {

  $form['huvi_piletimaailm_json_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Piletimaailm JSON feeds URL'),
    '#default_value' => variable_get('huvi_piletimaailm_json_url', ''),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
