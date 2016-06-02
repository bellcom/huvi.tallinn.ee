<?php
$base_path = $GLOBALS['base_path'];
$c_uid = $c_email = '';
$c_page = explode('/', $_SERVER[REQUEST_URI])[1];
$c_page = explode('?', $c_page)[0];
if($_GET['uid']) {
  $c_user = user_load_by_name($_GET['uid']);
}
if(!$c_user && $_GET['email']) {
  $c_user = user_load_by_mail($_GET['email']);
}
if(!$c_user) {
  if($c_page == 'user') {
    $c_user = user_load(explode('/', $_SERVER[REQUEST_URI])[2]);
  }
}
if($c_user) {
  ?>

  <div id="block-block-<?php print $block->delta; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="block__content">
      <ul class="user-custom-menu">
        <li <?php if($c_page == 'user'){ print 'class="active-trail"'; } ?>>
          <a href="<?php print $base_path . 'user/' . $c_user->uid; ?>/edit">Andmed</a>
        </li>
        <li <?php //if($c_page == 'otsing-kasutaja-uritused'){ print 'class="active-trail"'; } ?>>
          <a href="<?php print $base_path . 'otsing-kasutaja-uritused?uid=' . $c_user->name; ?>">Loodud üritused</a>
        </li>
        <li <?php if($c_page == 'saada-e-mail'){ print 'class="active-trail"'; } ?>>
          <a href="<?php print $base_path . 'saada-e-mail?email=' . $c_user->mail; ?>">Saada e-mail</a>
        </li>
      </ul>
  	</div>
  </div>

  <?php
}
