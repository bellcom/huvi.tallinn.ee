<?php

/**
 * @file
 * Kultuurikava Search pages.
 */

/**
 * Events search.
 * 
 * @return longtext
 *   rendered search page
 */
function kultuurikava_search_events() {
  $data = array();

  $date = date('Y-m-d');

  // Filtering.
  $filtering = array();

  // Keyword search.
  if (isset($_GET['keyword']) && !empty($_GET['keyword'])) {
    $filtering['sw'] = $_GET['keyword'];
  }

  // Time period filtering.
  if (isset($_GET['time']) && !empty($_GET['time'])) {

    switch ($_GET['time']) {
      case 'today':
        $date = date('Y-m-d');
        $filtering['enddate'] = $date;
        break;

      case 'tomorrow':
        $date = date('Y-m-d', strtotime("+1 day"));
        $filtering['enddate'] = $date;
        break;

      case 'weekend':

        // Current day of week.
        $day_of_week = date('N');
        switch ($day_of_week) {
          case '5':
            $date = date('Y-m-d');
            $filtering['enddate'] = date('Y-m-d', strtotime("next Sunday"));
            break;

          case '6':
            $date = date('Y-m-d', strtotime("last Friday"));
            $filtering['enddate'] = date('Y-m-d', strtotime("next Sunday"));
            break;

          case '7':
            $date = date('Y-m-d', strtotime("-2 days"));
            $filtering['enddate'] = date('Y-m-d');
            break;

          default:
            $date = date('Y-m-d', strtotime("next Friday"));
            $filtering['enddate'] = date('Y-m-d', strtotime("next Sunday"));
            break;
        }
        break;

      case 'thismonth':
        $date = date('Y-m-d');
        $filtering['enddate'] = date("Y-m-t", strtotime($date));
        break;

      case 'nextmonth':
        $date = date('Y-m-d', strtotime("first day of +1 month"));
        $filtering['enddate'] = date('Y-m-d', strtotime("last day of +1 month"));
        break;

      default:
        break;
    }

  }

  // Category filter.
  if (isset($_GET['category']) && !empty($_GET['category'])) {

    $categories = kultuurikava_get_categories('events');
    $category_filters = array();

    foreach ($_GET['category'] as $key => $category) {

      if (!array_key_exists($category, $categories)) {
        continue;
      }

      if (in_array($category, $category_filters)) {
        continue;
      }

      $category_filters[] = $category;

    }

    if (isset($category_filters) && !empty($category_filters)) {

      $filtering['category'] = array();

      foreach ($category_filters as $category) {
        $filtering['category'] = array_merge($filtering['category'], kultuurikava_get_kk_categories_by_slug($category, 'events'));
      }

      $filtering['category'] = implode($filtering['category'], ';');
    }

  }

  // Regions filter.
  if (isset($_GET['region']) && !empty($_GET['region'])) {

    $regions = kultuurikava_search_events_regions();
    $city_filters = array();

    foreach ($_GET['region'] as $key => $region) {

      if (!array_key_exists($region, $regions)) {
        continue;
      }

      if (in_array($region, $city_filters)) {
        continue;
      }

      $city_filters[] = $region;
    }

    if (isset($city_filters) && !empty($city_filters)) {
      $filtering['city'] = implode($city_filters, ';');
    }
  }
  
  // Free events filter
  if(isset($_GET['free']) && !empty($_GET['free'])) {
    if($_GET['free'] == '1') {
       $filtering['isfree'] = 'true';
    }
  }

  // Default page.
  $page = 0;

  if (isset($_GET['page']) && !empty($_GET['page'])) {
    $page = $_GET['page'];
  }

  // Items per page.
  $limit = 40;
  $start = $page * $limit;

  $parameters = array(
    'do' => 'events',
    'start' => $start,
    'limit' => $limit,
    'group' => TRUE,
    'date' => $date,
    'county' => 'tallinn',
    'order' => 'starta',
    'event' => 'true',
  );
  $parameters = array_merge($parameters, $filtering);
  $events = kultuurikava_api_call($parameters, NULL, 'nat');

  if (isset($events['events']) && !empty($events['events'])) {

    $data['events'] = array();
    foreach ($events['events'] as $key => $event) {

      // Grouping.
      $event_date = date('d-m-Y', $event['start_time']);
      if (!isset($data['events'][$event_date])) {
        $data['events'][$event_date] = array();
      }

      if (date('Hi', $event['start_time']) == '0000') {
        $data['events'][$event_date][$key]['time'] = '';
      }
      else {
        $data['events'][$event_date][$key]['time'] = date('H:i', $event['start_time']);
      }

      // Categories.
      $data['events'][$event_date][$key]['categories'] = '';
      if (isset($event['categories']) && !empty($event['categories'])) {
        $event_categories = array();
        foreach ($event['categories'] as $category_id) {
          $event_category = kultuurikava_get_category_by_kk_id($category_id, 'events');
          if ($event_category) {
            $event_categories[] = $event_category[0]->name;
          }
        }

        $data['events'][$event_date][$key]['categories'] = implode(', ', array_unique($event_categories));

      }

      $data['events'][$event_date][$key]['id'] = $event['id'];
      $data['events'][$event_date][$key]['name'] = $event['name'];
      $data['events'][$event_date][$key]['start_time'] = date('d.m.Y H:i', $event['start_time']);
      $data['events'][$event_date][$key]['end_time'] = date('d.m.Y H:i', $event['end_time']);
      $data['events'][$event_date][$key]['place_name'] = $event['place_name'];
    }

  }

  $output = theme('kultuurikava_search_events', array('data' => $data));
  $current_page = pager_default_initialize($events['total'], $limit);
  $output .= theme('pager', array('quantity', $events['total']));

  $return = array(
    'form' => drupal_get_form('kultuurikava_search_events_form'),
    'content' => array(
      '#type' => 'markup',
      '#markup' => $output,
    ),
  );

  return $return;
}


