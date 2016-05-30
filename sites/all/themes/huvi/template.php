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

  if ((arg(0) == 'uritus' || arg(0) == 'huvitegevus') && is_numeric(arg(1))) {
    $layout = 'single';
  }

  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $nid = arg(1);
    $node = node_load($nid);
    if (isset($node) && $node->type == 'event') {
      $layout = 'single';
    }
  }

  // Landing layout.
  if (arg(0) == 'landing') {
    $layout = 'landing';
  }
}
