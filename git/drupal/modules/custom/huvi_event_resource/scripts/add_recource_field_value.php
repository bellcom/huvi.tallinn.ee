<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
$user = user_load_by_name('webservice_user');
$query = new EntityFieldQuery();
$result = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->propertyCondition('uid', $user->uid, '=')
    ->execute();
if ($result) {
  foreach ($result['node'] as $key => $node) {
    $entity_load = entity_load('node', array($key));
    foreach ($entity_load as $ekey => $eval) {
      $entity = $eval;
    }
    $w = entity_metadata_wrapper('node', $entity);
    $w->field_source->set(1);
    $w->save();
  }
}
