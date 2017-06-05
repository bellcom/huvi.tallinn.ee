<?php
/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <?php print $field->wrapper_prefix; ?>
  <?php print $field->label_html; ?>
  <?php
    $node = node_load($row->nid);
    $target = $node->field_adv_link['und'][0]['attributes']['target'];
    $link = $node->field_adv_link['und'][0]['url'];
    $src = $node->field_adv_image['und'][0]['uri'];

  //The banner open on a new page or not open
    if (!empty($target) && $target == "_blank") : ?> 
      <a href = '<?php print $link; ?>' target = '<?php print $target; ?>' >
      <?php print '<img src =' . file_create_url($src) . ' >'; ?></a>
    <?php else :   ?>
      <a href = '<?php print $link; ?>' >
      <?php print '<img src =' . file_create_url($src) . ' >'; ?></a>
    <?php   endif;  ?>
  <?php print $field->wrapper_suffix; ?>
<?php endforeach; ?>
