<?php
$base_path = $GLOBALS['base_path'];
$button_link = $base_path . 'user/login';
$req_path = request_path();
if(!in_array('anonymous user', $user->roles)) {
	$button_link = $base_path . 'lisa';
}
?>

<div id="block-block-<?php print $block->delta; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <h2 class="block__title"><?php print $block->title; ?></h2>
  <div class="block__content">
    <p><?php print t('Entering is easy and takes little time!'); ?>
        <a class="button" href="<?php print $button_link; ?>"><?php print t(kuhuminna_utils_btn_lisa_text($req_path,'Lisa oma üritus','Lisa oma huvitegevus'));?></a>
    </p>
	</div>
</div>
