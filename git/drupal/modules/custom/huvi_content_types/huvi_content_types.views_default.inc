<?php
/**
 * @file
 * huvi_content_types.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function huvi_content_types_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'advertisement';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Advertisement';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advertisement';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'banner';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'event_advertisement' => 'event_advertisement',
    'activities_advertisement' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advertisement' => 'advertisement',
  );

  /* Display: Ad Small V */
  $handler = $view->new_display('block', 'Ad Small V', 'block_0');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advertisement' => 'advertisement',
  );
  /* Filter criterion: Content: Suurus (field_adv_size) */
  $handler->display->display_options['filters']['field_adv_size_value']['id'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['table'] = 'field_data_field_adv_size';
  $handler->display->display_options['filters']['field_adv_size_value']['field'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['value'] = array(
    'small' => 'small',
  );
  /* Filter criterion: Content: Näita lehel (field_show_on_page) */
  $handler->display->display_options['filters']['field_show_on_page_value']['id'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['table'] = 'field_data_field_show_on_page';
  $handler->display->display_options['filters']['field_show_on_page_value']['field'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['value'] = array(
    'uritused' => 'uritused',
  );

  /* Display: Activities advertisement */
  $handler = $view->new_display('block', 'Activities advertisement', 'activities_advertisement_block');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'activities_advertisement' => 'activities_advertisement',
    'event_advertisement' => 0,
  );

  /* Display: Event advertisement backup */
  $handler = $view->new_display('block', 'Event advertisement backup', 'block_1');
  $handler->display->display_options['enabled'] = FALSE;

  /* Display: Ad Small K */
  $handler = $view->new_display('block', 'Ad Small K', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advertisement' => 'advertisement',
  );
  /* Filter criterion: Content: Suurus (field_adv_size) */
  $handler->display->display_options['filters']['field_adv_size_value']['id'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['table'] = 'field_data_field_adv_size';
  $handler->display->display_options['filters']['field_adv_size_value']['field'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['value'] = array(
    'small' => 'small',
  );
  /* Filter criterion: Content: Näita lehel (field_show_on_page) */
  $handler->display->display_options['filters']['field_show_on_page_value']['id'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['table'] = 'field_data_field_show_on_page';
  $handler->display->display_options['filters']['field_show_on_page_value']['field'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['value'] = array(
    'uritused' => 'uritused',
  );

  /* Display: Ad Small P */
  $handler = $view->new_display('block', 'Ad Small P', 'block_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advertisement' => 'advertisement',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_position_value']['id'] = 'field_position_value';
  $handler->display->display_options['filters']['field_position_value']['table'] = 'field_data_field_position';
  $handler->display->display_options['filters']['field_position_value']['field'] = 'field_position_value';
  $handler->display->display_options['filters']['field_position_value']['operator'] = 'or';
  $handler->display->display_options['filters']['field_position_value']['value'] = array(
    3 => '3',
  );
  /* Filter criterion: Content: Suurus (field_adv_size) */
  $handler->display->display_options['filters']['field_adv_size_value']['id'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['table'] = 'field_data_field_adv_size';
  $handler->display->display_options['filters']['field_adv_size_value']['field'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['value'] = array(
    'small' => 'small',
  );
  /* Filter criterion: Content: Näita lehel (field_show_on_page) */
  $handler->display->display_options['filters']['field_show_on_page_value']['id'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['table'] = 'field_data_field_show_on_page';
  $handler->display->display_options['filters']['field_show_on_page_value']['field'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['value'] = array(
    'uritused' => 'uritused',
  );

  /* Display: Ad H Small V */
  $handler = $view->new_display('block', 'Ad H Small V', 'block_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advertisement' => 'advertisement',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_position_value']['id'] = 'field_position_value';
  $handler->display->display_options['filters']['field_position_value']['table'] = 'field_data_field_position';
  $handler->display->display_options['filters']['field_position_value']['field'] = 'field_position_value';
  $handler->display->display_options['filters']['field_position_value']['operator'] = 'or';
  $handler->display->display_options['filters']['field_position_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Suurus (field_adv_size) */
  $handler->display->display_options['filters']['field_adv_size_value']['id'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['table'] = 'field_data_field_adv_size';
  $handler->display->display_options['filters']['field_adv_size_value']['field'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['value'] = array(
    'small' => 'small',
  );
  /* Filter criterion: Content: Näita lehel (field_show_on_page) */
  $handler->display->display_options['filters']['field_show_on_page_value']['id'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['table'] = 'field_data_field_show_on_page';
  $handler->display->display_options['filters']['field_show_on_page_value']['field'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['value'] = array(
    'huvitegevused' => 'huvitegevused',
  );

  /* Display: Ad H Small K */
  $handler = $view->new_display('block', 'Ad H Small K', 'block_5');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advertisement' => 'advertisement',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_position_value']['id'] = 'field_position_value';
  $handler->display->display_options['filters']['field_position_value']['table'] = 'field_data_field_position';
  $handler->display->display_options['filters']['field_position_value']['field'] = 'field_position_value';
  $handler->display->display_options['filters']['field_position_value']['operator'] = 'or';
  $handler->display->display_options['filters']['field_position_value']['value'] = array(
    2 => '2',
  );
  /* Filter criterion: Content: Suurus (field_adv_size) */
  $handler->display->display_options['filters']['field_adv_size_value']['id'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['table'] = 'field_data_field_adv_size';
  $handler->display->display_options['filters']['field_adv_size_value']['field'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['value'] = array(
    'small' => 'small',
  );
  /* Filter criterion: Content: Näita lehel (field_show_on_page) */
  $handler->display->display_options['filters']['field_show_on_page_value']['id'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['table'] = 'field_data_field_show_on_page';
  $handler->display->display_options['filters']['field_show_on_page_value']['field'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['value'] = array(
    'huvitegevused' => 'huvitegevused',
  );

  /* Display: Ad H Small P */
  $handler = $view->new_display('block', 'Ad H Small P', 'block_6');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advertisement' => 'advertisement',
  );
  /* Filter criterion: Content: Suurus (field_adv_size) */
  $handler->display->display_options['filters']['field_adv_size_value']['id'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['table'] = 'field_data_field_adv_size';
  $handler->display->display_options['filters']['field_adv_size_value']['field'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['value'] = array(
    'small' => 'small',
  );
  /* Filter criterion: Content: Näita lehel (field_show_on_page) */
  $handler->display->display_options['filters']['field_show_on_page_value']['id'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['table'] = 'field_data_field_show_on_page';
  $handler->display->display_options['filters']['field_show_on_page_value']['field'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['value'] = array(
    'huvitegevused' => 'huvitegevused',
  );

  /* Display: Ad Big */
  $handler = $view->new_display('block', 'Ad Big', 'block_7');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_adv_link' => 0,
    'field_adv_image' => 0,
    'counter' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '2';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['vscc_controls_pause'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['hide_on_single_slide'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'counter' => 'counter',
    'field_adv_link' => 0,
    'field_adv_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['vscc_controls_pause'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['pause_on_click'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'advertisement:block_9';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_adv_link']['id'] = 'field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['table'] = 'field_data_field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['field'] = 'field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['label'] = '';
  $handler->display->display_options['fields']['field_adv_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_adv_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adv_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_adv_link']['type'] = 'link_plain';
  /* Field: Content: Bänneri pildifail */
  $handler->display->display_options['fields']['field_adv_image']['id'] = 'field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['table'] = 'field_data_field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['field'] = 'field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['label'] = '';
  $handler->display->display_options['fields']['field_adv_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_adv_image']['alter']['path'] = '[field_adv_link]';
  $handler->display->display_options['fields']['field_adv_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adv_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_adv_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '<span class="pager-item">&nbsp;</span>';
  $handler->display->display_options['fields']['counter']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['path'] = '#pager';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advertisement' => 'advertisement',
  );
  /* Filter criterion: Content: Suurus (field_adv_size) */
  $handler->display->display_options['filters']['field_adv_size_value']['id'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['table'] = 'field_data_field_adv_size';
  $handler->display->display_options['filters']['field_adv_size_value']['field'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['value'] = array(
    'large' => 'large',
  );
  /* Filter criterion: Content: Näita lehel (field_show_on_page) */
  $handler->display->display_options['filters']['field_show_on_page_value']['id'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['table'] = 'field_data_field_show_on_page';
  $handler->display->display_options['filters']['field_show_on_page_value']['field'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['value'] = array(
    'uritused' => 'uritused',
  );

  /* Display: Ad H Big */
  $handler = $view->new_display('block', 'Ad H Big', 'block_8');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_adv_link' => 0,
    'field_adv_image' => 0,
    'counter' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'vscc_controls';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['vscc_controls_pause'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'counter' => 'counter',
    'field_adv_link' => 0,
    'field_adv_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_hover'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['hide_on_single_slide'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['vscc_controls_pause'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'advertisement:block_10';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_adv_link']['id'] = 'field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['table'] = 'field_data_field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['field'] = 'field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['label'] = '';
  $handler->display->display_options['fields']['field_adv_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_adv_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adv_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_adv_link']['type'] = 'link_plain';
  /* Field: Content: Bänneri pildifail */
  $handler->display->display_options['fields']['field_adv_image']['id'] = 'field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['table'] = 'field_data_field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['field'] = 'field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['label'] = '';
  $handler->display->display_options['fields']['field_adv_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_adv_image']['alter']['path'] = '[field_adv_link]';
  $handler->display->display_options['fields']['field_adv_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adv_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_adv_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '<span class="pager-item">&nbsp;</span>';
  $handler->display->display_options['fields']['counter']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['path'] = '#pager';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advertisement' => 'advertisement',
  );
  /* Filter criterion: Content: Suurus (field_adv_size) */
  $handler->display->display_options['filters']['field_adv_size_value']['id'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['table'] = 'field_data_field_adv_size';
  $handler->display->display_options['filters']['field_adv_size_value']['field'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['value'] = array(
    'large' => 'large',
  );
  /* Filter criterion: Content: Näita lehel (field_show_on_page) */
  $handler->display->display_options['filters']['field_show_on_page_value']['id'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['table'] = 'field_data_field_show_on_page';
  $handler->display->display_options['filters']['field_show_on_page_value']['field'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['value'] = array(
    'huvitegevused' => 'huvitegevused',
  );

  /* Display: Ad Small 3 */
  $handler = $view->new_display('block', 'Ad Small 3', 'block_9');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_adv_link' => 0,
    'field_adv_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_adv_link' => 0,
    'field_adv_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'advertisement:block_7';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_adv_link']['id'] = 'field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['table'] = 'field_data_field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['field'] = 'field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['label'] = '';
  $handler->display->display_options['fields']['field_adv_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_adv_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adv_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_adv_link']['type'] = 'link_plain';
  /* Field: Content: Bänneri pildifail */
  $handler->display->display_options['fields']['field_adv_image']['id'] = 'field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['table'] = 'field_data_field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['field'] = 'field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['label'] = '';
  $handler->display->display_options['fields']['field_adv_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_adv_image']['alter']['path'] = '[field_adv_link]';
  $handler->display->display_options['fields']['field_adv_image']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_adv_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adv_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_adv_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advertisement' => 'advertisement',
  );
  /* Filter criterion: Content: Suurus (field_adv_size) */
  $handler->display->display_options['filters']['field_adv_size_value']['id'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['table'] = 'field_data_field_adv_size';
  $handler->display->display_options['filters']['field_adv_size_value']['field'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['value'] = array(
    'small' => 'small',
  );
  /* Filter criterion: Content: Näita lehel (field_show_on_page) */
  $handler->display->display_options['filters']['field_show_on_page_value']['id'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['table'] = 'field_data_field_show_on_page';
  $handler->display->display_options['filters']['field_show_on_page_value']['field'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['value'] = array(
    'uritused' => 'uritused',
  );

  /* Display: Ad H Small 3 */
  $handler = $view->new_display('block', 'Ad H Small 3', 'block_10');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'advertisement:block_8';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_adv_link']['id'] = 'field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['table'] = 'field_data_field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['field'] = 'field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['label'] = '';
  $handler->display->display_options['fields']['field_adv_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_adv_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adv_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_adv_link']['type'] = 'link_plain';
  /* Field: Content: Bänneri pildifail */
  $handler->display->display_options['fields']['field_adv_image']['id'] = 'field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['table'] = 'field_data_field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['field'] = 'field_adv_image';
  $handler->display->display_options['fields']['field_adv_image']['label'] = '';
  $handler->display->display_options['fields']['field_adv_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_adv_image']['alter']['path'] = '[field_adv_link]';
  $handler->display->display_options['fields']['field_adv_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adv_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_adv_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advertisement' => 'advertisement',
  );
  /* Filter criterion: Content: Suurus (field_adv_size) */
  $handler->display->display_options['filters']['field_adv_size_value']['id'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['table'] = 'field_data_field_adv_size';
  $handler->display->display_options['filters']['field_adv_size_value']['field'] = 'field_adv_size_value';
  $handler->display->display_options['filters']['field_adv_size_value']['value'] = array(
    'small' => 'small',
  );
  /* Filter criterion: Content: Näita lehel (field_show_on_page) */
  $handler->display->display_options['filters']['field_show_on_page_value']['id'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['table'] = 'field_data_field_show_on_page';
  $handler->display->display_options['filters']['field_show_on_page_value']['field'] = 'field_show_on_page_value';
  $handler->display->display_options['filters']['field_show_on_page_value']['value'] = array(
    'huvitegevused' => 'huvitegevused',
  );
  $export['advertisement'] = $view;

  $view = new view();
  $view->name = 'slide_show';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'slide_show';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'slide_show';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_pildid_slideshow' => 0,
    'counter' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'counter' => 'counter',
    'field_pildid_slideshow' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['hide_on_single_slide'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['fixed_height'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Pildid Slideshow */
  $handler->display->display_options['fields']['field_pildid_slideshow']['id'] = 'field_pildid_slideshow';
  $handler->display->display_options['fields']['field_pildid_slideshow']['table'] = 'field_data_field_pildid_slideshow';
  $handler->display->display_options['fields']['field_pildid_slideshow']['field'] = 'field_pildid_slideshow';
  $handler->display->display_options['fields']['field_pildid_slideshow']['label'] = '';
  $handler->display->display_options['fields']['field_pildid_slideshow']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pildid_slideshow']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pildid_slideshow']['settings'] = array(
    'image_style' => '900x200',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_pildid_slideshow']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_pildid_slideshow']['delta_offset'] = '0';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['slide_show'] = $view;

  return $export;
}
