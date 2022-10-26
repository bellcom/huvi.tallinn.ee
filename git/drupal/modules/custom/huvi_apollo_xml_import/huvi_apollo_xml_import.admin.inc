<?php

/**
 * @file
 * Admin page.
 */

/**
 * Basic huvi_piletilevi_json_import API settings form.
 */
function huvi_apollo_xml_import_settings_form($form, &$form_state) {

  $form = array(
    'huvi_apollo_theatre_areas_xml_url' => array(
      '#type' => 'textfield',
      '#title' => t('Appolo Areas XML URL'),
      '#default_value' => variable_get('huvi_apollo_theatre_areas_xml_url', ''),
      '#required' => TRUE,
    ),
    'huvi_apollo_events_xml_url' => array(
      '#type' => 'textfield',
      '#title' => t('Apollo Events XML URL'),
      '#default_value' => variable_get('huvi_apollo_events_xml_url', ''),
      '#required' => TRUE,
    ),
    'huvi_apollo_schedule_dates_xml_url' => array(
      '#type' => 'textfield',
      '#title' => t('Apollo Schedule Dates XML URL'),
      '#default_value' => variable_get('huvi_apollo_schedule_dates_xml_url', ''),
      '#required' => TRUE,
    ),
    'huvi_apollo_schedule_xml_url' => array(
      '#type' => 'textfield',
      '#title' => t('Apollo Schedule XML URL'),
      '#default_value' => variable_get('huvi_apollo_schedule_xml_url', ''),
      '#required' => TRUE,
    ),
  );

  return system_settings_form($form);
}
