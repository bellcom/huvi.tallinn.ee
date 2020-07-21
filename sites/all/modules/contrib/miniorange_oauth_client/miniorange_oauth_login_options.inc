<?php
/**
 * @file
 * Contains Login Settings for miniOrange OAuth Login Module.
 */

 /**
 * Showing Settings form.
 */
 function miniorange_oauth_login_options($form, &$form_state) {
     global $base_url;
     drupal_add_css( drupal_get_path('module', 'miniorange_oauth_client'). '/css/bootstrap.min.css' , array('group' => CSS_DEFAULT, 'every_page' => FALSE));
     drupal_add_css( drupal_get_path('module', 'miniorange_oauth_client'). '/css/style_settings.css' , array('group' => CSS_DEFAULT, 'every_page' => FALSE));
     drupal_add_js(drupal_get_path('module', 'miniorange_oauth_client') . '/js/slide_support_button.js');
    $baseUrlValue = variable_get('miniorange_oauth_client_base_url');

    $form['header_top_style_1'] = array('#markup' => '<div class="mo_oauth_table_layout_1">');

    $form['markup_top'] = array(
         '#markup' => '<div class="mo_oauth_table_layout mo_oauth_container">',
    );

    $form['markup_top_vt_start'] = array(
         '#markup' => '<b><span style="font-size: 17px;">Sign in Settings</span></b><br><br><hr><br/>'
     );

     $prefixname = '<div class="mo_oauth_row"><div class="mo_oauth_name">';
     $suffixname = '</div>';

     $prefixvalue = '<div class="mo_oauth_value">';
     $suffixvalue = '</div></div>';
     $module_path = drupal_get_path('module', 'miniorange_oauth_client');

     $form['miniorange_oauth_client_base_url_title'] = array(
         '#markup' => '<b>Base URL:</b> <div class="mo_oauth_tooltip"><img src="'.$base_url.'/'. $module_path . '/includes/images/info.png" alt="info icon" height="15px" width="15px"></div><div class="mo_oauth_tooltiptext"><b>Note: </b>You can customize base URL here. (For eg: https://www.xyz.com or http://localhost/abc)</div> ',
         '#prefix' => $prefixname,
         '#suffix' => $suffixname,
     );

     $form['miniorange_oauth_client_base_url'] = array(
         '#type' => 'textfield',
         '#default_value' => $baseUrlValue,
         '#attributes' => array('id'=>'mo_oauth_vt_baseurl','style' => 'width:73%;','placeholder' => 'Enter Base URL'),
         '#prefix' => $prefixvalue,
         '#suffix' => $suffixvalue,
     );

     $form['miniorange_oauth_client_siginin'] = array(
        '#type' => 'submit',
        '#id' => 'button_config_center',
        '#value' => t('Update'),
        '#submit' => array('miniorange_oauth_save_signin_settings'),
        '#suffix' => '<hr><br>',
    );

    $form['miniorange_oauth_force_auth'] = array(
        '#type' => 'checkbox',
        '#title' => t('Protect website against anonymous access <a href="' . $base_url . '/admin/config/people/miniorange_oauth_client/licensing"><b>[Premium, Enterprise]</b></a>'),
        '#disabled' => TRUE,
        '#description' => t('<b>Note: </b>Users will be redirected to your Oauth Server for login in case user is not logged in and tries to access website.<br><br>'),
    );
    $form['miniorange_oauth_auto_redirect'] = array(
        '#type' => 'checkbox',
        '#title' => t('Check this option if you want to <b> Auto-redirect to OAuth Provider/Server </b><a href="' . $base_url . '/admin/config/people/miniorange_oauth_client/licensing"><b>[Premium, Enterprise]</b></a>'),
        '#disabled' => TRUE,
        '#description' => t('<b>Note: </b>Users will be redirected to your Oauth Server for login when the login page is accessed.<br><br>'),
    );
    $form['miniorange_oauth_enable_backdoor'] = array(
        '#type' => 'checkbox',
        '#title' => t('Check this option if you want to enable <b>backdoor login </b><a href="' . $base_url . '/admin/config/people/miniorange_oauth_client/licensing"><b>[Premium, Enterprise]</b></a>'),
        '#disabled' => TRUE,
        '#description' => t('<b>Note</b>: Checking this option creates a backdoor to login to your Website using Drupal credentials<br> incase you get locked out of your Oauth Server.
                <br><b>Note down this URL: </b>Available in <a href="' . $base_url . '/admin/config/people/miniorange_oauth_client/licensing"><b>Premium, Enterprise</b></a> versions of the module.<br><br><br><br>'),
    );
         $form['markup_auto-create_users_vt_start'] = array(
         '#markup' => '<b><span style="font-size: 17px;">Auto Create Users</span></b><br><hr><p>This feature provides you with an option to automatically create a user if the user is not already present in Drupal</p>'
     );
    $form['miniorange_oauth_disable_autocreate_users'] = array(
            '#type' => 'checkbox',
            '#title' => t('Check this option if you want to disable <b>auto creation</b> of users if user does not exist.<a href="' . $base_url . '/admin/config/people/miniorange_oauth_client/licensing"><b>[Standard, Premium, Enterprise]</b></a>'),
	        '#disabled' => TRUE,
        );

     $form['markup_bottom_vt_start'] = array(
         '#markup' => '<br><br><br><b><span style="font-size: 17px;">Domain & Page Restriction</span></b><br><hr><br/>'
     );

     $form['miniorange_oauth_client_white_list_url_title'] = array(
         '#markup' => '<b>Allowed Domains</b><a href="' . $base_url . '/admin/config/people/miniorange_oauth_client/licensing"><b>[Enterprise]</b></a>  <div class="mo_oauth_tooltip"><img src="'.$base_url.'/'. $module_path . '/includes/images/info.png" alt="info icon" height="15px" width="15px"></div><div class="mo_oauth_tooltiptext"><b>Note: </b> Enter <b>semicolon(;) separated</b> domains to allow SSO. Other than these domains will not be allowed to do SSO</div>',
         '#prefix' => $prefixname,
         '#suffix' => $suffixname,
     );

     $form['miniorange_oauth_client_white_list_url'] = array(
         '#type' => 'textfield',
         '#attributes' => array('style' => 'width:73%','placeholder' => 'Enter semicolon(;) separated domains (Eg. xxxx.com; xxxx.com)'),
         '#disabled' => TRUE,
         '#prefix' => $prefixvalue,
         '#suffix' => $suffixvalue,
     );

     $form['miniorange_oauth_client_black_list_url_title'] = array(
         '#markup' => '<b>Restricted Domains</b> <a href="' . $base_url . '/admin/config/people/miniorange_oauth_client/licensing"><b>[Enterprise]</b></a>  <div class="mo_oauth_tooltip"><img src="'.$base_url.'/'. $module_path . '/includes/images/info.png" alt="info icon" height="15px" width="15px"></div><div class="mo_oauth_tooltiptext"><b>Note: </b> Enter <b>semicolon(;) separated</b> domains to allow SSO. Other than these domains will not be allowed to do SSO</div>',
         '#prefix' => $prefixname,
         '#suffix' => $suffixname,
     );

     $form['miniorange_oauth_client_black_list_url'] = array(
         '#type' => 'textfield',
         '#attributes' => array('style' => 'width:73%','placeholder' => 'Enter semicolon(;) separated domains (Eg. xxxx.com; xxxx.com)'),
         '#disabled' => TRUE,
         '#prefix' => $prefixvalue,
         '#suffix' => $suffixvalue,
     );

     $form['miniorange_oauth_client_page_restrict_url_title'] = array(
         '#markup' => '<b>Page Restriction</b><a href="' . $base_url . '/admin/config/people/miniorange_oauth_client/licensing"><b>[Enterprise]</b></a>  <div class="mo_oauth_tooltip"><img src="'.$base_url.'/'. $module_path . '/includes/images/info.png" alt="info icon" height="15px" width="15px"></div><div class="mo_oauth_tooltiptext"><b>Note: </b> Enter <b>semicolon(;) separated</b> URLs to restrict unauthorized access</div>',
         '#prefix' => $prefixname,
         '#suffix' => $suffixname,
     );

     $form['miniorange_oauth_client_page_restrict_url'] = array(
         '#type' => 'textfield',
         '#attributes' => array('style' => 'width:73%','placeholder' => 'Enter semicolon(;) separated page URLs (Eg. xxxx.com/yyy; xxxx.com/yyy)'),
         '#disabled' => TRUE,
         '#prefix' => $prefixvalue,
         '#suffix' => $suffixvalue,
     );

     $form['miniorange_oauth_client_siginin1'] = array(
            '#type' => 'button',
            '#disabled' => TRUE,
            '#value' => t('Save Configuration'),
        );
    $form['mo_header_style_end'] = array('#markup' => '</div>');
     Utilities::nofeaturelisted($form, $form_state);
     $form['mo_markup_div_imp']=array('#markup'=>'</div>');
     Utilities::AddSupportButton($form, $form_state);
     return $form;
 }
/**
 * Send support query.
 */
function send_support_query(&$form, $form_state)
{
    $email = trim($form['miniorange_oauth_email_address_support']['#value']);
    $phone = $form['miniorange_oauth_phone_number_support']['#value'];
    $query = trim($form['miniorange_oauth_support_query_support']['#value']);
    Utilities::send_query($email, $phone, $query);
}
function rfd(&$form, $form_state) {

    global $base_url;
    drupal_goto($base_url.'/admin/config/people/miniorange_oauth_client/request_for_demo');
}
/**
 * This function saves the values in the Sign in Settings tab.
 */
function miniorange_oauth_save_signin_settings($form, &$form_state) {
    $baseUrlvalue = trim($form['miniorange_oauth_client_base_url']['#value']);
    if(!empty($baseUrlvalue) && filter_var($baseUrlvalue, FILTER_VALIDATE_URL) == FALSE) {
        drupal_set_message(t('Please enter a valid URL'),'error');
        return;
    }
    variable_set('miniorange_oauth_client_base_url', $baseUrlvalue);
    drupal_set_message(t('Signin Settings successfully saved'));
}
