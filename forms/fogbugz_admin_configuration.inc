<?php

/**
 * @file
 * Defines functionality for the fogbugz admin configuration form.
 */

/**
 * Form constructor for the fogbugz admin configuration form.
 *
 * @ingroup forms
 */
function fogbugz_admin_configuration_form($form, &$form_state) {

  $form['fogbugz_user_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Fogbugz User Email'),
    '#default_value' => variable_get('fogbugz_user_email', NULL),
    '#size' => 20,
    '#maxlength' => 20,
    '#required' => TRUE,
  );

  $form['fogbugz_user_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Fogbugz User Password'),
    '#default_value' => variable_get('fogbugz_user_password', NULL),
    '#size' => 20,
    '#maxlength' => 20,
    '#required' => TRUE,
  );

  $form['fogbugz_protocol'] = array(
    '#type' => 'textfield',
    '#title' => t('Fogbugz Server Protocol'),
    '#default_value' => variable_get('fogbugz_protocol', 'http'),
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => TRUE,
  );

  $form['fogbugz_hostname'] = array(
    '#type' => 'textfield',
    '#title' => t('Fogbugz Server Hostname'),
    '#default_value' => variable_get('fogbugz_hostname'),
    '#size' => 50,
    '#maxlength' => 50,
    '#required' => TRUE,
  );

  $form['fogbugz_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Fogbugz Server Port'),
    '#default_value' => variable_get('fogbugz_port'),
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
