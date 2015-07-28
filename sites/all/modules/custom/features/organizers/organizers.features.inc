<?php
/**
 * @file
 * organizers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function organizers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function organizers_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function organizers_node_info() {
  $items = array(
    'organizers' => array(
      'name' => t('Organizers'),
      'base' => 'node_content',
      'description' => t('Organizers that make NedCamp everything it is!'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
