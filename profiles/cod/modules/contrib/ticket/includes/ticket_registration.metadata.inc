<?php

/**
 * @see hook_entity_property_info()
 */
class TicketRegistrationMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['trid'] = array(
      'label' => t('Ticket Registration ID'),
      'type' => 'integer',
      'description' => t('The ticket registration ID.'),
      'schema field' => 'trid',
      'setter callback' => 'entity_property_verbatim_set',
    );

    $properties['bundle'] = array(
      'label' => t('Ticket Type (Bundle)'),
      'type' => 'integer',
      'description' => t('The ticket registration ticket type.'),
      'schema field' => 'bundle',
      'setter callback' => 'entity_property_verbatim_set',
    );

    $properties['entity_type'] = array(
      'label' => t("Host entity type"),
      'type' => 'token',
      'description' => t("The entity type of the host entity."),
      'getter callback' => 'ticket_get_properties',

    );

    $properties['entity_id'] = array(
      'label' => t("Host entity ID"),
      'type' => 'integer',
      'description' => t("The entity ID of the host entity."),
      'getter callback' => 'ticket_get_properties',
    );

    $properties['created'] = array(
      'label' => t("Date created"),
      'type' => 'date',
      'schema field' => 'created',
      'description' => t('The ticket registration creation date.'),
      'setter callback' => 'entity_property_verbatim_set',
    );

    $properties['changed'] = array(
      'label' => t("Date updated"),
      'type' => 'date',
      'schema field' => 'updated',
      'description' => t('The ticket registration last changed date.'),
      'setter callback' => 'entity_property_verbatim_set',
    );

    // Provides a single calculated property that contains either the associated user's email address or the
    // anonymous email used if no user is associated with the registration
    $properties['mail'] = array(
      'label' => t('Registrant e-mail'),
      'type' => 'text',
      'description' => t('Either the user email address, if registration is for a user, or the anonymous user email property.'),
      'getter callback' => 'ticket_get_properties',
      'computed' => TRUE,
    );

    $properties['author'] = array(
      'label' => t("Author entity"),
      'type' => 'user',
      'schema field' => 'author_uid',
      'description' => t("The user who created the registration."),
      'getter callback' => 'ticket_registration_property_author_get',
      'setter callback' => 'entity_property_verbatim_set',
    );

    $properties['user'] = array(
      'label' => t("User entity"),
      'type' => 'entity',
      'schema field' => 'user_uid',
      'description' => t("The entity for which the registration belongs to. Usually a user."),
      'getter callback' => 'ticket_registration_property_user_get',
      'setter callback' => 'ticket_registration_property_user_set',
    );

    return $info;
  }

}
