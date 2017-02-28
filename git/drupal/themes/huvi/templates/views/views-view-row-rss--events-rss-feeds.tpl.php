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
    <?php if ($format == 1 || $format == 2 ) : ?>
      <description><?php  print $description; ?></description>
    <?php endif; ?>  
    <?php print $item_elements; ?>
      
  </item>
