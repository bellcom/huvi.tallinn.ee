<?php
$base_path = $GLOBALS['base_path'];
$button_link = $base_path . 'user/login';
if(!in_array('anonymous user', $user->roles)) {
	$button_link = $base_path . 'lisa';
}
?>

<div<?php print $attributes; ?>>
  <a class="landing-user-login" href="<?php print $button_link; ?>"><?php print t('Lisa üritus'); ?></a>
  <header class="l-header" role="banner">
	<div class="l-branding">
      <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo"><?php print $site_name; ?></a>
      <?php endif; ?>
			<div class="landing-description"><?php print t('Leia kõik mis Tallinnas toimub!'); ?></div>
      <div class="logo-branding"></div>
    </div>
  </header>

  <div class="l-main">
    <div class="sidebar-first-wrapper">
      <?php //print render($page['sidebar_first']); ?>
      <?php
        $sidebar_nid = 1384;
        $sidebar_content = node_load($sidebar_nid);
      ?>
      <div class="background-pattern"></div>
      <div class="landing-box">
        <div class="landing-box-image">
          <img src="sites/default/files/<?php print $sidebar_content->field_frontpage_image['und'][0]['filename']; ?>"/>
          <?php if(in_array('administrator', $user->roles) || in_array('manager', $user->roles)): ?>
            <a class="landing-sidebar-edit-link" href="node/<?php print $sidebar_nid; ?>/edit"><?php print t('edit'); ?></a>
          <?php endif; ?>
        </div>
        <div class="landing-box-content">
          <!--<h2>Üritused</h2>-->
          <?php print $sidebar_content->body['und'][0]['safe_value']; ?>
          <?php /*
          <ul class="landing-box-listing">
            <li>Muusika</li>
            <li>Etendused</li>
            <li>Näitused</li>
            <li>Muuseumid</li>
            <li>Messid</li>
            <li>Laadad</li>
            <li>Sport</li>
            <li>Kino</li>
            <li>Pidu ja klubid</li>
          </ul>
          */ ?>
          <?php print l($sidebar_content->title, 'uritused', array('attributes' => array('class' => array('landing-box-link', 'landing-box-link-desk')))); ?>
					<?php print l($sidebar_content->title, 'uritused', array('attributes' => array('class' => array('landing-box-link', 'landing-box-link-mobile')))); ?>
        </div>
      </div>


    </div>

    <div class="sidebar-second-wrapper">
      <?php //print render($page['sidebar_second']); ?>
      <?php
        $sidebar_nid = 1385;
        $sidebar_content = node_load($sidebar_nid);
      ?>
      <div class="background-pattern"></div>
      <div class="landing-box">
        <div class="landing-box-image">
          <img src="sites/default/files/<?php print $sidebar_content->field_frontpage_image['und'][0]['filename']; ?>"/>
          <?php if(in_array('administrator', $user->roles) || in_array('manager', $user->roles)): ?>
            <a class="landing-sidebar-edit-link" href="node/<?php print $sidebar_nid; ?>/edit"><?php print t('edit'); ?></a>
          <?php endif; ?>
        </div>
        <div class="landing-box-content">
          <!--<h2>Huvitegevused</h2>-->
          <?php print $sidebar_content->body['und'][0]['safe_value']; ?>
          <?php /*
          <ul class="landing-box-listing">
            <li>Muusika</li>
            <li>Kunst</li>
            <li>Käsitöö</li>
            <li>Tantsimine</li>
            <li>Sport</li>
            <li>Tehnika</li>
            <li>Keeleõpe</li>
            <li>Koolitused</li>
            <li>Kursused</li>
          </ul>
          */ ?>
          <?php print l($sidebar_content->title, 'huvitegevused', array('attributes' => array('class' => array('landing-box-link', 'landing-box-link-desk')))); ?>
					<?php print l($sidebar_content->title, 'huvitegevused', array('attributes' => array('class' => array('landing-box-link', 'landing-box-link-mobile')))); ?>
        </div>
      </div>

    </div>
  </div>
  <div class="choose"></div>
  <a class="footer-logo" href="http://tallinn.ee">Tallinn</a>
  <a class="footer-fb-logo" href="https://www.facebook.com/tallinnalinn">Tallinna linn</a>
</div>
