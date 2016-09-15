<?php
/**
 * @file
 * cod_nearby.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cod_nearby_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cod_nearby_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cod_nearby_node_info() {
  $items = array(
    'nearby' => array(
      'name' => t('Nearby'),
      'base' => 'node_content',
      'description' => t('Other things to do near the event.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
