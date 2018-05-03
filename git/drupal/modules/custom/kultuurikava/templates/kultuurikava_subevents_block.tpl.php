<?php if (!empty($subevents)) : ?>
<div class="subevents-block" id="node-<?php print $parent_nid?>">
  <h2 class="sub-event-title"><?php print(t('Sub-events')); ?></h2>
  <div class="sub-events">
  <?php if (isset($filters) && !empty($filters)) :?>
    <div class="subevents-filters">
    <?php foreach ($filters as $type => $filters) { ?>
      <div id="<?php print $type ?>" class="subevents-filter">
      <div class="subevents-filter-input">

        <input type="text"  name="<?php print $type ?>"  class="subevents-filter-textbox" value="<?php print $filters['label']?>" label="<?php print $filters['label']?>"readonly />

      <div  class="subevents-filter-list">
        <?php foreach ($filters['tabs'] as $key => $label) : ?>

          <?php if (in_array($key, $existing_filters[$type])) : ?>
          <?php if ($type == 'date') :?>
        <div id="<?php print $key?>">
          <input class="regular-radio filter-radio" type="radio" <?php in_array($key, $active_filters[$type]) ? print 'checked' : '' ?> name="<?php print $type?>" value = "<?php print $key?>" label="<?php print $label ?>"> <?php print $label ?> </div>
          <?php if ($key == 'period') :?>
        <div class="period-dates"><input type="text" id="start_date" name="start_date" placeholder="pp/kk/aa" readonly="readonly"/> - <input type="text" id="end_date" name="end_date" placeholder="pp/kk/aa" /></div>
        <?php endif;?>
            <?php else: ?>
          <div>   <input class="regular-checkbox filter-checkbox" type="checkbox" <?php (in_array($key, $active_filters[$type]) || !isset($active_filters[$type])) ? print 'checked' : ''?> name="<?php print type ?>" value = "<?php print $key?>" id="<?php print $key?>" label="<?php print $label ?>"><?php print $label ?> </div>
          <?php endif ?>
<!-- <li class="<?php (in_array($key, $active_filters[$type]) ? print 'active' : '')?>"><a href="#" id="<?php print $key ?>" class="subevent-filter-tab"><?php print $label ?></a></li>-->
          <?php endif ?>

        <?php endforeach ?>
        <?php if ($type != 'date') :?>

         <div class="select-links"><a href="#" class="check-all-filters-link"> <?php print ('Vali kõik')?> </a> | <a href="#" class="uncheck-all-filters-link"> <?php print ('Eemalda kõik')?> </a></div>
        <?php endif?>
      </div>
              </div>
    </div>

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
