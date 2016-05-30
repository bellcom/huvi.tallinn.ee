<?php
if($user->uid) {
  ?>

  <div id="block-block-<?php print $block->delta; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="block__content">
      <p>
        <span class="username">
          Tere, <b><a href="/user/<?php print $user->uid; ?>/edit"><?php print $user->name; ?></a></b>
        </span>
        <span class="logout-link">
          <a href="/user/logout"><?php print t('Log out'); ?></a>
        </span>
      </p>
  	</div>
  </div>
  <?php
}
