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
    '#size' => 64,
    '#maxlength' => 64,
    '#required' => TRUE,
  );

  $form['fogbugz_user_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Fogbugz User Password'),
    '#default_value' => variable_get('fogbugz_user_password', NULL),
    '#size' => 64,
    '#maxlength' => 64,
    '#required' => TRUE,
    '#description' => 'Minimum <b>6</b> characters. Cannot begin or end with a <b>"-"</b> character.',
  );

  $form['fogbugz_protocol'] = array(
    '#type' => 'textfield',
    '#title' => t('Fogbugz Server Protocol'),
    '#default_value' => variable_get('fogbugz_protocol', 'http'),
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => TRUE,
    '#description' => 'Typically <b>"http"</b> or <b>"https"</b>. Do not include <b>"://"</b>.',
  );

  $form['fogbugz_hostname'] = array(
    '#type' => 'textfield',
    '#title' => t('Fogbugz Server Hostname'),
    '#default_value' => variable_get('fogbugz_hostname'),
    '#size' => 64,
    '#maxlength' => 64,
    '#required' => TRUE,
    '#description' => 'Do not include the protocol or port.',
  );

  $form['fogbugz_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Fogbugz Server Port'),
    '#default_value' => variable_get('fogbugz_port', '7066'),
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => TRUE,
    '#description' => 'Typically <b>"7066"</b>.',
  );

  return system_settings_form($form);
}
