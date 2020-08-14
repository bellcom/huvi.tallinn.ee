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
    parent::getAccessToken();
    // Parent function returns only $token['access_token'].
    return $this->token;
  }
}
