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

function huvi_preprocess_views_view(&$variables) {
  if ($variables['view']->name  == 'event_listing_fixed') {
     if (!empty($variables['attachment_before'])) {
    // The line below is what is returning 0 regardless of how many rows are in the attachment.
    $attachment = $variables['attachment_before'];
    if (!empty($variables['empty']) && strpos( $attachment, "view-content") !== FALSE) {
      unset($variables['empty']);
    }
  }
  }
}