<?php

/**
 * @file
 * A handler to provide an Add-to-calendar field for a particular node.
 *
 * @ingroup views_field_handlers
 */
class bpoc_ical_handler_field_service_links extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
    $this->additional_fields['title'] = 'title';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Remove the alteration stuff
    unset($form['alter']);
  }

  function render($values) {
    $node = new stdClass();
    $node->nid = $values->{$this->aliases['nid']};
    $node->title = $values->{$this->aliases['title']};
    return '<span class="bpoc_ical">' . _bpoc_ical_create_button($node, TRUE) . '</span>';
  }
}
