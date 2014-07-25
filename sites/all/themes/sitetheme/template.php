<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function sitetheme_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  sitetheme_preprocess_html($variables, $hook);
  sitetheme_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
function sitetheme_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
function sitetheme_preprocess_page(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/* -- Delete this line if you want to use this function
function sitetheme_preprocess_node(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // sitetheme_preprocess_node_page() or sitetheme_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function sitetheme_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function sitetheme_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function sitetheme_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */


//::::::::::::::::::::::::::::::::::::::::::::::::::
//:: Changes the search form to use the "search" input element of HTML5.
//::::::::::::::::::::::::::::::::::::::::::::::::::
function sitetheme_preprocess_search_block_form(&$vars) {
	$vars['search_form'] = str_replace('type="text"', 'type="search"', $vars['search_form']);
}

//::::::::::::::::::::::::::::::::::::::::::::::::::
//:: Update search block to use polaceholder and use a <button> and not input[type=submit]
//::::::::::::::::::::::::::::::::::::::::::::::::::
function sitetheme_form_alter(&$form, &$form_state, $form_id) {
	if ($form_id == 'search_block_form') {
		$form['search_block_form']['#attributes']['placeholder'] = t('enter part #, type, or manufacturer');
    unset($form['actions']['submit']);
		$form['actions']['button'] = array (
			'#prefix' => '<button type="submit" id="edit-submit-btn" name="op" class="form-submit icon-search">',
			'#suffix' => '</button>',
			'#markup' => t('Search'),
			'#weight' => 1000,
		);
  }
}

//::::::::::::::::::::::::::::::::::::::::::::::::::
//:: Conditional JavaScript
//::::::::::::::::::::::::::::::::::::::::::::::::::
function sitetheme_preprocess_html(&$vars) {

  //::::::::::::::::::::::::::::::::::::::::::::::::::
  //:: Working body classes
  $body_classes = array($vars['classes_array']);
  #dpm($body_classes);
  //::::::::::::::::::::::::::::::::::::::::::::::::::
  //:: Removing sidebar classes
  foreach ($body_classes as $key => $value) {
    foreach ($value as $key2 => $value2) {
      if(preg_match("/sidebar/", $value2)) {
        unset($body_classes[$key][$key2]);
      }
    }
  }
  $vars['classes_array'] = $body_classes['0'];
  
  
  //::::::::::::::::::::::::::::::::::::::::::::::::::
  //:: Add role to body classes
  if ($vars['user']) {
    foreach($vars['user']->roles as $key => $role){
      $role_class = 'role-' . str_replace(' ', '-', $role);
      $vars['classes_array'][] = $role_class;
    }
  }
  
}