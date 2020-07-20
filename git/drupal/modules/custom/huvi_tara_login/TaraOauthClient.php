<?php

namespace huvi_tara_login;

use OAuth2\Client;

class TaraOauthClient extends Client {

  /**
   * Get and return an access token.
   *
   * If there is an existing token (stored in session), return that one. But if
   * the existing token is expired, get a new one from the authorization server.
   *
   * If the refresh_token has also expired and the auth_flow is 'server-side', a
   * redirection to the oauth2 server will be made, in order to re-authenticate.
   * However the redirection will be skipped if the parameter $redirect is
   * FALSE, and NULL will be returned as access_token.
   */
  public function getAccessToken($redirect = TRUE) {
    // Check whether the existing token has expired.
    // We take the expiration time to be shorter by 10 sec
    // in order to account for any delays during the request.
    // Usually a token is valid for 1 hour, so making
    // the expiration time shorter by 10 sec is insignificant.
    // However it should be kept in mind during the tests,
    // where the expiration time is much shorter.
    $expiration_time = $this->token['expiration_time'];
    if ($expiration_time > (time() + 10)) {
      // The existing token can still be used.
      return $this->token;
    }

    try {
      // Try to use refresh_token.
      $token = $this->getTokenRefreshToken();
    }
    catch (\Exception $e) {
      // Get a token.
      switch ($this->params['auth_flow']) {
        case 'client-credentials':
          $token = $this->getToken(array(
            'grant_type' => 'client_credentials',
            'scope' => $this->params['scope'],
          ));
          break;

        case 'user-password':
          $token = $this->getToken(array(
            'grant_type' => 'password',
            'username' => $this->params['username'],
            'password' => $this->params['password'],
            'scope' => $this->params['scope'],
          ));
          break;

        case 'server-side':
          if ($redirect) {
            $token = $this->getTokenServerSide();
          }
          else {
            $this->clearToken();
            return NULL;
          }
          break;

        default:
          throw new \Exception(t('Unknown authorization flow "!auth_flow". Suported values for auth_flow are: client-credentials, user-password, server-side.',
              array('!auth_flow' => $this->params['auth_flow'])));
      }
    }
    $token['expiration_time'] = REQUEST_TIME + $token['expires_in'];

    // Store the token (on session as well).
    $this->token = $token;
    static::storeToken($this->id, $token);

    // Redirect to the original path (if this is a redirection
    // from the server-side flow).
    static::redirect();

    // Return the token.
    return $token;
  }

}