/**
 * Events search form.
 * 
 * @param array $form
 *   form
 * @param array $form_state
 *   form state
 * 
 * @return array
 *   form array
 */
function kultuurikava_search_events_form($form, &$form_state) {

  $form['#prefix'] = '<div id="events_search_form">';
  $form['#suffix'] = '</div>';

  $form['#action'] = url('uritused');
  $form['#method'] = 'GET';
  $form['#pre_render'][] = 'kultuurikava_search_unset_default_form_elements';
  $form['#after_build'] = array('kultuurikava_search_events_form_afterbuild');

  $form['full_text'] = array(
    '#type' => 'fieldset',
  );

  $form['full_text']['keyword'] = array(
    '#type' => 'textfield',
    '#title' => t('Find event'),
    '#default_value' => !empty($_GET['keyword']) ? $_GET['keyword'] : '',
    '#size' => 60,
    '#maxlength' => 128,
    '#attributes' => array(
      'placeholder' => t('For example: Movies for children'),
    ),
  );

  $form['full_text']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );

  $periods = array(
    'today' => t('Today'),
    'tomorrow' => t('Tomorrow'),
    'weekend' => t('Fri-Sun'),
    'thismonth' => t('This month'),
    'nextmonth' => t('Next month'),
  );

  $form['filters']['time'] = array(
    '#type' => 'radios',
    '#title' => t('When?'),
    '#default_value' => !empty($_GET['time']) ? $_GET['time'] : '',
    '#options' => $periods,
  );

  // Categories.
  $categories = kultuurikava_get_categories('events');

  // Default categories.
  $default_categories = array();
  if (isset($_GET['category']) && !empty($_GET['category'])) {

    foreach ($_GET['category'] as $key => $category) {

      if (!array_key_exists($category, $categories)) {
        continue;
      }

      if (in_array($category, $default_categories)) {
        continue;
      }

      $default_categories[] = $category;

    }

  }

  $form['filters']['category'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Event type?'),
    '#options' => $categories,
    '#default_value' => $default_categories,
    '#multiple' => TRUE,
    '#theme' => 'select_as_checkboxes',
  );

  // Regions.
  $regions = kultuurikava_search_events_regions();

  // Default regions.
  $default_regions = array();
  if (isset($_GET['region']) && !empty($_GET['region'])) {

    foreach ($_GET['region'] as $key => $region) {

      if (!array_key_exists($region, $regions)) {
        continue;
      }

      if (in_array($region, $default_regions)) {
        continue;
      }

      $default_regions[] = $region;

    }

  }

  $form['filters']['region'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Region?'),
    '#options' => $regions,
    '#default_value' => $default_regions,
    '#multiple' => TRUE,
    '#theme' => 'select_as_checkboxes',
  );

  $form['free'] = array(
    '#type' => 'checkbox',
    '#title' => t('Free events'),
    '#default_value' => !empty($_GET['free']) ? $_GET['free'] : '',
  );

  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset fields'),
  );

  $form['#attached']['js'][] = drupal_get_path('module', 'kultuurikava_search') . '/kultuurikava_search.js';

  return $form;

}


