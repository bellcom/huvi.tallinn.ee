<?php

/**
 * @file
 * Kultuurikava Admin pages.
 */

/**
 * Basic Kultuurikava API settings form.
 */
function kultuurikava_settings_form($form, &$form_state) {

  $form['kultuurikava_api_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Kultuurikava API URL'),
    '#default_value' => variable_get('kultuurikava_api_url', ''),
    '#required' => TRUE,
  );

  $form['kultuurikava_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Kultuurikava API key'),
    '#default_value' => variable_get('kultuurikava_api_key', ''),
    '#required' => TRUE,
  );

  $form['kultuurikava_cron_import_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of events imported in one cron run. (Default is 50)'),
    '#default_value' => variable_get('kultuurikava_cron_import_number', 50),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive'),
  );

  $form['kultuurikava_import_next_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Next page to be imported. (If there are more items to be imported than the set number of events, this will be increased after every cron run. Set to 0 and uncheck next checkbox to re-import events.)'),
    '#default_value' => variable_get('kultuurikava_import_next_page', FALSE),
    '#element_validate' => array('element_validate_integer'),
  );

  $form['kultuurikava_import_first_done'] = array(
    '#type' => 'checkbox',
    '#title' => t('Only update events. (Will be automatically checked after first update is done. Uncheck, to re-impot everything. No deletion, only overwriting.)'),
    '#default_value' => variable_get('kultuurikava_import_first_done', FALSE),
  );

  return system_settings_form($form);
}


/**
 * Form for testing.
 *
 * @param array $form
 *   form
 * @param array $form_state
 *   form state
 *
 * @return array
 *   form
 */
function kultuurikava_test_form($form, &$form_state) {
  $form = array();

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Test'),
  );

  return $form;
}


/**
 * Test form submit handler.
 *
 * @param array $form
 *   form
 * @param array $form_state
 *   form state
 */
function kultuurikava_test_form_submit($form, &$form_state) {

  $parameters = array(
    'do' => 'events',
    //'start' => 1500,
    //'limit' => 500,
    'date' => date('Y-m-d'),
    'county' => 'tallinn',
    'order' => 'starta',
    'recreation' => '1',
  );



  // 14463
  // TMW Event ID: 3824305

  // OK Place ID 86549
  // NOK Tag ID: 2825871
  // Category ID: 14453

  $events = kultuurikava_api_call($parameters, NULL, 'nat');

  dsm($events);

}
