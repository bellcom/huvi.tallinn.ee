<?php

/**
 * @file
 * Functions for Devel administrative pages.
 */

/**
 * Form constructor for the settings form.
 *
 * @ingroup forms
 */
function tara_admin_settings() {
  $form['tara_user_id'] = array(
    '#type' => 'textfield',
    '#title' => t('User id'),
    '#default_value' => variable_get('tara_user_id'),
    '#size' => 50,
    '#maxlength' => 50,
    '#required' => TRUE,
  );
  
    $form['tara_user_password'] = array(
    '#type' => 'textfield',
    '#title' => t('User password'),
    '#default_value' => variable_get('tara_user_password'),
    '#size' => 50,
    '#maxlength' => 50,
    '#required' => TRUE,
  );
    $form['tara_redirect_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect URL'),
    '#default_value' => variable_get('tara_redirect_url'),
    '#size' => 50,
    '#maxlength' => 50,
    '#required' => TRUE,
  );
    
  $form['tara_endpoint_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Tara endpoint token URL'),
    '#default_value' => variable_get('tara_endpoint_token'),
    '#size' => 50,
    '#maxlength' => 50,
    '#required' => TRUE,
  );
  
  $form['tara_endpoint_authorize'] = array(
    '#type' => 'textfield',
    '#title' => t('Tara endpoint authorize URL'),
    '#default_value' => variable_get('tara_endpoint_authorize'),
    '#size' => 50,
    '#maxlength' => 50,
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

