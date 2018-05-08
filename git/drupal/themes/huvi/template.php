<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * huvi theme.
 */

/**
 * Implements theme_omega_layout_alter().
 *
 * @param string $layout
 *   layout
 */
function huvi_omega_layout_alter(&$layout) {
  $header = drupal_get_http_header('status');
  if ($header == '404 Not Found') {
    $layout = 'main';
    return;
  }
  if ((arg(0) == 'uritus' || arg(0) == 'huvitegevus')) {
    $layout = 'single';
  }

  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $nid = arg(1);
    $node = node_load($nid);
    if (isset($node) && $node->type == 'event') {
      $layout = 'single';
      $url = $_SERVER['HTTP_REFERER'];
      drupal_add_js("remapBackButton('$url');", array('type' => 'inline', 'scope' => 'footer'));
    }
  }

  // Landing layout.
  if (arg(0) == 'landing') {
    $layout = 'landing';
  }
}