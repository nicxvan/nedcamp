<?php
/**
 * @file
 * Views include file.
 */

/**
 * Implements hook_views_plugins().
 *
 * Declare a new display so that users can add displays for each ticket type.
 */
function ticket_views_plugins() {
  // Declare a new display handler plugin.
  return array(
    'module' => 'views',
    'display' => array(
      'ticket_registration' => array(
        'title' => t('Ticket Registrations'),
        'handler' => 'ticket_views_plugin_display_ticket_registration',
        'path' => drupal_get_path('module', 'ticket') . '/views',
        'uses options' => TRUE,
        'use pager' => TRUE,
        'use more' => TRUE,
        'accept attachments' => TRUE,
        'theme' => 'views_view',
      ),
    ),
  );
}

/**
 * Implements hook_views_data_alter().
 */
function ticket_views_data_alter(&$data) {
  // Allow views to relate registrations to users.
  $data['ticket_registration']['author_uid']['relationship'] = array(
    'title' => t('Registrant'),
    'help' => t('Relate registration to the user who created it.'),
    'handler' => 'views_handler_relationship',
    'base' => 'users',
    'base field' => 'uid', // Field on the joined table.
    'field' => 'author_uid',
    'label' => t('registrant'),
  );

  $data['ticket_registration']['view_registration'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the ticket registration.'),
      'handler' => 'ticket_views_handler_field_registration_link',
    ),
  );

  $data['ticket_registration']['edit_registration'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the ticket registration.'),
      'handler' => 'ticket_views_handler_field_registration_link_edit',
    ),
  );

  $data['ticket_registration']['cancel_registration'] = array(
    'field' => array(
      'title' => t('Cancel link'),
      'help' => t('Provide a simple link to delete the ticket registration.'),
      'handler' => 'ticket_views_handler_field_registration_link_cancel',
    ),
  );

}
