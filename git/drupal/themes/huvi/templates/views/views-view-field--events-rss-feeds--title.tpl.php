<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//print $output;
$output = htmlspecialchars_decode($output);

$output = str_replace("&amp;", "&", $output);
$output = strtr($output, array(
  '&#039;' => "'",
  "&quot;" => '"',
  '&lt;' => '<',
  '&gt;' => '>',
  '&amp;' => '&',
  ));

print decode_entities($output);
