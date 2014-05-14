<?php

/**
 * @see hook_entity_property_info()
 */
class TicketTypeMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['ttid'] = array(
      'label' => t('Ticket Type ID'),
      'type' => 'integer',
      'description' => t('The ticket type ID.'),
      'schema field' => 'ttid',
      'setter callback' => 'entity_property_verbatim_set',
    );
    $properties['revision_id'] = array(
      'label' => t('Ticket Type Revision'),
      'type' => 'integer',
      'description' => t('The ticket type revision.'),
      'schema field' => 'revision_id',
      'setter callback' => 'entity_property_verbatim_set',
    );
    $properties['entity_type'] = array(
      'label' => t('Entity Type'),
      'type' => 'text',
      'description' => t('The host entity type.'),
      'schema field' => 'entity_type',
      'setter callback' => 'entity_property_verbatim_set',
    );
    $properties['entity_id'] = array(
      'label' => t('Entity ID'),
      'type' => 'integer',
      'description' => t('The host entity ID.'),
      'schema field' => 'entity_id',
      'setter callback' => 'entity_property_verbatim_set',
    );
    $properties['field_name'] = array(
      'label' => t('Field Name'),
      'type' => 'text',
      'description' => t('The host entity field name.'),
      'schema field' => 'field_name',
      'setter callback' => 'entity_property_verbatim_set',
    );
    $properties['status'] = array(
      'label' => t('Status'),
      'type' => 'boolean',
      'description' => t('The ticket type status.'),
      'schema field' => 'status',
      'setter callback' => 'entity_property_verbatim_set',
    );
    $properties['created'] = array(
      'label' => t('Date Created'),
      'type' => 'date',
      'description' => t('The ticket type creation date.'),
      'schema field' => 'created',
      'setter callback' => 'entity_property_verbatim_set',
    );
    $properties['changed'] = array(
      'label' => t('Date Changed'),
      'type' => 'date',
      'description' => t('The ticket type last changed date.'),
      'schema field' => 'changed',
      'setter callback' => 'entity_property_verbatim_set',
    );

    return $info;
  }

}
