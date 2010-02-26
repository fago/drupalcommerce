<?php
// $Id$

/**
 * @file Provides rules integration.
 */

/**
 * Implements hook_rules_data_info() to provide a rules data type for the
 * commerce price object.
 */
function commerce_price_rules_data_info() {
  $types['commerce_price_object'] = array(
    'label' => t('commerce price'),
    'wrap' => TRUE,
  );
  // Add some data info about the type so one is able to set/get the base price.
  $types['commerce_price_object']['data info']['properties'] = array(
    'base-price' => array(
      'type' => 'price',
      'label' => t('Base price'),
      'description' => t('TODO: The base price.'),
      'getter callback' => 'commerce_price_get_base_price',
      'setter callback' => 'commerce_price_set_base_price',
    ),
  );
  // Add in the data info aobut the 'price' data structure.
  _commerce_price_property_data_info($types['commerce_price_object']['data info']['properties']['base-price']);
  return $types;
}
