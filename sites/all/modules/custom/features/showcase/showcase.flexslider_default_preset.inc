<?php
/**
 * @file
 * showcase.flexslider_default_preset.inc
 */

/**
 * Implements hook_flexslider_default_presets().
 */
function showcase_flexslider_default_presets() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'showcase_image_slider';
  $preset->title = 'Showcase Image Slider';
  $preset->theme = 'classic';
  $preset->imagestyle_normal = 'showcase_image_slider_full';
  $preset->imagestyle_thumbnail = 'showcase_image_slider_thumb';
  $preset->options = array(
    'namespace' => 'flex-',
    'selector' => '.slides--showcase_image_slider > li',
    'easing' => 'swing',
    'direction' => 'horizontal',
    'reverse' => 0,
    'smoothHeight' => 1,
    'startAt' => '0',
    'animationSpeed' => '500',
    'initDelay' => '0',
    'useCSS' => 1,
    'touch' => 1,
    'video' => 0,
    'keyboard' => 1,
    'multipleKeyboard' => 0,
    'mousewheel' => 0,
    'controlsContainer' => '.flex-control-nav-container',
    'sync' => '',
    'asNavFor' => '',
    'itemWidth' => '0',
    'itemMargin' => '0',
    'minItems' => '0',
    'maxItems' => '0',
    'move' => '0',
    'animation' => 'fade',
    'slideshow' => 1,
    'slideshowSpeed' => '5000',
    'directionNav' => 0,
    'controlNav' => 'thumbnails',
    'prevText' => 'Previous',
    'nextText' => 'Next',
    'pausePlay' => 0,
    'pauseText' => 'Pause',
    'playText' => 'Play',
    'randomize' => 0,
    'thumbCaptions' => 0,
    'thumbCaptionsBoth' => 0,
    'animationLoop' => 1,
    'pauseOnAction' => 1,
    'pauseOnHover' => 1,
    'manualControls' => '',
  );
  $export['showcase_image_slider'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'showcase_page_slider';
  $preset->title = 'Showcase Page Slider';
  $preset->theme = 'classic';
  $preset->imagestyle_normal = 'showcase_image_slider_full';
  $preset->imagestyle_thumbnail = 'showcase_image_slider_thumb';
  $preset->options = array(
    'namespace' => 'flex-',
    'selector' => '.slides--showcase_page_slider > li',
    'easing' => 'swing',
    'direction' => 'horizontal',
    'reverse' => 0,
    'smoothHeight' => 1,
    'startAt' => '0',
    'animationSpeed' => '500',
    'initDelay' => '0',
    'useCSS' => 1,
    'touch' => 1,
    'video' => 0,
    'keyboard' => 1,
    'multipleKeyboard' => 0,
    'mousewheel' => 0,
    'controlsContainer' => '.flex-control-nav-container',
    'sync' => '',
    'asNavFor' => '',
    'itemWidth' => '0',
    'itemMargin' => '0',
    'minItems' => '0',
    'maxItems' => '0',
    'move' => '0',
    'animation' => 'fade',
    'slideshow' => 1,
    'slideshowSpeed' => '20000',
    'directionNav' => 1,
    'controlNav' => '0',
    'prevText' => 'Previous',
    'nextText' => 'Next',
    'pausePlay' => 0,
    'pauseText' => 'Pause',
    'playText' => 'Play',
    'randomize' => 0,
    'thumbCaptions' => 0,
    'thumbCaptionsBoth' => 0,
    'animationLoop' => 1,
    'pauseOnAction' => 1,
    'pauseOnHover' => 0,
    'manualControls' => '',
  );
  $export['showcase_page_slider'] = $preset;

  return $export;
}
