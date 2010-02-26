<?php
// $Id$

/**
 * @file Provides default rules configuration.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_price_default_rules_configuration() {
  $set = rules_rule_set(
    array(
      // The passed product entity.
      //'entity' => array('type' => 'entity', 'label' => t('Entity')),
      'id' => array('type' => 'integer', 'label' => t('id')),
    ),
    // Provided variables.
    array(
      'node' => array('type' => 'node', 'label' => 'node'),
    )
  );
  $set->label = t('Price calculation');
  $set->name = 'commerce_price_calculation';
  //$set->plugin = 'rule set';
  // Dumb example.
  $rule = rule()->action('entity_fetch', array('type' => 'node', 'id:select' => 'id', 'entity_fetched:var' => 'node'));
  $set->rule($rule);

  //Invoke via
  //list($node) = rules_invoke_rule_set('commerce_price_calculation');
  $configs[$set->name] = $set;
  return $configs;
}
