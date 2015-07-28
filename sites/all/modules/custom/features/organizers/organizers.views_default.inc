<?php
/**
 * @file
 * organizers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function organizers_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'organizers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Organizers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Organizers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_type_of_organizer',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['group']['element_type'] = 'h2';
  $handler->display->display_options['style_options']['group']['class'] = 'organizers__group';
  $handler->display->display_options['style_options']['row']['element_type'] = 'article';
  $handler->display->display_options['style_options']['row']['class'] = 'organizers__organizer';
  $handler->display->display_options['style_options']['row']['last_every_nth'] = '3';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Excluded: Type of Organizer */
  $handler->display->display_options['fields']['field_type_of_organizer']['id'] = 'field_type_of_organizer';
  $handler->display->display_options['fields']['field_type_of_organizer']['table'] = 'field_data_field_type_of_organizer';
  $handler->display->display_options['fields']['field_type_of_organizer']['field'] = 'field_type_of_organizer';
  $handler->display->display_options['fields']['field_type_of_organizer']['ui_name'] = 'Excluded: Type of Organizer';
  $handler->display->display_options['fields']['field_type_of_organizer']['label'] = '';
  $handler->display->display_options['fields']['field_type_of_organizer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_type_of_organizer']['element_type'] = '0';
  $handler->display->display_options['fields']['field_type_of_organizer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_type_of_organizer']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_type_of_organizer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_type_of_organizer']['field_api_classes'] = TRUE;
  /* Field: Content: Headshot */
  $handler->display->display_options['fields']['field_headshot']['id'] = 'field_headshot';
  $handler->display->display_options['fields']['field_headshot']['table'] = 'field_data_field_headshot';
  $handler->display->display_options['fields']['field_headshot']['field'] = 'field_headshot';
  $handler->display->display_options['fields']['field_headshot']['label'] = '';
  $handler->display->display_options['fields']['field_headshot']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_headshot']['element_class'] = 'organizers__headshot';
  $handler->display->display_options['fields']['field_headshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_headshot']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_headshot']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_headshot']['settings'] = array(
    'image_style' => 'speakers_rabblerousers',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'p';
  $handler->display->display_options['fields']['title']['element_class'] = 'organizers__name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Twitter URL */
  $handler->display->display_options['fields']['field_twitter_url']['id'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['table'] = 'field_data_field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['field'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['label'] = '';
  $handler->display->display_options['fields']['field_twitter_url']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_twitter_url']['element_class'] = 'organizers__twitter';
  $handler->display->display_options['fields']['field_twitter_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_twitter_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_twitter_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_twitter_url']['click_sort_column'] = 'url';
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = '';
  $handler->display->display_options['fields']['field_organization']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_organization']['element_class'] = 'organizers__company';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_organization']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_organization']['click_sort_column'] = 'url';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_type'] = '0';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit Organizer';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organizers' => 'organizers',
  );

  /* Display: Organizers Page */
  $handler = $view->new_display('page', 'Organizers Page', 'organizers_page');
  $handler->display->display_options['path'] = 'organizers';
  $export['organizers'] = $view;

  return $export;
}
