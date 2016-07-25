<?php
/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
$node = node_load( $row->nid );
$target = $node->field_adv_link['und'][0]['attributes']['target'] ;
$link = $node->field_adv_link['und'][0]['url'] ;
$src = $field->last_tokens['[field_adv_image]'] ;
  if( !empty($target) && $target == "_blank" ){ //The banner open on a new page or not open
    $link = $node->field_adv_link['und'][0]['url'] ;
    $src = $field->last_tokens['[field_adv_image]'] ;?>
    <a href = '<?php print $link ; ?>' target = '<?php print $target ; ?>' >
    <?php print ($src) ; ?></a>
<?php 
  }
  else{?>
    <a href = '<?php print $link ; ?>' >
    <?php print ($src) ; ?></a>
<?php
  }?>