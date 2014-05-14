<?php

/**
 * The controller class used for registration state entities
 */
class TicketStateController extends EntityAPIControllerExportable {

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);

    if ($entity->default_state == 1) {
      $query = db_update('ticket_state')
        ->fields(array('default_state' => 0))
        ->condition('tsid', $entity->tsid, '<>');
      $query->execute();
    }
  }

}