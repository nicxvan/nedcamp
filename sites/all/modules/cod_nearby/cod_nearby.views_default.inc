<?php
/**
 * @file
 * cod_nearby.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cod_nearby_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nearby_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Nearby list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'What to do nearby';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'geofield_map_map';
  $handler->display->display_options['style_options']['data_source'] = 'field_nearby_coords';
  $handler->display->display_options['style_options']['popup_source'] = 'title';
  $handler->display->display_options['style_options']['geofield_map_min_zoom'] = '0';
  $handler->display->display_options['style_options']['geofield_map_max_zoom'] = '0';
  $handler->display->display_options['style_options']['geofield_map_baselayers_satellite'] = 0;
  $handler->display->display_options['style_options']['geofield_map_baselayers_hybrid'] = 0;
  $handler->display->display_options['style_options']['geofield_map_draggable'] = 1;
  $handler->display->display_options['style_options']['geofield_map_center'] = array(
    'lat' => '',
    'lon' => '',
    'geocode' => 'Find my location',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location (coordinates) */
  $handler->display->display_options['fields']['field_nearby_coords']['id'] = 'field_nearby_coords';
  $handler->display->display_options['fields']['field_nearby_coords']['table'] = 'field_data_field_nearby_coords';
  $handler->display->display_options['fields']['field_nearby_coords']['field'] = 'field_nearby_coords';
  $handler->display->display_options['fields']['field_nearby_coords']['label'] = '';
  $handler->display->display_options['fields']['field_nearby_coords']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_nearby_coords']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_nearby_coords']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_nearby_coords']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_nearby_coords']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nearby';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'list');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_nearby_location']['id'] = 'field_nearby_location';
  $handler->display->display_options['fields']['field_nearby_location']['table'] = 'field_data_field_nearby_location';
  $handler->display->display_options['fields']['field_nearby_location']['field'] = 'field_nearby_location';
  $handler->display->display_options['fields']['field_nearby_location']['label'] = '';
  $handler->display->display_options['fields']['field_nearby_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_nearby_location']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_nearby_location']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address-hide-country' => 'address-hide-country',
    ),
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $export['nearby_list'] = $view;

  return $export;
}
