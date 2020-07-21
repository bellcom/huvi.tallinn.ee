<?php

include_once drupal_get_path('module', 'openid_connect') . '/includes/OpenIDConnectClientBase.class.php';

/**
 * @file
 * Generic OpenID Connect client.
 *
 * Used primarily to login to Drupal sites powered by oauth2_server or PHP
 * sites powered by oauth2-server-php.
 */
class OpenIDConnectClientTara extends OpenIDConnectClientBase {

  /**
   * The human-readable name of the client plugin.
   *
   * @var string
   */
  protected $state;

  public function __construct($name, $label, array $settings) {
    $form = parent::__construct($name, $label, $settings);
    $this->state = $this->_generateState();
  }

  protected function _generateState($length = 16) {

    $str = '';
    for ($i = 0; $i < $length; $i++) {
      $str .= chr(mt_rand(32, 126));
    }
    return $str;
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm() {
    global $base_url;
    $form = parent::settingsForm();

    $form['client_secret']['#type'] = 'textfield';

    $form['token_endpoint'] = array(
      '#title' => t('Token endpoint'),
      '#type' => 'textfield',
      '#default_value' => $this->getSetting('token_endpoint'),
    );

    $form['authorization_endpoint'] = array(
      '#title' => t('Authorization endpoint'),
      '#type' => 'textfield',
      '#default_value' => $this->getSetting('authorization_endpoint'),
    );

    $form['redirect_url'] = array(
      '#title' => t('Redirect URL'),
      '#type' => 'textfield',
      '#description' => t("Relative to @base_url", array('@base_url' => $base_url)),
      '#default_value' => $this->getSetting('redirect_url'),
    );

    $form['scope'] = array(
      '#title' => t('Scope'),
      '#type' => 'textfield',
      '#default_value' => 'openid',
      '#description' => t("Use: @scope", array('@scope' => 'openid')),
      '#default_value' => $this->getSetting('scope'),
    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function getEndpoints() {
    return array(
      'authorization' => $this->getSetting('authorization_endpoint'),
      'token' => $this->getSetting('token_endpoint'),
      'redirect_url' => $this->getSetting('redirect_url'),
      'scope' => $this->getSetting('scope'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function authorize($scope = 'openid') {
    global $base_url;
    $post_data = array(
      'scope' => $this->getSetting('scope'),
      'response_type' => 'code',
      'client_id' => $this->getSetting('client_id'),
      'redirect_uri' => $base_url . $this->getSetting('redirect_url'),
      'state' => base64_encode(hash('sha256', $this->state)),
    );



//    $client_id = $this->params['client_id'];
//    $client_secret = $this->params['client_secret'];
//    $token_endpoint = $this->params['token_endpoint'];
//
    $options = array(
      'method' => 'POST',
      'data' => drupal_http_build_query($post_data),
      'headers' => array(
        'Content-Type' => 'application/x-www-form-urlencoded',
        'Authorization' => 'Basic ' . base64_encode("$this->getSetting('client_id'):$this->getSetting('client_secret')"),
      ),
    );

    $result = drupal_http_request($this->getSetting('authorization_endpoint'), $options);

    print_r('<pre>');
    print_r($result);
    print_r('/<pre>');
    die();

//
//    if ($result->code != 200) {
//      throw new \Exception(
//        t("Failed to get an access token of grant_type @grant_type.\nError: @result_error",
//          array(
//            '@grant_type' => $data['grant_type'],
//            '@result_error' => $result->error,
//        ))
//      );
//    }
//
//    $token = drupal_json_decode($result->data);
//
//    if (!isset($token['expires_in'])) {
//      $token['expires_in'] = 3600;
//    }
//
//    return $token;
  }

}

//$redirect_uri = OPENID_CONNECT_REDIRECT_PATH_BASE . '/' . $this->name;
//$post_data = array(
//  'code' => $authorization_code,
//  'client_id' => $this->getSetting('client_id'),
//  'client_secret' => $this->getSetting('client_secret'),
//  'redirect_uri' => url($redirect_uri, array('absolute' => TRUE)),
//  'grant_type' => 'authorization_code',
//);
//$request_options = array(
//  'method' => 'POST',
//  'data' => drupal_http_build_query($post_data),
//  'timeout' => 15,
//  'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
//);
//$endpoints = $this->getEndpoints();
//$response = drupal_http_request($endpoints['token'], $request_options);
//if (!isset($response->error) && $response->code == 200) {
//  $response_data = drupal_json_decode($response->data);
//  $tokens = array(
//    'id_token' => $response_data['id_token'],
//    'access_token' => $response_data['access_token'],
//  );
//  if (array_key_exists('expires_in', $response_data)) {
//    $tokens['expire'] = REQUEST_TIME + $response_data['expires_in'];
//  }
//  if (array_key_exists('refresh_token', $response_data)) {
//    $tokens['refresh_token'] = $response_data['refresh_token'];
//  }
//  return $tokens;
//}
//else {
//  openid_connect_log_request_error(__FUNCTION__, $this->name, $response);
//  return FALSE;
//}