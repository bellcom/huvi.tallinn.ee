<?php
/**
 * @file
 * huvi_event_resource.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function huvi_event_resource_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'event';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'rest';
  $endpoint->authentication = array(
    'services_basic_auth' => 'services_basic_auth',
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'bencode' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
      'xml' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/vnd.php.serialized' => FALSE,
      'application/x-www-form-urlencoded' => FALSE,
      'application/xml' => FALSE,
      'multipart/form-data' => FALSE,
      'text/xml' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'event' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['event'] = $endpoint;

  return $export;
}
