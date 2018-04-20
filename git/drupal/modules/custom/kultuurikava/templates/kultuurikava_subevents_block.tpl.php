<?php if (!empty($subevents)) : ?>
<div class="subevents-block" id="node-<?php print $parent_nid?>">
  <h2 class="sub-event-title"><?php print(t('Sub-events')); ?></h2>
  <div class="sub-events">
  <?php if (isset($filters) && !empty($filters)) :?>
    <div class="subevents-filters">
    <?php foreach ($filters as $type => $filters) { ?>

      <ul class="subevent-filter-tabs" id="<?php print $type ?>">
        <li class="label"><?php print $filters['label'] ?> </li>
        <?php foreach ($filters['tabs'] as $key => $label) : ?>
          <?php if (in_array($key, $existing_filters[$type])) : ?>
            <li class="<?php (in_array($key, $active_filters[$type]) ? print 'active' : '')?>"><a href="#" id="<?php print $key ?>" class="subevent-filter-tab"><?php print $label ?></a></li>
          <?php endif ?>
        <?php endforeach ?>
      </ul>
    <?php } ?>
      <div id="modal_loader">
              </div>
  </div>
  <?php endif;?>
    <div id="sub_events">
    <?php print theme('kultuurikava_subevents', array('subevents' => $subevents));
    ?>
  </div>
  </div>
    
</div>  
<?php endif; ?>
