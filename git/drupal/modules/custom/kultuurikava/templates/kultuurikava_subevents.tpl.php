<?php if(!empty($subevents)) : ?>
    <?php foreach ($subevents as $day => $sub_event_group) { ?>
      <div class="event-group">      <h3><span class="date-display-single"><?php print format_date(strtotime($day), 'only_date_with_year') ?></span></h3>
        <?php foreach ($sub_event_group as $key => $sub_event) { ?>
          <a class="sub-event" href="<?php print $sub_event['path']; ?>">
            <div class="sub-event-row">
              <div class="sub-event-row-left-col"><?php print $sub_event['time']; ?></div>
              <div class="sub-event-row-right-col">
                <span class="sub-event-row-right-col-title"><?php print $sub_event['title']; ?> - </span>
                <?php print $sub_event['place']; ?>
              </div>
            </div>
          </a>
        <?php } ?>
      </div>
    <?php } ?>
  <?php else:?>
<div class="subevents-empty">
      <p>Kahjuks ei leitud ühtegi üritust antud kriteeriumitega.</p>
    </div>
  <?php endif; ?>

