<?php
/**
 * @file
 * Ticket Type entity class.
 */

/**
 * Provides an entity class Ticket Type.
 */
class TicketRegistration extends Entity {

  // Allow access to Ticket Type properties.
  public $trid;
  public $vid;
  // Essentially ttid is the bundle.
  public $bundle;
  public $created;
  public $changed;
  public $mail;
  public $author_uid;
  public $user_uid;

  /**
   * Construct.
   */
  public function __construct(array $values = array()) {
    return parent::__construct($values, 'ticket_registration');
  }

  /**
   * A helper function to get a registration's ticket type entity.
   */
  public function ticket_type() {
    return entity_load_single('ticket_type', $this->bundle);
  }

  /**
   * A helper function to get the email address of registration owner
   */
  public function getMail() {
    return $this->mail;
  }

}

class TicketRegistrationUIController extends EntityContentUIController {

  /**
   * Implements hook_menu().
   */
  public function hook_menu() {
    // Provide standard entity ui routes for registrations.
    $items = parent::hook_menu();

    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%entity_object';
    $plural_label = isset($this->entityInfo['plural label']) ? $this->entityInfo['plural label'] : $this->entityInfo['label'] . 's';

    // Remove any management links. We're defining some of these in
    // the ticket_type entity and field_ui will provide the rest.
    foreach (array_keys($items) as $path) {
      if (strpos($path, $this->path . '/manage/') === 0) {
        unset ($items[$path]);
      }
    }

    return $items;
  }

}
