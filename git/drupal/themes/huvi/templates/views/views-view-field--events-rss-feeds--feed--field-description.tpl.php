<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
$format = $_GET['format'];


$output = htmlspecialchars_decode($output);

$output = str_replace("&amp;", "&", $output);
$output = strtr($output, array(
  '&#039;' => "'",
  "&quot;" => '"',
  '&lt;' => '<',
  '&gt;' => '>',
  '&amp;' => '&',
  ));
if ($format == 2){
 $node = node_load($view->result[$view->row_index]->field_schedule_field_collection_item_nid);
 $output  = '<img src="' . $node->field_image_url['und'][0]['value'] . '" width="150" align="left" hspace ="10">' . $output;
}
print decode_entities($output);