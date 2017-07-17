<?php
/**
 * @file
 * huvi_rss_feeds.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function huvi_rss_feeds_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events_rss_feeds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Events rss feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'huvi.tallinn.ee RSS feeds';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Otsi';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista valikud';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteeri';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_categories_event_value_i18n' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_schedule_city_id_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_isfree_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '55';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« esimene';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ eelmine';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'järgmine ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'viimane »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_schedule_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'event-item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'event-group';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Kahjuks ei leitud ühtegi üritust antud kriteeriumitega.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Field collection item: Entity with the Toimumise aeg ja koht (field_schedule) */
  $handler->display->display_options['relationships']['field_schedule_node']['id'] = 'field_schedule_node';
  $handler->display->display_options['relationships']['field_schedule_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_schedule_node']['field'] = 'field_schedule_node';
  $handler->display->display_options['relationships']['field_schedule_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  /* Field: Field collection item: Organisatsiooni nimi */
  $handler->display->display_options['fields']['field_korraldaja_nimi']['id'] = 'field_korraldaja_nimi';
  $handler->display->display_options['fields']['field_korraldaja_nimi']['table'] = 'field_data_field_korraldaja_nimi';
  $handler->display->display_options['fields']['field_korraldaja_nimi']['field'] = 'field_korraldaja_nimi';
  $handler->display->display_options['fields']['field_korraldaja_nimi']['label'] = '';
  $handler->display->display_options['fields']['field_korraldaja_nimi']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_schedule_node';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_value']['expose']['operator_id'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['label'] = 'Tüüp (field_type)';
  $handler->display->display_options['filters']['field_type_value']['expose']['operator'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['field_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    'all' => 'all',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Märgi, kui üritus on tasuta (field_isfree)';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'is_free';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa (field_schedule_city_id)';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Ürituse kategooriad (field_categories_event) */
  $handler->display->display_options['filters']['field_categories_event_value']['id'] = 'field_categories_event_value';
  $handler->display->display_options['filters']['field_categories_event_value']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['filters']['field_categories_event_value']['field'] = 'field_categories_event_value';
  $handler->display->display_options['filters']['field_categories_event_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_event_value']['group'] = 2;
  $handler->display->display_options['filters']['field_categories_event_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['operator_id'] = 'field_categories_event_value_op';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['label'] = 'Ürituse kategooriad (field_categories_event)';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['operator'] = 'field_categories_event_value_op';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['identifier'] = 'event_category';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_event_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Huvitegevuse kategooriad (field_categories_activity) */
  $handler->display->display_options['filters']['field_categories_activity_value']['id'] = 'field_categories_activity_value';
  $handler->display->display_options['filters']['field_categories_activity_value']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['filters']['field_categories_activity_value']['field'] = 'field_categories_activity_value';
  $handler->display->display_options['filters']['field_categories_activity_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_activity_value']['group'] = 2;
  $handler->display->display_options['filters']['field_categories_activity_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['operator_id'] = 'field_categories_activity_value_op';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['label'] = 'Huvitegevuse kategooriad (field_categories_activity)';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['operator'] = 'field_categories_activity_value_op';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['identifier'] = 'activity_category';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_activity_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'allwords';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Combine fields filter';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'text';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'now - 5 minute';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feeds');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'path';
  $handler->display->display_options['row_options']['description_field'] = 'field_description';
  $handler->display->display_options['row_options']['creator_field'] = 'field_korraldaja_nimi';
  $handler->display->display_options['row_options']['date_field'] = 'field_schedule_date';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'path',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_value']['expose']['operator_id'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['label'] = 'Tüüp (field_type)';
  $handler->display->display_options['filters']['field_type_value']['expose']['operator'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['field_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    'all' => 'all',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Märgi, kui üritus on tasuta (field_isfree)';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'is_free';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa (field_schedule_city_id)';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Ürituse kategooriad (field_categories_event) */
  $handler->display->display_options['filters']['field_categories_event_value']['id'] = 'field_categories_event_value';
  $handler->display->display_options['filters']['field_categories_event_value']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['filters']['field_categories_event_value']['field'] = 'field_categories_event_value';
  $handler->display->display_options['filters']['field_categories_event_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_event_value']['group'] = 2;
  $handler->display->display_options['filters']['field_categories_event_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['operator_id'] = 'field_categories_event_value_op';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['label'] = 'Ürituse kategooriad (field_categories_event)';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['operator'] = 'field_categories_event_value_op';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['identifier'] = 'event_category';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_event_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Huvitegevuse kategooriad (field_categories_activity) */
  $handler->display->display_options['filters']['field_categories_activity_value']['id'] = 'field_categories_activity_value';
  $handler->display->display_options['filters']['field_categories_activity_value']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['filters']['field_categories_activity_value']['field'] = 'field_categories_activity_value';
  $handler->display->display_options['filters']['field_categories_activity_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_activity_value']['group'] = 2;
  $handler->display->display_options['filters']['field_categories_activity_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['operator_id'] = 'field_categories_activity_value_op';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['label'] = 'Huvitegevuse kategooriad (field_categories_activity)';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['operator'] = 'field_categories_activity_value_op';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['identifier'] = 'activity_category';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_activity_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'allwords';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Combine fields filter';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'text';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_description' => 'field_description',
  );
  $handler->display->display_options['path'] = 'event-rss-feed1';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $export['events_rss_feeds'] = $view;

  $view = new view();
  $view->name = 'events_schedule_rss_feeds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Event schedule RSS feeds';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_schedule_node';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feeds_schedule');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'huvi.tallinn.ee RSS feeds';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
  );
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'path';
  $handler->display->display_options['row_options']['description_field'] = 'field_description';
  $handler->display->display_options['row_options']['creator_field'] = 'field_korraldaja_nimi';
  $handler->display->display_options['row_options']['date_field'] = 'field_schedule_date';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'path',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the Toimumise aeg ja koht (field_schedule) */
  $handler->display->display_options['relationships']['field_schedule_node']['id'] = 'field_schedule_node';
  $handler->display->display_options['relationships']['field_schedule_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_schedule_node']['field'] = 'field_schedule_node';
  $handler->display->display_options['relationships']['field_schedule_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_adv_link']['id'] = 'field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['table'] = 'field_data_field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['field'] = 'field_adv_link';
  $handler->display->display_options['fields']['field_adv_link']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_adv_link']['label'] = '';
  $handler->display->display_options['fields']['field_adv_link']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_adv_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_adv_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_adv_link']['click_sort_column'] = 'url';
  /* Field: Field collection item: Organisatsiooni nimi */
  $handler->display->display_options['fields']['field_korraldaja_nimi']['id'] = 'field_korraldaja_nimi';
  $handler->display->display_options['fields']['field_korraldaja_nimi']['table'] = 'field_data_field_korraldaja_nimi';
  $handler->display->display_options['fields']['field_korraldaja_nimi']['field'] = 'field_korraldaja_nimi';
  $handler->display->display_options['fields']['field_korraldaja_nimi']['label'] = '';
  $handler->display->display_options['fields']['field_korraldaja_nimi']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_schedule_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_schedule_node';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_value']['expose']['operator_id'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['label'] = 'Tüüp (field_type)';
  $handler->display->display_options['filters']['field_type_value']['expose']['operator'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['field_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['value'] = array(
    2944187 => '2944187',
    2944191 => '2944191',
    2944189 => '2944189',
    2944190 => '2944190',
    2944193 => '2944193',
    2944194 => '2944194',
    2920234 => '2920234',
    2944195 => '2944195',
  );
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa (field_schedule_city_id)';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Märgi, kui üritus on tasuta (field_isfree)';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'is_free';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'now - 5 minute';
  $handler->display->display_options['filters']['field_schedule_date_value']['year_range'] = '-0:+0';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Combine fields filter';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'text';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Ürituse kategooriad (field_categories_event) */
  $handler->display->display_options['filters']['field_categories_event_value']['id'] = 'field_categories_event_value';
  $handler->display->display_options['filters']['field_categories_event_value']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['filters']['field_categories_event_value']['field'] = 'field_categories_event_value';
  $handler->display->display_options['filters']['field_categories_event_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_event_value']['group'] = 2;
  $handler->display->display_options['filters']['field_categories_event_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['operator_id'] = 'field_categories_event_value_op';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['label'] = 'Ürituse kategooriad (field_categories_event)';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['operator'] = 'field_categories_event_value_op';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['identifier'] = 'event_category';
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_event_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Huvitegevuse kategooriad (field_categories_activity) */
  $handler->display->display_options['filters']['field_categories_activity_value']['id'] = 'field_categories_activity_value';
  $handler->display->display_options['filters']['field_categories_activity_value']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['filters']['field_categories_activity_value']['field'] = 'field_categories_activity_value';
  $handler->display->display_options['filters']['field_categories_activity_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_activity_value']['group'] = 2;
  $handler->display->display_options['filters']['field_categories_activity_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['operator_id'] = 'field_categories_activity_value_op';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['label'] = 'Huvitegevuse kategooriad (field_categories_activity)';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['operator'] = 'field_categories_activity_value_op';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['identifier'] = 'activity_category';
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_activity_value']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['path'] = 'event-rss-feed';
  $handler->display->display_options['sitename_title'] = 0;
  $export['events_schedule_rss_feeds'] = $view;

  return $export;
}