/**
 * Remove some elements from url.
 * 
 * @param array $form
 *   form
 * 
 * @return array
 *   form
 */
function kultuurikava_search_unset_default_form_elements($form) {
  unset($form['form_token']);
  unset($form['form_build_id']);
  unset($form['form_id']);
  unset($form['submit']['#name']);

  return $form;
}


/**
 * Form after build.
 * 
 * @param array $form
 *   form
 * 
 * @return array
 *   form
 */
function kultuurikava_search_events_form_afterbuild($form) {
  $op = isset($_GET['op']) ? $_GET['op'] : '';
  if ($op == t('Reset fields')) {
    drupal_goto("uritused");
  }
  else {
    return $form;
  }
}


/**
 * Form after build.
 * 
 * @param array $form
 *   form
 * 
 * @return array
 *   form
 */
function kultuurikava_search_activities_form_afterbuild($form) {
  $op = isset($_GET['op']) ? $_GET['op'] : '';
  if ($op == t('Reset fields')) {
    drupal_goto("huvitegevused");
  }
  else {
    return $form;
  }
}


/**
 * Get Tallinn regions.
 * 
 * @param bool $keys
 *   return with keys or not
 * 
 * @return array
 *   regions
 */
function kultuurikava_search_events_regions($keys = FALSE) {

  $regions = array(
    'haabersti' => t('Haabersti'),
    // 'kadriorg' => t('Kadriorg'),
    'kesklinn' => t('Kesklinn'),
    'kristiine' => t('Kristiine'),
    'lasnamae' => t('Lasnamäe'),
    'mustamae' => t('Mustamäe'),
    'nomme' => t('Nõmme'),
    'pirita' => t('Pirita'),
    'pohja-tallinn' => t('Põhja-Tallinn'),
    // 'tallinn' => t('Tallinn'),
    // 'vanalinn' => t('Vanalinn'),
  );

  if ($keys) {
    $regions_keys = array();
    foreach ($regions as $key => $region) {
      $regions_keys[] = $key;
    }

    return $regions_keys;
  }

  return $regions;
}


/**
 * Get Categories. DEPRICATED.
 * 
 * @param bool $keys
 *   return with keys or not
 * 
 * @return array
 *   categories
 */
function kultuurikava_search_events_categories($keys = FALSE) {
  $categories = array(
    'music' => t('Music'),
    'performances' => t('Performances'),
    'exhibitions' => t('Exhibitions'),
    'fairs' => t('Fairs, markets'),
    'sports' => t('Sports'),
    'movies' => t('Movies'),
    'nightlife' => t('Nightlife'),
    'children' => t('Children'),
    'other' => t('Other'),
  );

  if ($keys) {
    $categories_keys = array();
    foreach ($categories as $key => $category) {
      $categories_keys[] = $key;
    }

    return $categories_keys;
  }

  return $categories;

}


/**
 * Get kultuurikava category slugs by own category slug.
 * 
 * @param string $category
 *   category slug
 * 
 * @return array
 *   kultuurikava categories
 */
function kultuurikava_search_events_api_categories($category) {

  switch ($category) {
    case 'music':
      $result = array('muusika', 'tants');
      break;

    case 'performances':
      $result = array('teater');
      break;

    case 'exhibitions':
      $result = array('naitus', 'muuseum');
      break;

    case 'fairs':
      $result = array('mess-ja-laat');
      break;

    case 'sports':
      $result = array('sport');
      break;

    case 'movies':
      $result = array('kino');
      break;

    case 'nightlife':
      $result = array('pidu-klubi');
      break;

    case 'children':
      $result = array('pere-ja-lapsed');
      break;

    case 'other':
      $result = array('varia', 'kirjandus', 'kirik', 'huvialad', 'rahvakultuur');
      break;
  }

  return $result;
}


/**
 * Activities search.
 * 
 * @return longtext
 *   rendered search page
 */
