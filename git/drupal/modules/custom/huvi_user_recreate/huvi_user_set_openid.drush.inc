<?php

/**
 * Implementation of hook_drush_command().
 */
function huvi_user_set_openid_drush_command() {
  $items = array();
  $items['set_openid'] = array(
    'callback' => 'huvi_user_set_openid_set_openid', // Callback function
    'description' => 'Drush command to update authname and emal for the user.',
    'aliases' => array('openid'),
    'arguments' => array(
      'uid' => 'UserID',
      'openid' => 'OpenID',
    ),
    'examples' => array(
      'drush openid 254 38010101122' => 'Assign openid 38010101122 to user 254.',
    ),
  );
  return $items;
}

/**
 * Set new openid and email to the user.
 *
 * @param string $uid
 * @param string $openid
 */
function huvi_user_set_openid_set_openid(string $uid = NULL, string $openid = NULL) {

  if (is_null($uid) || is_null($openid)) {
    drush_print('No arguments. Example: drush openid 254 38010101122');
    die();
  }

  // Set new authname.
  $result = db_query('UPDATE {authmap} SET authname = :openid WHERE uid = :uid', array(':uid' => $uid, ':openid' => 'https://openid.ee/u/' . $openid));
  // Print information output.
  if ($result->rowCount()) {
    drush_print('Authname updated');
  }
  else {
    drush_print('Authname has not been updated');
  }

  // Set new email.
  $result = db_query('UPDATE {users} SET mail = :openid WHERE uid = :uid AND mail LIKE \'%@eesti.ee\'', array(':uid' => $uid, ':openid' => $openid . '@eesti.ee'));
  // Print information output.
  if ($result->rowCount()) {
    drush_print('Mail updated');
  }
  else {
    drush_print('Mail has not been updated');
  }

  // Set new init.
  $result = db_query('UPDATE {users} SET init = :openid WHERE uid = :uid ', array(':uid' => $uid, ':openid' => $openid . '@eesti.ee'));
  // Print information output.
  if ($result->rowCount()) {
    drush_print('Init updated');
  }
  else {
    drush_print('Init has not been updated');
  }
}
