<?php
/**
 * @file
 * showcase.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function showcase_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function showcase_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function showcase_image_default_styles() {
  $styles = array();

  // Exported image style: showcase_image_slider_full.
  $styles['showcase_image_slider_full'] = array(
    'name' => 'showcase_image_slider_full',
    'label' => 'Showcase Image Slider Full',
    'effects' => array(
      4 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: showcase_image_slider_thumb.
  $styles['showcase_image_slider_thumb'] = array(
    'name' => 'showcase_image_slider_thumb',
    'label' => 'Showcase Image Slider Thumb',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function showcase_node_info() {
  $items = array(
    'showcase' => array(
      'name' => t('Showcase'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Project Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