function kultuurikava_search_activities() {

  $data = array();

  $date = date('Y-m-d');

  // Filtering.
  $filtering = array();

  // Keyword search.
  if (isset($_GET['keyword']) && !empty($_GET['keyword'])) {
    $filtering['sw'] = $_GET['keyword'];
  }

  // Time period filtering.
  if (isset($_GET['time']) && !empty($_GET['time'])) {

    switch ($_GET['time']) {
      case 'today':
        $date = date('Y-m-d');
        $filtering['enddate'] = $date;
        break;

      case 'tomorrow':
        $date = date('Y-m-d', strtotime("+1 day"));
        $filtering['enddate'] = $date;
        break;

      case 'weekend':

        // Current day of week.
        $day_of_week = date('N');
        switch ($day_of_week) {
          case '5':
            $date = date('Y-m-d');
            $filtering['enddate'] = date('Y-m-d', strtotime("next Sunday"));
            break;

          case '6':
            $date = date('Y-m-d', strtotime("last Friday"));
            $filtering['enddate'] = date('Y-m-d', strtotime("next Sunday"));
            break;

          case '7':
            $date = date('Y-m-d', strtotime("-2 days"));
            $filtering['enddate'] = date('Y-m-d');
            break;

          default:
            $date = date('Y-m-d', strtotime("next Friday"));
            $filtering['enddate'] = date('Y-m-d', strtotime("next Sunday"));
            break;
        }

        break;

      case 'thismonth':
        $date = date('Y-m-d');
        $filtering['enddate'] = date("Y-m-t", strtotime($date));
        break;

      case 'nextmonth':
        $date = date('Y-m-d', strtotime("first day of +1 month"));
        $filtering['enddate'] = date('Y-m-d', strtotime("last day of +1 month"));
        break;

      default:
        break;
    }

  }

  // Category filter.
  if (isset($_GET['category']) && !empty($_GET['category'])) {

    $categories = kultuurikava_get_categories('activities');
    $category_filters = array();

    foreach ($_GET['category'] as $key => $category) {

      if (!array_key_exists($category, $categories)) {
        continue;
      }

      if (in_array($category, $category_filters)) {
        continue;
      }

      $category_filters[] = $category;

    }

    if (isset($category_filters) && !empty($category_filters)) {

      $filtering['category'] = array();

      foreach ($category_filters as $category) {
        $filtering['category'] = array_merge($filtering['category'], kultuurikava_get_kk_categories_by_slug($category, 'activities'));
      }

      $filtering['category'] = implode($filtering['category'], ';');
    }

  }

  // Regions filter.
  if (isset($_GET['region']) && !empty($_GET['region'])) {

    $regions = kultuurikava_search_events_regions();
    $city_filters = array();

    foreach ($_GET['region'] as $key => $region) {

      if (!array_key_exists($region, $regions)) {
        continue;
      }

      if (in_array($region, $city_filters)) {
        continue;
      }

      $city_filters[] = $region;
    }

    if (isset($city_filters) && !empty($city_filters)) {
      $filtering['city'] = implode($city_filters, ';');
    }
  }
  
  // Free events filter
  if(isset($_GET['free']) && !empty($_GET['free'])) {
    if($_GET['free'] == '1') {
       $filtering['isfree'] = 'true';
    }
  }

  // Default page.
  $page = 0;

  if (isset($_GET['page']) && !empty($_GET['page'])) {
    $page = $_GET['page'];
  }

  // Items per page.
  $limit = 40;
  $start = $page * $limit;

  $parameters = array(
    'do' => 'events',
    'start' => $start,
    'limit' => $limit,
    'group' => TRUE,
    'date' => $date,
    'county' => 'tallinn',
    'order' => 'starta',
    'recreation' => 'true',
  );
  $parameters = array_merge($parameters, $filtering);
  $events = kultuurikava_api_call($parameters, NULL, 'nat');

  if (isset($events['events']) && !empty($events['events'])) {

    $data['events'] = array();
    foreach ($events['events'] as $key => $event) {

      // Grouping.
      $event_date = date('d-m-Y', $event['start_time']);
      if (!isset($data['events'][$event_date])) {
        $data['events'][$event_date] = array();
      }

      if (date('Hi', $event['start_time']) == '0000') {
        $data['events'][$event_date][$key]['time'] = '';
      }
      else {
        $data['events'][$event_date][$key]['time'] = date('H:i', $event['start_time']);
      }

      // Categories.
      $data['events'][$event_date][$key]['categories'] = '';
      if (isset($event['categories']) && !empty($event['categories'])) {
        $event_categories = array();
        foreach ($event['categories'] as $category_id) {
          $event_category = kultuurikava_get_category_by_kk_id($category_id, 'activities');
          if ($event_category) {
            $event_categories[] = $event_category[0]->name;
          }
        }

        $data['events'][$event_date][$key]['categories'] = implode(', ', array_unique($event_categories));
      }

      $data['events'][$event_date][$key]['id'] = $event['id'];
      $data['events'][$event_date][$key]['name'] = $event['name'];
      $data['events'][$event_date][$key]['start_time'] = date('d.m.Y H:i', $event['start_time']);
      $data['events'][$event_date][$key]['end_time'] = date('d.m.Y H:i', $event['end_time']);
      $data['events'][$event_date][$key]['place_name'] = $event['place_name'];
    }

  }

  $output = theme('kultuurikava_search_activities', array('data' => $data));
  $current_page = pager_default_initialize($events['total'], $limit);
  $output .= theme('pager', array('quantity', $events['total']));

  $return = array(
    'form' => drupal_get_form('kultuurikava_search_activities_form'),
    'content' => array(
      '#type' => 'markup',
      '#markup' => $output,
    ),
  );

  return $return;

}


