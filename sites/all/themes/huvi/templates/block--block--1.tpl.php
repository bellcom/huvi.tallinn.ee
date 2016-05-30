<?php
$button_link = '/user/login';
if(!in_array('anonymous user', $user->roles)) {
  $button_link = '/lisa';
}
?>

<div id="block-block-<?php print $block->delta; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <h2 class="block__title"><?php print $block->title; ?></h2>
  <div class="block__content">
    <p><?php print t('Entering is easy and takes little time!'); ?>
      <a class="button" href="<?php print $button_link; ?>"><?php print t('Add own event!'); ?></a>
    </p>
	</div>
</div>
