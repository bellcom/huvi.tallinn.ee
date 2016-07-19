<?php
/**
 * @file
 * event_listing_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function event_listing_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'event_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Event listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Üritused ülehomme';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Otsi';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühjenda väljad';
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
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
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
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$dateraw = strtotime( "today" );

$day = t(date(\'l\', $dateraw));
$date = date(\'d.m | \', $dateraw) . $day;
echo $date;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date_1']['id'] = 'field_schedule_date_1';
  $handler->display->display_options['fields']['field_schedule_date_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_class'] = 'event-group-title';
  $handler->display->display_options['fields']['field_schedule_date_1']['empty'] = '<span class="date-display-single">[php]</span>';
  $handler->display->display_options['fields']['field_schedule_date_1']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['delta_offset'] = '0';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_class'] = 'time fixwidth';
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'only_time',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'name fixwidth';
  /* Field: Content: Ürituse kategooriad */
  $handler->display->display_options['fields']['field_categories_event']['id'] = 'field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['field'] = 'field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_categories_event']['label'] = '';
  $handler->display->display_options['fields']['field_categories_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories_event']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_categories_event']['element_wrapper_class'] = 'category fixwidth';
  $handler->display->display_options['fields']['field_categories_event']['type'] = 'i18n_list_default';
  $handler->display->display_options['fields']['field_categories_event']['delta_offset'] = '0';
  /* Field: Field collection item: Asukoht */
  $handler->display->display_options['fields']['field_schedule_place']['id'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['table'] = 'field_data_field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['field'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_class'] = 'place fixwidth';
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  /* Sort criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['sorts']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['sorts']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['sorts']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
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
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'uritus' => 'uritus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Content: Ürituse kategooriad (field_categories_event) (translated) */
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['id'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['field'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator_id'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['label'] = 'Ürituse tüüp:';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['identifier'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta üritus';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value_1']['id'] = 'field_schedule_date_value_1';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value_1']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['year_range'] = '-0:+0';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if((intval($data->field_data_field_schedule_date_field_schedule_date_value2) - intval($data->field_data_field_schedule_date_field_schedule_date_value)) > 2592000) {
  return true;
}';

  /* Display: Event */
  $handler = $view->new_display('block', 'Event', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the Toimumise aeg ja koht (field_schedule) */
  $handler->display->display_options['relationships']['field_schedule_node']['id'] = 'field_schedule_node';
  $handler->display->display_options['relationships']['field_schedule_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_schedule_node']['field'] = 'field_schedule_node';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'uritus' => 'uritus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Content: Ürituse kategooriad (field_categories_event) (translated) */
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['id'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['field'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator_id'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['label'] = 'Ürituse tüüp:';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['identifier'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta üritus';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value_1']['id'] = 'field_schedule_date_value_1';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value_1']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_schedule_date_value_1']['year_range'] = '-0:+0';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if((intval($data->field_data_field_schedule_date_field_schedule_date_value2) - intval($data->field_data_field_schedule_date_field_schedule_date_value)) > 2592000) {
return true;
}';

  /* Display: E Today */
  $handler = $view->new_display('block', 'E Today', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'uritus' => 'uritus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'tomorrow + 4 hours';
  $handler->display->display_options['filters']['field_schedule_date_value']['year_range'] = '-0:+0';
  $handler->display->display_options['filters']['field_schedule_date_value']['add_delta'] = 'yes';
  /* Filter criterion: Content: Ürituse kategooriad (field_categories_event) (translated) */
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['id'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['field'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator_id'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['label'] = 'Ürituse tüüp:';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['identifier'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta üritus';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg - end date (field_schedule_date:value2) */
  $handler->display->display_options['filters']['field_schedule_date_value2']['id'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value2']['field'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_schedule_date_value2']['add_delta'] = 'yes';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if((intval($data->field_data_field_schedule_date_field_schedule_date_value2) - intval($data->field_data_field_schedule_date_field_schedule_date_value)) > 2592000) {
  return true;
}';

  /* Display: E Tomorrow */
  $handler = $view->new_display('block', 'E Tomorrow', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$dateraw = strtotime( "tomorrow" );

$day = t(date(\'l\', $dateraw));
$date = date(\'d.m | \', $dateraw) . $day;
echo $date;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date_1']['id'] = 'field_schedule_date_1';
  $handler->display->display_options['fields']['field_schedule_date_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_class'] = 'event-group-title';
  $handler->display->display_options['fields']['field_schedule_date_1']['empty'] = '<span class="date-display-single">[php]</span>';
  $handler->display->display_options['fields']['field_schedule_date_1']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => 'tomorrow',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['delta_offset'] = '0';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_class'] = 'time fixwidth';
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'only_time',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'name fixwidth';
  /* Field: Content: Ürituse kategooriad */
  $handler->display->display_options['fields']['field_categories_event']['id'] = 'field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['field'] = 'field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_categories_event']['label'] = '';
  $handler->display->display_options['fields']['field_categories_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories_event']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_categories_event']['element_wrapper_class'] = 'category fixwidth';
  $handler->display->display_options['fields']['field_categories_event']['type'] = 'i18n_list_default';
  $handler->display->display_options['fields']['field_categories_event']['delta_offset'] = '0';
  /* Field: Field collection item: Asukoht */
  $handler->display->display_options['fields']['field_schedule_place']['id'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['table'] = 'field_data_field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['field'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_class'] = 'place fixwidth';
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'uritus' => 'uritus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['granularity'] = 'hour';
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'tomorrow +1 day 3 hours';
  $handler->display->display_options['filters']['field_schedule_date_value']['year_range'] = '-0:+0';
  $handler->display->display_options['filters']['field_schedule_date_value']['add_delta'] = 'yes';
  /* Filter criterion: Content: Ürituse kategooriad (field_categories_event) (translated) */
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['id'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['field'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator_id'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['label'] = 'Ürituse tüüp:';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['identifier'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta üritus';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg - end date (field_schedule_date:value2) */
  $handler->display->display_options['filters']['field_schedule_date_value2']['id'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value2']['field'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value2']['default_date'] = 'now +1 day';
  $handler->display->display_options['filters']['field_schedule_date_value2']['add_delta'] = 'yes';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if((intval($data->field_data_field_schedule_date_field_schedule_date_value2) - intval($data->field_data_field_schedule_date_field_schedule_date_value)) > 2592000) {
  return true;
}';

  /* Display: E F-S */
  $handler = $view->new_display('block', 'E F-S', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'php',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'event-item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'event-group';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date_1']['id'] = 'field_schedule_date_1';
  $handler->display->display_options['fields']['field_schedule_date_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_class'] = 'event-group-title';
  $handler->display->display_options['fields']['field_schedule_date_1']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['delta_offset'] = '0';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_class'] = 'time fixwidth';
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'only_time',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$dateraw = strtotime( "this friday" );

$day = t(date(\'l\', $dateraw));
$date = date(\'d.m | \', $dateraw) . $day;
$value = $data->field_field_schedule_date_1[0][\'rendered\'][\'#markup\'];
$raw = $data->field_field_schedule_date_1[0][\'raw\'][\'value\'];
if($raw >= $dateraw) {
echo $value;
}
else {
echo \'<span class="date-display-single">\'.$date.\'</span>\';
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'name fixwidth';
  /* Field: Content: Ürituse kategooriad */
  $handler->display->display_options['fields']['field_categories_event']['id'] = 'field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['field'] = 'field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_categories_event']['label'] = '';
  $handler->display->display_options['fields']['field_categories_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories_event']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_categories_event']['element_wrapper_class'] = 'category fixwidth';
  $handler->display->display_options['fields']['field_categories_event']['type'] = 'i18n_list_default';
  $handler->display->display_options['fields']['field_categories_event']['delta_offset'] = '0';
  /* Field: Field collection item: Asukoht */
  $handler->display->display_options['fields']['field_schedule_place']['id'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['table'] = 'field_data_field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['field'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_class'] = 'place fixwidth';
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'uritus' => 'uritus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['granularity'] = 'hour';
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'Monday next week + 3 hours';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_to_date'] = 'Sunday this week';
  $handler->display->display_options['filters']['field_schedule_date_value']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value']['add_delta'] = 'yes';
  /* Filter criterion: Content: Ürituse kategooriad (field_categories_event) (translated) */
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['id'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['field'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator_id'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['label'] = 'Ürituse tüüp:';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['identifier'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta üritus';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg - end date (field_schedule_date:value2) */
  $handler->display->display_options['filters']['field_schedule_date_value2']['id'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value2']['field'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value2']['default_date'] = 'Friday this week';
  $handler->display->display_options['filters']['field_schedule_date_value2']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value2']['add_delta'] = 'yes';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if((intval($data->field_data_field_schedule_date_field_schedule_date_value2) - intval($data->field_data_field_schedule_date_field_schedule_date_value)) > 2592000) {
  return true;
}';

  /* Display: E This month */
  $handler = $view->new_display('block', 'E This month', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'uritus' => 'uritus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'last day of this month';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_to_date'] = 'last day of this month';
  $handler->display->display_options['filters']['field_schedule_date_value']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value']['add_delta'] = 'yes';
  /* Filter criterion: Content: Ürituse kategooriad (field_categories_event) (translated) */
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['id'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['field'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator_id'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['label'] = 'Ürituse tüüp:';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['operator'] = 'field_categories_event_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['identifier'] = 'field_categories_event_value_i18n';
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_event_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta üritus';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg - end date (field_schedule_date:value2) */
  $handler->display->display_options['filters']['field_schedule_date_value2']['id'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value2']['field'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_schedule_date_value2']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value2']['add_delta'] = 'yes';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if((intval($data->field_data_field_schedule_date_field_schedule_date_value2) - intval($data->field_data_field_schedule_date_field_schedule_date_value)) > 2592000) {
  return true;
}';

  /* Display: E Next month */
  $handler = $view->new_display('block', 'E Next month', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'php',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'event-item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'event-group';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date_1']['id'] = 'field_schedule_date_1';
  $handler->display->display_options['fields']['field_schedule_date_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_class'] = 'event-group-title';
  $handler->display->display_options['fields']['field_schedule_date_1']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['delta_offset'] = '0';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_class'] = 'time fixwidth';
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'only_time',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$dateraw = strtotime( "first day of next month" );

$day = t(date(\'l\', $dateraw));
$date = date(\'d.m | \', $dateraw) . $day;
$value = $data->field_field_schedule_date_1[0][\'rendered\'][\'#markup\'];
$raw = $data->field_field_schedule_date_1[0][\'raw\'][\'value\'];
if($raw >= $dateraw) {
echo $value;
}
else {
echo \'<span class="date-display-single">\'.$date.\'</span>\';
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'name fixwidth';
  /* Field: Content: Ürituse kategooriad */
  $handler->display->display_options['fields']['field_categories_event']['id'] = 'field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['table'] = 'field_data_field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['field'] = 'field_categories_event';
  $handler->display->display_options['fields']['field_categories_event']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_categories_event']['label'] = '';
  $handler->display->display_options['fields']['field_categories_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories_event']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_categories_event']['element_wrapper_class'] = 'category fixwidth';
  $handler->display->display_options['fields']['field_categories_event']['type'] = 'i18n_list_default';
  $handler->display->display_options['fields']['field_categories_event']['delta_offset'] = '0';
  /* Field: Field collection item: Asukoht */
  $handler->display->display_options['fields']['field_schedule_place']['id'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['table'] = 'field_data_field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['field'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_class'] = 'place fixwidth';
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';

  /* Display: Activity */
  $handler = $view->new_display('block', 'Activity', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Otsi';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühjenda väljad';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteeri';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_categories_activity_value_i18n' => array(
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
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$dateraw = strtotime( "today" );

$day = t(date(\'l\', $dateraw));
$date = date(\'d.m | \', $dateraw) . $day;
echo $date;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date_1']['id'] = 'field_schedule_date_1';
  $handler->display->display_options['fields']['field_schedule_date_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_class'] = 'event-group-title';
  $handler->display->display_options['fields']['field_schedule_date_1']['empty'] = '<span class="date-display-single">[php]</span>';
  $handler->display->display_options['fields']['field_schedule_date_1']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['delta_offset'] = '0';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_class'] = 'time fixwidth';
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'only_time',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'name fixwidth';
  /* Field: Content: Huvitegevuse kategooriad */
  $handler->display->display_options['fields']['field_categories_activity']['id'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['field'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_categories_activity']['label'] = '';
  $handler->display->display_options['fields']['field_categories_activity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_class'] = 'category fixwidth';
  $handler->display->display_options['fields']['field_categories_activity']['type'] = 'i18n_list_default';
  $handler->display->display_options['fields']['field_categories_activity']['delta_offset'] = '0';
  /* Field: Field collection item: Asukoht */
  $handler->display->display_options['fields']['field_schedule_place']['id'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['table'] = 'field_data_field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['field'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_class'] = 'place fixwidth';
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'huvitegevus' => 'huvitegevus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'now +1 year';
  $handler->display->display_options['filters']['field_schedule_date_value']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value']['add_delta'] = 'yes';
  /* Filter criterion: Content: Huvitegevuse kategooriad (field_categories_activity) (translated) */
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['id'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['field'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator_id'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['label'] = 'Huvitegevuse tüüp:';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['identifier'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta huvitegevused';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg - end date (field_schedule_date:value2) */
  $handler->display->display_options['filters']['field_schedule_date_value2']['id'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value2']['field'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_schedule_date_value2']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value2']['add_delta'] = 'yes';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if((intval($data->field_data_field_schedule_date_field_schedule_date_value2) - intval($data->field_data_field_schedule_date_field_schedule_date_value)) > 2592000) {
  return true;
}';

  /* Display: A Today */
  $handler = $view->new_display('block', 'A Today', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Otsi';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühjenda väljad';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteeri';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_categories_activity_value_i18n' => array(
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
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$dateraw = strtotime( "today" );

$day = t(date(\'l\', $dateraw));
$date = date(\'d.m | \', $dateraw) . $day;
echo $date;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date_1']['id'] = 'field_schedule_date_1';
  $handler->display->display_options['fields']['field_schedule_date_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_class'] = 'event-group-title';
  $handler->display->display_options['fields']['field_schedule_date_1']['empty'] = '<span class="date-display-single">[php]</span>';
  $handler->display->display_options['fields']['field_schedule_date_1']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['delta_offset'] = '0';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_class'] = 'time fixwidth';
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'only_time',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'name fixwidth';
  /* Field: Content: Huvitegevuse kategooriad */
  $handler->display->display_options['fields']['field_categories_activity']['id'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['field'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_categories_activity']['label'] = '';
  $handler->display->display_options['fields']['field_categories_activity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_class'] = 'category fixwidth';
  $handler->display->display_options['fields']['field_categories_activity']['type'] = 'i18n_list_default';
  $handler->display->display_options['fields']['field_categories_activity']['delta_offset'] = '0';
  /* Field: Field collection item: Asukoht */
  $handler->display->display_options['fields']['field_schedule_place']['id'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['table'] = 'field_data_field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['field'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_class'] = 'place fixwidth';
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'huvitegevus' => 'huvitegevus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['granularity'] = 'hour';
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'tomorrow + 3 hours';
  $handler->display->display_options['filters']['field_schedule_date_value']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value']['add_delta'] = 'yes';
  /* Filter criterion: Content: Huvitegevuse kategooriad (field_categories_activity) (translated) */
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['id'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['field'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator_id'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['label'] = 'Huvitegevuse tüüp:';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['identifier'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta huvitegevused';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg - end date (field_schedule_date:value2) */
  $handler->display->display_options['filters']['field_schedule_date_value2']['id'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value2']['field'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_schedule_date_value2']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value2']['add_delta'] = 'yes';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if((intval($data->field_data_field_schedule_date_field_schedule_date_value2) - intval($data->field_data_field_schedule_date_field_schedule_date_value)) > 2592000) {
  return true;
}';

  /* Display: A Tomorrow */
  $handler = $view->new_display('block', 'A Tomorrow', 'block_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Otsi';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühjenda väljad';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteeri';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_categories_activity_value_i18n' => array(
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
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$dateraw = strtotime( "tomorrow" );

$day = t(date(\'l\', $dateraw));
$date = date(\'d.m | \', $dateraw) . $day;
echo $date;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date_1']['id'] = 'field_schedule_date_1';
  $handler->display->display_options['fields']['field_schedule_date_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_class'] = 'event-group-title';
  $handler->display->display_options['fields']['field_schedule_date_1']['empty'] = '<span class="date-display-single">[php]</span>';
  $handler->display->display_options['fields']['field_schedule_date_1']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['delta_offset'] = '0';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_class'] = 'time fixwidth';
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'only_time',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'name fixwidth';
  /* Field: Content: Huvitegevuse kategooriad */
  $handler->display->display_options['fields']['field_categories_activity']['id'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['field'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_categories_activity']['label'] = '';
  $handler->display->display_options['fields']['field_categories_activity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_class'] = 'category fixwidth';
  $handler->display->display_options['fields']['field_categories_activity']['type'] = 'i18n_list_default';
  $handler->display->display_options['fields']['field_categories_activity']['delta_offset'] = '0';
  /* Field: Field collection item: Asukoht */
  $handler->display->display_options['fields']['field_schedule_place']['id'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['table'] = 'field_data_field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['field'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_class'] = 'place fixwidth';
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'huvitegevus' => 'huvitegevus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['granularity'] = 'hour';
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'tomorrow +1 day 3 hours';
  $handler->display->display_options['filters']['field_schedule_date_value']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value']['add_delta'] = 'yes';
  /* Filter criterion: Content: Huvitegevuse kategooriad (field_categories_activity) (translated) */
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['id'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['field'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator_id'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['label'] = 'Huvitegevuse tüüp:';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['identifier'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta huvitegevused';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg - end date (field_schedule_date:value2) */
  $handler->display->display_options['filters']['field_schedule_date_value2']['id'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value2']['field'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value2']['default_date'] = 'now +1 day';
  $handler->display->display_options['filters']['field_schedule_date_value2']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value2']['add_delta'] = 'yes';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if((intval($data->field_data_field_schedule_date_field_schedule_date_value2) - intval($data->field_data_field_schedule_date_field_schedule_date_value)) > 2592000) {
  return true;
}';

  /* Display: A F-S */
  $handler = $view->new_display('block', 'A F-S', 'block_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Otsi';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühjenda väljad';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteeri';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_categories_activity_value_i18n' => array(
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
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'php',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'event-item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'event-group';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date_1']['id'] = 'field_schedule_date_1';
  $handler->display->display_options['fields']['field_schedule_date_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_class'] = 'event-group-title';
  $handler->display->display_options['fields']['field_schedule_date_1']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['delta_offset'] = '0';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_class'] = 'time fixwidth';
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'only_time',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$dateraw = strtotime( "this friday" );

$day = t(date(\'l\', $dateraw));
$date = date(\'d.m | \', $dateraw) . $day;
$value = $data->field_field_schedule_date_1[0][\'rendered\'][\'#markup\'];
$raw = $data->field_field_schedule_date_1[0][\'raw\'][\'value\'];
if($raw >= $dateraw) {
echo $value;
}
else {
echo \'<span class="date-display-single">\'.$date.\'</span>\';
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'name fixwidth';
  /* Field: Content: Huvitegevuse kategooriad */
  $handler->display->display_options['fields']['field_categories_activity']['id'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['field'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_categories_activity']['label'] = '';
  $handler->display->display_options['fields']['field_categories_activity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_class'] = 'category fixwidth';
  $handler->display->display_options['fields']['field_categories_activity']['type'] = 'i18n_list_default';
  $handler->display->display_options['fields']['field_categories_activity']['delta_offset'] = '0';
  /* Field: Field collection item: Asukoht */
  $handler->display->display_options['fields']['field_schedule_place']['id'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['table'] = 'field_data_field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['field'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_class'] = 'place fixwidth';
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'huvitegevus' => 'huvitegevus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['granularity'] = 'hour';
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'Monday next week + 3 hours';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_to_date'] = 'Sunday this week';
  $handler->display->display_options['filters']['field_schedule_date_value']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value']['add_delta'] = 'yes';
  /* Filter criterion: Content: Huvitegevuse kategooriad (field_categories_activity) (translated) */
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['id'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['field'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator_id'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['label'] = 'Huvitegevuse tüüp:';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['identifier'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta huvitegevused';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg - end date (field_schedule_date:value2) */
  $handler->display->display_options['filters']['field_schedule_date_value2']['id'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value2']['field'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value2']['default_date'] = 'Friday this week';
  $handler->display->display_options['filters']['field_schedule_date_value2']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value2']['add_delta'] = 'yes';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if((intval($data->field_data_field_schedule_date_field_schedule_date_value2) - intval($data->field_data_field_schedule_date_field_schedule_date_value)) > 2592000) {
  return true;
}';

  /* Display: A This month */
  $handler = $view->new_display('block', 'A This month', 'block_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Otsi';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühjenda väljad';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteeri';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_categories_activity_value_i18n' => array(
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
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$dateraw = strtotime( "today" );

$day = t(date(\'l\', $dateraw));
$date = date(\'d.m | \', $dateraw) . $day;
echo $date;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date_1']['id'] = 'field_schedule_date_1';
  $handler->display->display_options['fields']['field_schedule_date_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_class'] = 'event-group-title';
  $handler->display->display_options['fields']['field_schedule_date_1']['empty'] = '<span class="date-display-single">[php]</span>';
  $handler->display->display_options['fields']['field_schedule_date_1']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['delta_offset'] = '0';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_class'] = 'time fixwidth';
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'only_time',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'name fixwidth';
  /* Field: Content: Huvitegevuse kategooriad */
  $handler->display->display_options['fields']['field_categories_activity']['id'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['field'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_categories_activity']['label'] = '';
  $handler->display->display_options['fields']['field_categories_activity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_class'] = 'category fixwidth';
  $handler->display->display_options['fields']['field_categories_activity']['type'] = 'i18n_list_default';
  $handler->display->display_options['fields']['field_categories_activity']['delta_offset'] = '0';
  /* Field: Field collection item: Asukoht */
  $handler->display->display_options['fields']['field_schedule_place']['id'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['table'] = 'field_data_field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['field'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_class'] = 'place fixwidth';
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'huvitegevus' => 'huvitegevus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'last day of this month';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_to_date'] = 'last day of this month';
  $handler->display->display_options['filters']['field_schedule_date_value']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value']['add_delta'] = 'yes';
  /* Filter criterion: Content: Huvitegevuse kategooriad (field_categories_activity) (translated) */
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['id'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['field'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator_id'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['label'] = 'Huvitegevuse tüüp:';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['identifier'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta huvitegevused';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg - end date (field_schedule_date:value2) */
  $handler->display->display_options['filters']['field_schedule_date_value2']['id'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value2']['field'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_schedule_date_value2']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value2']['add_delta'] = 'yes';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if((intval($data->field_data_field_schedule_date_field_schedule_date_value2) - intval($data->field_data_field_schedule_date_field_schedule_date_value)) > 2592000) {
  return true;
}';

  /* Display: A Next month */
  $handler = $view->new_display('block', 'A Next month', 'block_11');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Üritused';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Otsi';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühjenda väljad';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteeri';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_categories_activity_value_i18n' => array(
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
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'php',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'event-item';
  $handler->display->display_options['style_options']['wrapper_class'] = 'event-group';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date_1']['id'] = 'field_schedule_date_1';
  $handler->display->display_options['fields']['field_schedule_date_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date_1']['element_wrapper_class'] = 'event-group-title';
  $handler->display->display_options['fields']['field_schedule_date_1']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date_1']['delta_offset'] = '0';
  /* Field: Field collection item: Alguse ning olemasolul ka lõpuaeg */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_date']['element_wrapper_class'] = 'time fixwidth';
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'only_time',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => 'now',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_schedule_date']['delta_offset'] = '0';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$dateraw = strtotime( "first day of next month" );

$day = t(date(\'l\', $dateraw));
$date = date(\'d.m | \', $dateraw) . $day;
$value = $data->field_field_schedule_date_1[0][\'rendered\'][\'#markup\'];
$raw = $data->field_field_schedule_date_1[0][\'raw\'][\'value\'];
if($raw >= $dateraw) {
echo $value;
}
else {
echo \'<span class="date-display-single">\'.$date.\'</span>\';
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'name fixwidth';
  /* Field: Content: Huvitegevuse kategooriad */
  $handler->display->display_options['fields']['field_categories_activity']['id'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['field'] = 'field_categories_activity';
  $handler->display->display_options['fields']['field_categories_activity']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_categories_activity']['label'] = '';
  $handler->display->display_options['fields']['field_categories_activity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_categories_activity']['element_wrapper_class'] = 'category fixwidth';
  $handler->display->display_options['fields']['field_categories_activity']['type'] = 'i18n_list_default';
  $handler->display->display_options['fields']['field_categories_activity']['delta_offset'] = '0';
  /* Field: Field collection item: Asukoht */
  $handler->display->display_options['fields']['field_schedule_place']['id'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['table'] = 'field_data_field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['field'] = 'field_schedule_place';
  $handler->display->display_options['fields']['field_schedule_place']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_schedule_place']['element_wrapper_class'] = 'place fixwidth';
  /* Field: Content: Kirjeldus */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Tüüp (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'huvitegevus' => 'huvitegevus',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_schedule' => 'field_schedule',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg -  start date (field_schedule_date) */
  $handler->display->display_options['filters']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['filters']['field_schedule_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_schedule_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_date'] = 'last day of next month';
  $handler->display->display_options['filters']['field_schedule_date_value']['default_to_date'] = 'last day of next month';
  $handler->display->display_options['filters']['field_schedule_date_value']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value']['add_delta'] = 'yes';
  /* Filter criterion: Content: Huvitegevuse kategooriad (field_categories_activity) (translated) */
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['id'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['table'] = 'field_data_field_categories_activity';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['field'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator_id'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['label'] = 'Huvitegevuse tüüp:';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['operator'] = 'field_categories_activity_value_i18n_op';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['identifier'] = 'field_categories_activity_value_i18n';
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_categories_activity_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Linnaosa (field_schedule_city_id) */
  $handler->display->display_options['filters']['field_schedule_city_id_value']['id'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['table'] = 'field_data_field_schedule_city_id';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['field'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_id'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['label'] = 'Linnaosa:';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator_label'] = 'Linnaosa';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['operator'] = 'field_schedule_city_id_value_op';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['identifier'] = 'field_schedule_city_id_value';
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_schedule_city_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Otsi';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_schedule_place' => 'field_schedule_place',
    'field_description' => 'field_description',
  );
  /* Filter criterion: Content: Märgi, kui üritus on tasuta (field_isfree) */
  $handler->display->display_options['filters']['field_isfree_value']['id'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['table'] = 'field_data_field_isfree';
  $handler->display->display_options['filters']['field_isfree_value']['field'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['filters']['field_isfree_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_isfree_value']['group'] = 1;
  $handler->display->display_options['filters']['field_isfree_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator_id'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['label'] = 'Tasuta huvitegevused';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['operator'] = 'field_isfree_value_op';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['identifier'] = 'field_isfree_value';
  $handler->display->display_options['filters']['field_isfree_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_isfree_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_isfree_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Alguse ning olemasolul ka lõpuaeg - end date (field_schedule_date:value2) */
  $handler->display->display_options['filters']['field_schedule_date_value2']['id'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['filters']['field_schedule_date_value2']['field'] = 'field_schedule_date_value2';
  $handler->display->display_options['filters']['field_schedule_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_schedule_date_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_schedule_date_value2']['default_date'] = 'first day of next month';
  $handler->display->display_options['filters']['field_schedule_date_value2']['year_range'] = '-5:+5';
  $handler->display->display_options['filters']['field_schedule_date_value2']['add_delta'] = 'yes';
  $export['event_listing'] = $view;

  return $export;
}
