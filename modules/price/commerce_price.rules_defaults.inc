<?php
// $Id$

/**
 * @file Provides default rules configuration.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_price_default_rules_configuration() {
  $set = rules_rule_set(array(
    // The passed product entity. TODO: Generalize to all entities.
    'product' => array('type' => 'commerce_product', 'label' => t('Product')),
    'price' => array('type' => 'commerce_price_object', 'label' => t('Price')),
  ));
  $set->label = t('Price calculation');
  $set->name = 'commerce_price_calculation';
  $rule = rule()->action('data_set', array('data:select' => 'price:base-price', 'value:select' => 'product:sell-price'));
  $set->rule($rule);

  $configs[$set->name] = $set;
  return $configs;
}
