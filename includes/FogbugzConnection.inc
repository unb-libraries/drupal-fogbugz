<?php

/**
 * @file
 * Base connection object for calls to the the fogbugz API.
 */

/**
 * The main FogbugzConnection object.
 */
class FogbugzConnection {

  /**
   * The connection token.
   *
   * @var string
   */
  private $connectionToken = NULL;

  /**
   * Constructor.
   */
  public function __construct() {
    $this->setConnectionToken();
  }

  /**
   * Get a token from the API, needed for calls.
   */
  private function setConnectionToken() {
    $fogbugz_api_response = curl_post_data(
      variable_get('fogbugz_protocol') .
      '://' .
      variable_get('fogbugz_hostname') .
      ':' .
      variable_get('fogbugz_port') .
      '/api.asp?cmd=logon',
      array(
        'email' => variable_get('fogbugz_user_email'),
        'password' => variable_get('fogbugz_user_password'),
      )
    );

    if ($fogbugz_api_response) {
      $xml = simplexml_load_string($fogbugz_api_response, 'SimpleXMLElement', LIBXML_NOCDATA);
      $this->connectionToken = (string) $xml->token;
    }
    else {
      drupal_set_message(t('Connection to FogBugz failed. Please contact the site administrator.'), 'error');
    }
  }

  /**
   * Post data to the API.
   */
  public function post($post_data) {
    $post_data['token'] = $this->connectionToken;
    return curl_post_data(
      variable_get('fogbugz_protocol') .
      '://' .
      variable_get('fogbugz_hostname') .
      ':' .
      variable_get('fogbugz_port') .
      '/api.asp?cmd=new',
      $post_data
    );
  }

}

/**
 * Curl data post helper.
 */
function curl_post_data($uri, $post_data) {
  $curl_handle = curl_init($uri);
  curl_setopt($curl_handle, CURLOPT_RETURNTRANSFER, TRUE);
  curl_setopt($curl_handle, CURLOPT_POST, TRUE);
  curl_setopt($curl_handle, CURLOPT_POSTFIELDS, $post_data);
  return curl_exec($curl_handle);
}
