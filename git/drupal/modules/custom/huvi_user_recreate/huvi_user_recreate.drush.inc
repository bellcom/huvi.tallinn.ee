<?php

/**
 * Implementation of hook_drush_command().
 */
function huvi_user_recreate_drush_command() {
  $items = array();
  $items['reasign-user-content'] = array(
    'callback' => 'huvi_user_recreate_ressign_user_content', // Callback function
    'description' => 'Drush command to reassign user content.',
    'aliases' => array('ruc'),
    'arguments' => array(
      'old_uid' => 'ID of old (deleted) user.',
      'new_uid' => 'ID of new user.',
    ),
    'examples' => array(
      'drush ruc 254 698' => 'Assign user 254 content to user 698.',
    ),
  );
  return $items;
}

/**
 * Run SQL queries to reassign user content.
 * 
 * @param string $old_uid
 * @param string $new_uid
 */
function huvi_user_recreate_ressign_user_content(string $old_uid = NULL, string $new_uid = NULL) {

  if (is_null($old_uid) || is_null($new_uid)) {
    drush_print('No arguments. Example: drush ruc 254 698');
    die();
  }
  $filename = 'user-recreate/' . $old_uid . '.sql';

  $handle = fopen($filename, "r");
  if ($handle) {
    while (($line = fgets($handle)) !== false) {
      // Set new user id to the query.
      $line = str_replace('{?}', $new_uid, $line);
      // Run line from the file as SQL query.
      $result = db_query($line);
      // Get table name from request.
      $table = huvi_user_recreate_find_between($line, 'UPDATE', 'SET');
      // Ger result row number.
      $records_number = $result->rowCount();
      // Print information output.
      drush_print(ngettext($table . ' = ' . $records_number . ' record', $table . ' = ' . $records_number . ' records', $records_number));

    }
    fclose($handle);
  }
  else {
    drush_print('Could not open file: ' . $filename);
  }
}

/**
 * Return string between two strings.
 *
 * @param string $string
 * @param string $start
 * @param string $end
 * @param bool $greedy
 * @return type
 */
function huvi_user_recreate_find_between(string $string, string $start, string $end) {
  $start = preg_quote($start, '/');
  $end = preg_quote($end, '/');
  $format = '/(%s)(.*';
  $format .= ')(%s)/';
  $pattern = sprintf($format, $start, $end);
  preg_match($pattern, $string, $matches);

  return trim($matches[2]);
}