/**
 * Activities search form.
 * 
 * @param array $form_state
 *   form state
 * 
 * @return array
 *   form array
 */
function kultuurikava_search_activities_form($form, &$form_state) {

  $form['#prefix'] = '<div id="events_search_form">';
  $form['#suffix'] = '</div>';

  $form['#action'] = url('huvitegevused');
  $form['#method'] = 'GET';
  $form['#pre_render'][] = 'kultuurikava_search_unset_default_form_elements';
  $form['#after_build'] = array('kultuurikava_search_activities_form_afterbuild');

  $form['full_text'] = array(
    '#type' => 'fieldset',
  );

  $form['full_text']['keyword'] = array(
    '#type' => 'textfield',
    '#title' => t('Find activity'),
    '#default_value' => !empty($_GET['keyword']) ? $_GET['keyword'] : '',
    '#size' => 60,
    '#maxlength' => 128,
    '#attributes' => array(
      'placeholder' => t('For example: Saturday activities'),
    ),
  );

  $form['full_text']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );

  $periods = array(
    'today' => t('Today'),
    'tomorrow' => t('Tomorrow'),
    'weekend' => t('Fri-Sun'),
    'thismonth' => t('This month'),
    'nextmonth' => t('Next month'),
  );

  $form['filters']['time'] = array(
    '#type' => 'radios',
    '#title' => t('When?'),
    '#default_value' => !empty($_GET['time']) ? $_GET['time'] : '',
    '#options' => $periods,
  );

  // Categories.
  $categories = kultuurikava_get_categories('activities');

  // Default categories.
  $default_categories = array();
  if (isset($_GET['category']) && !empty($_GET['category'])) {

    foreach ($_GET['category'] as $key => $category) {

      if (!array_key_exists($category, $categories)) {
        continue;
      }

      if (in_array($category, $default_categories)) {
        continue;
      }

      $default_categories[] = $category;

    }

  }

  $form['filters']['category'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Activity type?'),
    '#options' => $categories,
    '#default_value' => $default_categories,
    '#multiple' => TRUE,
    '#theme' => 'select_as_checkboxes',
  );

  // Regions.
  $regions = kultuurikava_search_events_regions();

  // Default regions.
  $default_regions = array();
  if (isset($_GET['region']) && !empty($_GET['region'])) {

    foreach ($_GET['region'] as $key => $region) {

      if (!array_key_exists($region, $regions)) {
        continue;
      }

      if (in_array($region, $default_regions)) {
        continue;
      }

      $default_regions[] = $region;

    }

  }

  $form['filters']['region'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Region?'),
    '#options' => $regions,
    '#default_value' => $default_regions,
    '#multiple' => TRUE,
    '#theme' => 'select_as_checkboxes',
  );

  $form['free'] = array(
    '#type' => 'checkbox',
    '#title' => t('Free activities'),
    '#default_value' => !empty($_GET['free']) ? $_GET['free'] : '',
  );

  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset fields'),
  );

  $form['#attached']['js'][] = drupal_get_path('module', 'kultuurikava_search') . '/kultuurikava_search.js';
  // $form_state['rebuild'] = TRUE;

  return $form;

}
