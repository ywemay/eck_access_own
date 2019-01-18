<?php
/**
 * @file
 * Field handler to present a link to the entity content.
 */
class eck_access_own_views_handler_field_link extends eck_views_handler_field_link {
  //views_handler_field_entity {

  public function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  public function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
    parent::options_form($form, $form_state);

    // The path is set by render_link function so don't allow to set it.
    $form['alter']['path'] = array('#access' => FALSE);
    $form['alter']['external'] = array('#access' => FALSE);
  }

  function render_link($entity, $values) {
    $entity_type = $entity->entityType();
    $bundle = $entity->bundle();
    $action = "view";

    $perms = array(
        "eck administer entities",
        "eck {$action} entities",
        "eck administer {$entity_type} {$bundle} entities",
        "eck {$action} {$entity_type} {$bundle} entities");

    global $user;
    if ($entity->uid == $user->uid) {
      $perms[] = "eck {$action} own {$entity_type} {$bundle} entities";
    }

    $text = "";

    if (eck__multiple_access_check($perms)) {
      $crud_info = get_bundle_crud_info($entity->entityType(), $entity->bundle());
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = str_replace('%eckentity', $entity->id, $crud_info['view']['path']);
      $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    }

    return $text;
  }
}
