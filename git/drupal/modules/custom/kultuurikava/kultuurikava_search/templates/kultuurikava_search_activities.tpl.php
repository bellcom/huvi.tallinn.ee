<?php
/**
 * @file
 * Activities search page template
 */
?>

<div class="events">
  <?php if(isset($data['events']) && !empty($data['events'])):?>
  
  <?php foreach($data['events'] as $group => $events): ?>
  
  <div class="event-group-title"><strong><?php print format_date(strtotime($group), 'custom', 'd.m'); ?></strong> | <?php print format_date(strtotime($group), 'custom', 'l'); ?></div>
  <div class="event-group">
    
    <?php foreach($events as $key => $event): ?>
    <div class="event-item">
      
      <div class="time fixwidth">
        <?php print $event['time']; ?>
      </div>
      
      <div class="name fixwidth">
        <?php print l($event['name'], 'huvitegevus/' . $event['id']); ?>
      </div>
      
      <div class="category fixwidth">
        <?php print $event['categories']; ?>
      </div>
      
      <div class="place fixwidth">
        <?php print $event['place_name']; ?>
      </div>
      
      <div class="clear"></div>
      
    </div>
    <?php endforeach; ?>
    
  </div>
  
  <?php endforeach; ?>

  <?php else: ?>
  <div class="noresults"><?php print t('No activities found, try to refine your search'); ?></div>
  <?php endif; ?>
</div>
