<?php
/**
 * Implements hook_form_system_theme_settings_alter().
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function sitetheme_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL)  {
  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }

  // Create the form using Forms API: http://api.drupal.org/api/7

  // Create the form using Forms API
  $form['logo']['logo_placement'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Logo Placement'),
  );
  $form['logo']['logo_placement']['logo_placement_selector'] = array(
    '#type'          => 'select',
    '#title'         => t('Location of logo'),
    '#default_value' => theme_get_setting('logo_placement_selector'),
    '#options'       => array(
                          'header'  => t('Header'),
                          'sidebar' => t('Sidebar'),
                          'content' => t('Content'),
                        ),
  );
  
  
  /* -- Delete this line if you want to use this setting
  $form['sitetheme_example'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('sitetheme sample setting'),
    '#default_value' => theme_get_setting('sitetheme_example'),
    '#description'   => t("This option doesn't do anything; it's just an example."),
  );
  // */

  // Remove some of the base theme's settings.
  /* -- Delete this line if you want to turn off this setting.
  unset($form['themedev']['zen_wireframes']); // We don't need to toggle wireframes on this site.
  // */

  // We are editing the $form in place, so we don't need to return anything.
}
