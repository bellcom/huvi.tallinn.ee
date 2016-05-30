<div<?php print $attributes; ?>>
  <header class="l-header" role="banner">
    <!--<div class="header-top">
    <div class="top-left">
      <div class="toplinks">
        <a href="" class="open-accessibility button-top">Vaegnägijatele</a>
      </div>
      <div class="textsize button-top" id="header_right">
        <a class="small active" href="javascript:void(0);">a</a>
        <a class="normal" href="javascript:void(0);">a</a>
        <a class="large" href="javascript:void(0);">a</a>
      </div>
    </div>
    <div class="top-right">

    </div>
  </div>-->

		<div class="top-bar">
			<div class="top-bar-left"></div>

			<div class="top-bar-right">
				<?php print render($page['top_bar_right']); ?>
			</div>
		</div>

    <div class="l-branding">
      <?php if ($logo): ?>
        <?php if(!empty($user->roles) && in_array('manager', $user->roles)) {
           $front_page = $front_page . '?' . rand(1000,9999);
        } ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo"><?php print $site_name; ?></a>
      <?php endif; ?>
    </div>

    <div class="l-navigation">
      <?php print render($page['navigation']); ?>
      <?php print $switcher_link; ?>
    </div>

    <div class="l-section-illustration">
      <div class="section-illustration event-section-illustration"></div>
    </div>

    <?php print render($page['header']); ?>
  </header>

  <div class="l-main">
    <div class="l-content" role="main">
      <?php print render($page['highlighted']); ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>
  </div>

  <footer class="l-footer" role="contentinfo">

    <div class="l-footer--top-wrapper">
      <div class="l-footer--top-container">
        <!--<a class="footer-logo" href="http://tallinn.ee">Tallinn</a>-->
      </div>
    </div>

    <div class="l-footer--main-wrapper">
      <div class="l-footer--main-container">
        <?php print render($page['footer_main_first']); ?>
        <?php print render($page['footer_main_second']); ?>
        <?php print render($page['footer_main_third']); ?>
        <?php print render($page['footer_main_fourth']); ?>
      </div>
    </div>

    <div class="l-footer--bottom-wrapper">
      <div class="l-footer--bottom-container">
        <div class="l-footer--bottom-container">
          <div class="l-footer-bottom">
            <?php print render($page['footer_bottom']); ?>
          </div>
          <a class="footer-fb-logo" href="https://www.facebook.com/tallinntana">Tallinn Täna</a>
          <a class="footer-logo" href="http://tallinn.ee">Tallinn</a>
          <div class="copyright"><p>&copy; <?php echo date("Y"); ?> Tallinna Linnakantselei</p></div>
        </div>

      </div>
    </div>

  </footer>
</div>
