<?php
/**
 * @file
 * Single event template
 */

$event = kultuurikava_node_to_event($node);	
//var_dump($event);//
if(isset($event) && !empty($event)):
  drupal_set_title($event['name']);

  $path = isset($_GET['q']) ? $_GET['q'] : '<front>';
  $url = url($path, array('absolute' => TRUE));
  $base_path = $GLOBALS['base_path'];
  $back_button_url = 'uritused';
  if ($event['type'] == 'huvitegevus') {
    $back_button_url = 'huvitegevused';
  }

  global $user;
  $show_node_edit_link = false;
  $allowed_users = array();
  $allowed_users[] = $node->uid;
  if(isset($node->field_users_ref['und'])) {
    foreach($node->field_users_ref['und'] as $key => $value) {
      $allowed_users[] = $value['uid'];
    }
  }
  if(in_array($user->uid, $allowed_users)) {
    $show_node_edit_link = true;
    $node_edit_link =  '<a href="' . $base_path . 'node/' . $node->nid . '/edit">' . t('Edit event') . '</a>';
  }

  ?>

  <article class="event">

    <div class="page-meta">
      <div class="meta-left">
        <div class="back-button">
          <?php print l(t('Back to search'), $back_button_url); ?>
        </div>
      </div>

      <div class="meta-right">
        <?php if($show_node_edit_link): ?>
          <div class="node-edit-link">
            <?php print $node_edit_link; ?>
          </div>
        <?php endif; ?>
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
      <?php
      if($node->status == 0) {
        print '<div class="hidden-event-notice">' . t('This event is currently hidden.') . ' ' . $node_edit_link . ' ' . t('and uncheck "Hidden event" to publish it.') . '</div>';
      }
      ?>

      <div class="page-content-left">

        <?php if(isset($node->field_gallery['und'][0]['filename'])): ?>
          <div>
            <a class="colorbox" href="<?php print image_style_url('big_popup', $node->field_gallery['und'][0]['filename']); ?>">
              <img src="<?php print image_style_url('event_main_image', $node->field_gallery['und'][0]['filename']); ?>" />
            </a>
          </div>
        <?php else: ?>
          <?php if($event['hasimage']): ?>
            <?php if(isset($event['image']) && !empty($event['image'])): ?>
              <div>
                <a class="colorbox" href="<?php print $event['image']; ?>&w=600&ext=.jpg">
                  <img src="<?php print $event['image']; ?>" />
                </a>
              </div>
            <?php endif; ?>
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

        <h1><?php print $event['name'];?></h1>

        <?php if(isset($event['ticketurl']) && !empty($event['ticketurl'])): ?>
        <div class="buymain">

          <div class="buy"><a href="#" class="buy-link"><?php print t('Buy ticket'); ?></a></div>

          <div id="ticketmenu" class="buymenu">
            <ul>
            <?php foreach($event['ticketurl'] as $buy_link): ?>
              <li><?php print $buy_link; ?></li>
            <?php endforeach; ?>
            </ul>
          </div>

        </div>
        <?php endif; ?>

        <?php if(isset($event['schedule']) && !empty($event['schedule'])): ?>
        <div class="event-schedule">
          <?php //TODO: Better array filtering with time.
            // Not working due to week day being first in the time field
            asort($event['schedule']);
            $rows = 0;
            $shown_rows = 10; // Rows to show before hiding the rest at first load
          ?>		  
          <?php foreach($event['schedule'] as $schedule_item): ?>
            <?php if(isset($schedule_item['time'])): ?>
            <?php $rows++; ?>
            <div class="schedule-item<?php if($rows > $shown_rows) {print ' schedule-hidden';} ?>">

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
          <?php if($rows > $shown_rows): ?>
            <div class="schedule-show-all">
              <?php print(t('Show all')); ?>
            </div>
          <?php endif; ?>
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
          <?php //print_r($content['field_description']); ?>
          <div class="event-description">
		  
		  <?php print(kuhuminna_utils_linkify($event['description'])); ?>
          </div>
        <?php endif; ?>
		
		<div class="event-korraldaja">
		 <?php //Korraldaja 
		  if(isset($event['korraldaja']) && !empty($event['korraldaja'])): ?>
			<?php foreach($event['korraldaja'] as $korraldaja_item): ?>
			<?php print("<b>Korraldaja</b><p>"); ?>
		  	<?php print($korraldaja_item['name'] . ", "); ?>
		  	<?php print($korraldaja_item['email']); ?>
			<?php print("<p>kontakttelefon: "); ?>
			<?php print($korraldaja_item['phone']); ?>
			</div>
		  <?php endforeach; ?>
		    <?php endif; ?>

        <?php if(isset($node->field_videos)): ?>
          <?php print render($content['field_videos']); ?>
        <?php endif; ?>

        <?php if(isset($node->field_gallery['und'][1])): ?>
          <?php print render($content['field_gallery']); ?>
        <?php endif; ?>

        <?php if(isset($event['main_event'])): ?>
          <div class="main-events">
            <h2 class="main-event-title"><?php print(t('Main event')); ?></h2>
            <a class="main-event" href="<?php print $event['main_event']['path']; ?>"><?php print $event['main_event']['title']; ?> »</a>
          </div>
        <?php endif; ?>

        <?php if(isset($event['sub_events'])): ?>
          <div class="sub-events">
            <h2 class="sub-event-title"><?php print(t('Sub-events')); ?></h2>
            <?php foreach($event['sub_events'] as $key => $sub_event) { ?>
              <a class="sub-event" href="<?php print $sub_event['path']; ?>"><?php print $sub_event['title']; ?> »</a>
            <?php } ?>
          </div>
        <?php endif; ?>

      </div>
    </div>
  </article>

<?php endif; ?>
