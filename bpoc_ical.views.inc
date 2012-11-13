<?php
/**
 * @file
 * Provide views data and handlers for bpoc_ical module
 */

/**
 * Implementation of hook_views_data().
 */
function bpoc_ical_views_data() {
  $data = array();

  $data['node']['bpoc_ical'] = array(
    'title' => t('BPOC iCal'),
    'help' => t('An Add-To-Calendar button.'),
    'field' => array(
      'handler' => 'bpoc_ical_handler_field_service_links',
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function bpoc_ical_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'bpoc_ical'),
    ),
    'handlers' => array(
      'bpoc_ical_handler_field_service_links' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
