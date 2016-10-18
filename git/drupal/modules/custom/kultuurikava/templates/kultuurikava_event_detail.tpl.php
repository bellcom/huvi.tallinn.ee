<?php
/**
 * @file
 * Single event template
 */
?>

<?php drupal_set_title($event['name']); ?>


<?php
  $path = isset($_GET['q']) ? $_GET['q'] : '<front>';
  $url = url($path, array('absolute' => TRUE));
?>


<article class="event">

  <div class="page-meta">
    <div class="meta-left">

      <div class="back-button">
        <?php print l(t('Back to search'), 'events'); ?>
      </div>
    </div>

    <div class="meta-right">
      <div class="share-buttons">
        <ul>
          <li class="share-text">Share</li>
          <li><a class="mail-share" href="mailto:?subject=<?php print $event['name']; ?>&amp;body=<?php print $event['name'] . '%0D%0A' . $url; ?>"><span>E-mail</span></a></li>
          <li class="share-fb"><a href="#" class="social-share fb-share" data-url="<?php print $url; ?>"><span>Facebook</span></a></li>
          <li class="share-tw"><a href="#" class="social-share twitter-share" data-url="<?php print $url; ?>" data-title="<?php print $event['name']; ?>"><span>Twitter</span></a></li>
          <li class="share-google"><a href="#" class="social-share google-share" data-url="<?php print $url; ?>"><span>Google</span></a></li>
        </ul>
      </div>
    </div>
  </div>


  <div class="page-content">
    <div class="page-content-left">

      <?php if($event['hasimage']): ?>
        <?php if(isset($event['image']) && !empty($event['image'])): ?>
          <div>
            <img src="<?php print $event['image']; ?>" />
          </div>
        <?php endif; ?>
      <?php endif; ?>


      <?php if(isset($event['map_latlng']) && !empty($event['map_latlng'])): ?>
      <?php if(isset($event['map_markers']) && !empty($event['map_markers'])): ?>
      <div id="map_wrapper" style="height: 300px">
          <div id="map_canvas" class="mapping" style="height: 100%; width: 100%" data-markers="<?php print $event['map_markers']; ?>" data-latlng="<?php print $event['map_latlng']; ?>"></div>
      </div>
      <?php endif; ?>
      <?php endif; ?>

    </div>

    <div class="page-content-right">
      <h1><?php print $event['name']; ?></h1>


      <?php if(isset($event['ticket']) && !empty($event['ticket'])): ?>
      <div class="buymain">

        <div class="buy"><a href="#" class="buy-link"><?php print t('Buy ticket'); ?></a></div>

        <div id="ticketmenu" class="buymenu">
          <ul>
          <?php foreach($event['ticket'] as $buy_link): ?>
            <li><?php print $buy_link; ?></li>
          <?php endforeach; ?>
          </ul>
        </div>

      </div>
      <?php endif; ?>

      <?php if(isset($event['schedule']) && !empty($event['schedule'])): ?>
      <div class="event-schedule">

        <?php foreach($event['schedule'] as $schedule_item): ?>
          <?php if(isset($schedule_item['time'])): ?>
          <div class="schedule-item">
            <div class="row">
              <span class="event-time"><?php print $schedule_item['time']; ?></span>
            </div>
            <?php if(isset($schedule_item['place']) && !empty($schedule_item['place'])): ?>
            <div class="row">
              <span class="event-place"><?php print $schedule_item['place']; ?></span>
            </div>
            <?php endif; ?>

          </div>
          <?php endif; ?>
        <?php endforeach; ?>
      </div>
      <?php endif; ?>

      <?php if(isset($event['pre_description']) && !empty($event['pre_description'])): ?>
        <div class="pre-description">
          <?php foreach($event['pre_description'] as $label => $value): ?>
          <strong><?php print t($label); ?>:</strong> <?php print $value; ?> <br />
          <?php endforeach; ?>
        </div>
      <?php endif; ?>

      <?php if(isset($event['description']) && !empty($event['description'])): ?>
        <div class="event-description"><?php print $event['description']; ?></div>
      <?php endif; ?>

    </div>
  </div>
</article>
