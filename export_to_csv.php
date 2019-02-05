<?php

print('Starting..' . PHP_EOL);
/** bootstrap Drupal * */
chdir(__DIR__);
require_once './includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
print('Drupal bootstrap done..' . PHP_EOL);
print('Loading data..' . PHP_EOL);
$query = new EntityFieldQuery;
$result = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'event')
    ->propertyCondition('created', array('1514757600', ' 1546250399'), 'between')
    ->propertyCondition('status', 1) // Here instead of in $conditions
    ->execute();
if (empty($result['node'])) {
  print('No nodes found'); // No applicable nodes found, no nodes to load.
}

$filtered_nids = array_keys($result['node']);
$fp = fopen('events_export.csv', 'wb');
fputcsv($fp, array('ID', 'Name', 'Description', 'Toimumiskoht', 'Organizers name', 'Location coordinates', 'Toimumiskuupäev', 'Toimumiskellaaeg', 'District', 'Type'));

$nodes = node_load_multiple($filtered_nids);
print('Processing..' . PHP_EOL);
$lines = 0;
foreach ($nodes as $node) {
  $wrapper = entity_metadata_wrapper('node', $node);
  if (is_array($wrapper->field_schedule->value())) {
    foreach ($wrapper->field_schedule->value() as $schedule_item) {
      $asukoht_term = NULL;
      $node_data = array();
      $node_data[0] = $node->nid;
      $node_data[1] = $node->title;
      $node_data[2] = $wrapper->field_description->value()['value'];
      if (!empty($schedule_item->field_schedule_toimumis['und'][0]['tid'])) {
        $asukoht_term = taxonomy_term_load($schedule_item->field_schedule_toimumis['und'][0]['tid']);
        if (!empty($asukoht_term)) {
          $node_data[3] = $asukoht_term->name;
        }
        else {
          $node_data[3] = Null;
        }
      }
      else {
        $node_data[3] = Null;
      }

      if (!empty($wrapper->field_korraldaja->value())) {
        $node_data[4] = $wrapper->field_korraldaja->field_korraldaja_nimi->value();
      }
      else {
        $node_data[4] = '';
      }
      if (!empty($node->field_map_latlng['und'][0]['value'])) {
        $node_data[5] = $node->field_map_latlng['und'][0]['value'];
      }
      $node_data[6] = '';
      $node_data[7] = '';
      $all_fields = field_info_fields();
      $field_schedule_city_id_array = list_allowed_values($all_fields["field_schedule_city_id"]);

      $koht_array = array();
      if (!empty($field_schedule_city_id_array[$schedule_item->field_schedule_city_id['und'][0]['value']])) {
        $node_data[8] = $field_schedule_city_id_array[$schedule_item->field_schedule_city_id['und'][0]['value']];
      }
      $node_data[9] = $node->field_type['und'][0]['value'];
      if (is_array($schedule_item->field_schedule_date['und'])) {
        foreach ($schedule_item->field_schedule_date['und'] as $event_date) {
          $node_data[6] = gmdate("Y-m-d", $event_date['value']);
          $node_data[7] = gmdate("H:i", $event_date['value']);
          if ($event_date['value'] <> $event_date['value2']) {
            $node_data[7] = $node_data[7] . '-' . gmdate("H:i", $event_date['value2']);
          }
          fputcsv($fp, $node_data);
          print($lines++ . "\r");
        }
      }
      else {
        fputcsv($fp, $node_data);
      }
    }
  }
}
fclose($fp);
print(PHP_EOL . 'File ' . __DIR__ . DIRECTORY_SEPARATOR . 'events_export.csv' . ' is generated successfully.' . PHP_EOL);
print('Finish.' . PHP_EOL);
