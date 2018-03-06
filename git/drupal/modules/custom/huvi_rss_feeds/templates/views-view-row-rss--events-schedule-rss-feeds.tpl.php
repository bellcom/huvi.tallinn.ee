<?php
/**
 * @file
 * Default view template to display a item in an RSS feed.
 *
 * @ingroup views_templates
 */
?>
<item>
  <title><?php print $title; ?></title>
  <link><?php print $link; ?></link>
  <description><?php print check_plain(strip_tags($description)); ?></description>
  <date><?php print $event_date ?> </date>
  <excerpt><?php print _huvi_rss_feeds_clear_html($excerpt); ?></excerpt>
  <predescription><?php print _huvi_rss_feeds_clear_html($pre_description); ?></predescription>
  <categories><?php print implode(', ' , $categories) ;?></categories>
  <?php if (isset($ticketurl) && is_array($ticketurl)) :?>
    <ticketUrl ><?php print implode(', ' , $ticketurl); ?></ticketUrl>
  <?php endif?>
  <video><?php print  htmlspecialchars($video); ?></video>
  <isfree><?php print $isfree; ?></isfree>
  <place> <?php print $place; ?></place>
  <point><?php print $map_latlng; ?></point>
  <managerName> <?php print $manager_name; ?></managerName>
  <managerEmail> <?php print $manager_email; ?></managerEmail>
  <managerPhone> <?php print $manager_phone; ?></managerPhone>
  <enclosure url="<?php print $image; ?>" type="image/*" />
 <?php print $item_elements; ?>

</item>
