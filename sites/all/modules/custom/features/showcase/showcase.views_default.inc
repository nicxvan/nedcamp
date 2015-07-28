<?php
/**
 * @file
 * showcase.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function showcase_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'showcase';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Showcase';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'NEDcamp Showcase';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'showcase_page_slider';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Lead-in';
  $handler->display->display_options['header']['area']['content'] = '<p>Drupal projects from the sponsors and attendees of NEDcamp 2015</p>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<div class="showcase__counter">Project @start of @total</div>';
  /* Field: Excluded: Content: Showcase Images */
  $handler->display->display_options['fields']['field_showcase_images']['id'] = 'field_showcase_images';
  $handler->display->display_options['fields']['field_showcase_images']['table'] = 'field_data_field_showcase_images';
  $handler->display->display_options['fields']['field_showcase_images']['field'] = 'field_showcase_images';
  $handler->display->display_options['fields']['field_showcase_images']['ui_name'] = 'Excluded: Content: Showcase Images';
  $handler->display->display_options['fields']['field_showcase_images']['label'] = '';
  $handler->display->display_options['fields']['field_showcase_images']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_showcase_images']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_showcase_images']['alter']['text'] = '<div class="showcase__images">[field_showcase_images]</div>';
  $handler->display->display_options['fields']['field_showcase_images']['element_type'] = '0';
  $handler->display->display_options['fields']['field_showcase_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_showcase_images']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_showcase_images']['element_wrapper_class'] = 'showcase__images';
  $handler->display->display_options['fields']['field_showcase_images']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_showcase_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_showcase_images']['type'] = 'flexslider';
  $handler->display->display_options['fields']['field_showcase_images']['settings'] = array(
    'optionset' => 'showcase_image_slider',
    'image_style' => 'showcase_image_slider_full',
    'caption' => 0,
  );
  $handler->display->display_options['fields']['field_showcase_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_showcase_images']['separator'] = '';
  $handler->display->display_options['fields']['field_showcase_images']['field_api_classes'] = TRUE;
  /* Field: Output: Showcase Images and sharing via Template */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Output: Showcase Images and sharing via Template';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_showcase_images]';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'showcase__images_sharing';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'showcase__title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'showcase__description';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Project Link */
  $handler->display->display_options['fields']['field_project_link']['id'] = 'field_project_link';
  $handler->display->display_options['fields']['field_project_link']['table'] = 'field_data_field_project_link';
  $handler->display->display_options['fields']['field_project_link']['field'] = 'field_project_link';
  $handler->display->display_options['fields']['field_project_link']['label'] = '';
  $handler->display->display_options['fields']['field_project_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_project_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_link']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_project_link']['element_wrapper_class'] = 'showcase__project_link';
  $handler->display->display_options['fields']['field_project_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_project_link']['click_sort_column'] = 'url';
  /* Field: Content: Agency Website */
  $handler->display->display_options['fields']['field_agency_website']['id'] = 'field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['table'] = 'field_data_field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['field'] = 'field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['label'] = 'Built By';
  $handler->display->display_options['fields']['field_agency_website']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_agency_website']['element_class'] = 'showcase__label';
  $handler->display->display_options['fields']['field_agency_website']['element_label_type'] = 'p';
  $handler->display->display_options['fields']['field_agency_website']['element_label_class'] = 'showcase__content';
  $handler->display->display_options['fields']['field_agency_website']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_agency_website']['element_wrapper_class'] = 'showcase__agency';
  $handler->display->display_options['fields']['field_agency_website']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_agency_website']['click_sort_column'] = 'url';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_type'] = '0';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'showcase__edit edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit Showcase Item';
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'showcase:showcase_sorting';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    'showcase' => 'showcase',
  );

  /* Display: Showcase Page */
  $handler = $view->new_display('page', 'Showcase Page', 'showcase');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'next';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['element_type'] = 'article';
  $handler->display->display_options['style_options']['row']['class'] = 'showcase__item';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['last_every_nth'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'showcase';

  /* Display: Auto Showcase Page */
  $handler = $view->new_display('page', 'Auto Showcase Page', 'auto_showcase');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Showcase Images */
  $handler->display->display_options['fields']['field_showcase_images']['id'] = 'field_showcase_images';
  $handler->display->display_options['fields']['field_showcase_images']['table'] = 'field_data_field_showcase_images';
  $handler->display->display_options['fields']['field_showcase_images']['field'] = 'field_showcase_images';
  $handler->display->display_options['fields']['field_showcase_images']['label'] = '';
  $handler->display->display_options['fields']['field_showcase_images']['element_type'] = '0';
  $handler->display->display_options['fields']['field_showcase_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_showcase_images']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_showcase_images']['element_wrapper_class'] = 'showcase__images';
  $handler->display->display_options['fields']['field_showcase_images']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_showcase_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_showcase_images']['type'] = 'flexslider';
  $handler->display->display_options['fields']['field_showcase_images']['settings'] = array(
    'optionset' => 'showcase_image_slider',
    'image_style' => 'showcase_image_slider_full',
    'caption' => 0,
  );
  $handler->display->display_options['fields']['field_showcase_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_showcase_images']['separator'] = '';
  $handler->display->display_options['fields']['field_showcase_images']['field_api_classes'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'showcase__title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'showcase__description';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Project Link */
  $handler->display->display_options['fields']['field_project_link']['id'] = 'field_project_link';
  $handler->display->display_options['fields']['field_project_link']['table'] = 'field_data_field_project_link';
  $handler->display->display_options['fields']['field_project_link']['field'] = 'field_project_link';
  $handler->display->display_options['fields']['field_project_link']['label'] = '';
  $handler->display->display_options['fields']['field_project_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_project_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_link']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_project_link']['element_wrapper_class'] = 'showcase__project_link';
  $handler->display->display_options['fields']['field_project_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_project_link']['click_sort_column'] = 'url';
  /* Field: Content: Agency Website */
  $handler->display->display_options['fields']['field_agency_website']['id'] = 'field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['table'] = 'field_data_field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['field'] = 'field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['label'] = 'Built By';
  $handler->display->display_options['fields']['field_agency_website']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_agency_website']['element_class'] = 'showcase__label';
  $handler->display->display_options['fields']['field_agency_website']['element_label_type'] = 'p';
  $handler->display->display_options['fields']['field_agency_website']['element_label_class'] = 'showcase__content';
  $handler->display->display_options['fields']['field_agency_website']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_agency_website']['element_wrapper_class'] = 'showcase__agency';
  $handler->display->display_options['fields']['field_agency_website']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_agency_website']['click_sort_column'] = 'url';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_type'] = '0';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'showcase__edit edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit Showcase Item';
  $handler->display->display_options['path'] = 'auto_showcase';

  /* Display: Node page Block */
  $handler = $view->new_display('block', 'Node page Block', 'showcase_node');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['element_type'] = 'article';
  $handler->display->display_options['style_options']['row']['class'] = 'showcase_node__item';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['last_every_nth'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Lead-in';
  $handler->display->display_options['header']['area']['content'] = '<p>Drupal projects from the sponsors and attendees of NEDcamp 2015</p>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'View Entire Showcase';
  $handler->display->display_options['footer']['area']['content'] = '<p class="showcase__view_all"><a href="/showcase" class="showcase__view_all_link btn">View Entire Showcase</a></p>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Block: Showcase Node Page';

  /* Display: Showcase Sorting */
  $handler = $view->new_display('page', 'Showcase Sorting', 'showcase_sorting');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_project_link' => 'field_project_link',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Update';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'showcase__title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Content';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'showcase__description';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Project Link */
  $handler->display->display_options['fields']['field_project_link']['id'] = 'field_project_link';
  $handler->display->display_options['fields']['field_project_link']['table'] = 'field_data_field_project_link';
  $handler->display->display_options['fields']['field_project_link']['field'] = 'field_project_link';
  $handler->display->display_options['fields']['field_project_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_project_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_link']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_project_link']['element_wrapper_class'] = 'showcase__project_link';
  $handler->display->display_options['fields']['field_project_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_project_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_project_link']['type'] = 'link_url';
  $handler->display->display_options['path'] = 'admin/sorting/showcase';
  $export['showcase'] = $view;

  return $export;
}
