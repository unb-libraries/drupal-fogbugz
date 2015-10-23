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

/**
 * Form validation handler for fogbugz_admin_configuration_form().
 */
function fogbugz_admin_configuration_form_validate($form, &$form_state) {
  // Validate email address (Drupal core 7.x fn).
  $validate_email = trim($form_state['values']['fogbugz_user_email']);
  if (!valid_email_address($validate_email)) {
    form_set_error('fogbugz_user_email', t('Please enter a valid email address.'));
  }

  // Validate password (Fogbugz has min 6 chars + cannot start/end with '-' restriction).
  $validate_pass = trim($form_state['values']['fogbugz_user_password']);
  $length_pass = strlen($validate_pass);
  if ($length_pass < 6 || $validate_pass[0] === '-' || $validate_pass[$length_pass - 1] === '-') {
    form_set_error('fogbugz_user_password', t('Please enter a valid password.'));
  }

  // Validate protocol.
  $validate_uri = trim($form_state['values']['fogbugz_protocol']);
  if (!ctype_alpha($validate_uri) || strlen($validate_uri) < 3) {
    form_set_error('fogbugz_protocol', t('Please enter a valid server protocol.'));
  }

  // Validate hostname field (Drupal core 7.x fn).
  $validate_host = trim($form_state['values']['fogbugz_hostname']);
  if (!drupal_valid_http_host($validate_host) || strstr($validate_host, ':')) {
    form_set_error('fogbugz_hostname', t('Please enter a valid server hostname.'));
  }

  // Validate port.
  $validate_port = trim($form_state['values']['fogbugz_port']);
  if (!ctype_digit($validate_port) || $validate_port < 1 || $validate_port > 48653) {
    form_set_error('fogbugz_port', t('Please enter a valid server port.'));
  }
}
