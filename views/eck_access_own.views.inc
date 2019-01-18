<?php
/**
 * @file
 * Provide additional Views fields for entity content.
 */

/**
 * Implements hook_views_data_alter().
 */
function eck_access_own_views_data_alter(&$data) {
  foreach (EntityType::loadAll() as $entity_type) {

    $data["eck_{$entity_type->name}"]['view_own_link'] = array(
      'field' => array(
        'title' => t('Link Own'),
        'help' => t('Provide a simple link to the %entity_label content.', array('%entity_label' => $entity_type->label)),
        'handler' => 'eck_access_own_views_handler_field_link',
        'weight' => 22,
      ),
    );
    $data["eck_{$entity_type->name}"]['edit_own_link'] = array(
      'field' => array(
        'title' => t('Edit link Own'),
        'help' => t('Provide a simple link to edit the %entity_label content that take in account record ownership access.', array('%entity_label' => $entity_type->label)),
        'handler' => 'eck_access_own_views_handler_field_link_edit',
        'weight' => 22,
      ),
    );
    $data["eck_{$entity_type->name}"]['delete_own_link'] = array(
      'field' => array(
        'title' => t('Delete link Own'),
        'help' => t('Provide a simple link to delete the %entity_label content that take in account record ownership access.', array('%entity_label' => $entity_type->label)),
        'handler' => 'eck_access_own_views_handler_field_link_delete',
        'weight' => 22,
      ),
    );
  }
}
