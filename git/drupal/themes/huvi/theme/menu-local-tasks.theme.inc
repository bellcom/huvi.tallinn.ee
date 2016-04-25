<?php

/**
 * @file
 * Contains the theme function override for 'menu_local_task'.
 */

/**
 * Returns HTML for primary and secondary local tasks.
 *
 * @ingroup themeable
 */
function huvi_menu_local_tasks(&$variables) {
  global $user;
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs tabs--primary  links--inline">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs tabs--secondary links--inline">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  // Don't show user menu links to mortals
  if(!in_array('administrator', $user->roles)
    && !in_array('manager', $user->roles)) {
    $output = '';
  }

  return $output;
}
