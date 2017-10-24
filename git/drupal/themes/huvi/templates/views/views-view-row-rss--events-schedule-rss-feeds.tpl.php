<?php
/**
 * @file
 * Default view template to display a item in an RSS feed.
 *
 * @ingroup views_templates
 */
$format = $_GET['format'];
?>
<item>
  <title><?php print $title; ?></title>
  <link><?php print $link; ?></link>
  <?php if ($format == 1 || $format == 2) : ?>
    <description><?php print $description; ?></description>
  <?php endif; ?>
  <?php if ($format == 2) : ?>

    <?php $node = node_load($view->result[$view->row_index]->field_schedule_field_collection_item_nid); ?>

    <?php if (file_exists(drupal_realpath($node->field_gallery['und'][0]['uri']))): ?>
      <enclosure url="<?php print file_create_url($node->field_gallery['und'][0]['uri']); ?>" type="image/*" />
      <?php elseif ($image = $node->field_image_url['und'][0]['value']): ?>
      <enclosure url="<?php print $image ?>" type="image/*" />
    <?php endif; ?>
  <?php endif; ?>
  <?php print $item_elements; ?>

</item>
