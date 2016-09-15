<?php
/**
 * @file
 * huvi_tallinn_settings.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function huvi_tallinn_settings_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'aeg_huvitegevus';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Aeg:';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_event_listing_fixed-block_7',
      'hide_title' => 1,
      'title' => 'Täna',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_event_listing_fixed-block_8',
      'hide_title' => 1,
      'title' => 'Homme',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'views_delta_event_listing_fixed-block_9',
      'hide_title' => 1,
      'title' => 'R-P',
      'weight' => '-98',
      'type' => 'block',
    ),
    3 => array(
      'bid' => 'views_delta_event_listing_fixed-block_10',
      'hide_title' => 1,
      'title' => 'Sel kuul',
      'weight' => '-97',
      'type' => 'block',
    ),
    4 => array(
      'bid' => 'views_delta_event_listing_fixed-block_11',
      'hide_title' => 1,
      'title' => 'Järgmisel kuul',
      'weight' => '-96',
      'type' => 'block',
    ),
    5 => array(
      'bid' => 'views_delta_event_listing_fixed-block_6',
      'hide_title' => 1,
      'title' => 'Kõik',
      'weight' => '-95',
      'type' => 'block',
    ),
    6 => array(
      'bid' => 'views_delta_event_listing_fixed-block_13',
      'hide_title' => 1,
      'title' => 'Vali ajavahemik',
      'weight' => '-94',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Aeg:');
  t('Homme');
  t('Järgmisel kuul');
  t('Kõik');
  t('R-P');
  t('Sel kuul');
  t('Täna');
  t('Vali ajavahemik');

  $export['aeg_huvitegevus'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'event_quicktabs_for_date_range_s';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Aeg:';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_event_listing_fixed-block_1',
      'hide_title' => 1,
      'title' => 'Täna',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_event_listing_fixed-block_2',
      'hide_title' => 1,
      'title' => 'Homme',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'views_delta_event_listing_fixed-block_3',
      'hide_title' => 1,
      'title' => 'R-P',
      'weight' => '-98',
      'type' => 'block',
    ),
    3 => array(
      'bid' => 'views_delta_event_listing_fixed-block_4',
      'hide_title' => 1,
      'title' => 'Sel kuul',
      'weight' => '-97',
      'type' => 'block',
    ),
    4 => array(
      'bid' => 'views_delta_event_listing_fixed-block_5',
      'hide_title' => 1,
      'title' => 'Järgmisel kuul',
      'weight' => '-96',
      'type' => 'block',
    ),
    5 => array(
      'bid' => 'views_delta_event_listing_fixed-block',
      'hide_title' => 1,
      'title' => 'Kõik',
      'weight' => '-95',
      'type' => 'block',
    ),
    6 => array(
      'bid' => 'views_delta_event_listing_fixed-block_12',
      'hide_title' => 1,
      'title' => 'Vali ajavahemik',
      'weight' => '-94',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Aeg:');
  t('Homme');
  t('Järgmisel kuul');
  t('Kõik');
  t('R-P');
  t('Sel kuul');
  t('Täna');
  t('Vali ajavahemik');

  $export['event_quicktabs_for_date_range_s'] = $quicktabs;

  return $export;
}
