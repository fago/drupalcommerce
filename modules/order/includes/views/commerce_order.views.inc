<?php
// $Id$

/**
 * Export Drupal Commerce orders to Views.
 */

/**
 * Implements hook_views_data()
 */
function commerce_order_views_data() {
  $data = array();

  $data['commerce_order']['table']['group']  = t('Commerce Order');

  $data['commerce_order']['table']['base'] = array(
    'field' => 'order_number',
    'title' => t('Commerce Order'),
    'help' => t('Order placed in the store.'),
  );

  // Expose the order ID.
  $data['commerce_order']['order_id'] = array(
    'title' => t('Order ID'),
    'help' => t('The unique internal identifier of the order.'),
    'field' => array(
      'handler' => 'commerce_order_handler_field_order',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'commerce_order_handler_argument_order_order_id',
      'name field' => 'order_number',
      'numeric' => TRUE,
      'validate type' => 'order_id',
    ),
  );

  // Expose the order number.
  $data['commerce_order']['order_number'] = array(
    'title' => t('Order number'),
    'help' => t('The unique customer facing number of the order.'),
    'field' => array(
      'handler' => 'commerce_order_handler_field_order',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    // TODO: Provide an argument handler for orders.
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Expose the owner uid.
  $data['commerce_order']['uid'] = array(
    'title' => t('Owner'),
    'help' => t('Relate an order to its owner.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('Order owner'),
    ),
  );

  // Expose the order status.
  $data['commerce_order']['status'] = array(
    'title' => t('Order status'),
    'help' => t('The workflow status of the order.'),
    'field' => array(
      'handler' => 'commerce_order_handler_field_order_status',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'commerce_order_handler_filter_status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Expose the created and changed timestamps.
  $data['commerce_order']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the order was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_order']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the order was last updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Expose links to operate on the order.
  $data['commerce_order']['view_order'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the administrator view of the order.'),
      'handler' => 'commerce_order_handler_field_order_link',
    ),
  );
  $data['commerce_order']['edit_order'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the order.'),
      'handler' => 'commerce_order_handler_field_order_link_edit',
    ),
  );
  $data['commerce_order']['delete_order'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the order.'),
      'handler' => 'commerce_order_handler_field_order_link_delete',
    ),
  );

  $data['commerce_order']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all the available operations links for the order.'),
      'handler' => 'commerce_order_handler_field_order_operations',
    ),
  );

  return $data;
}
