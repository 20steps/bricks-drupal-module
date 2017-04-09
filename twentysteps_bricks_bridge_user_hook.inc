<?php
	
	/*
	 * This file is part of the 20steps Bricks module.
	 *
	 * (c) 2017 20steps
	 *
	 * For the full copyright and license information, please view the LICENSE
	 * file that was distributed with this source code.
	 */

/**
 * @param $edit
 * @param $account
 * @return void
 */
function twentysteps_bricks_bridge_user_login(&$edit, $account)
{
    $event = new \Ekino\Bundle\DrupalBundle\Event\DrupalEvent();
    $event
        ->addParameter($edit)
        ->addParameter($account)
    ;

    symfony_event_dispatch('drupal.user_login', $event);
}

/**
 * @param $account
 * @return void
 */
function twentysteps_bricks_bridge_user_logout($account)
{
    $event = new \Ekino\Bundle\DrupalBundle\Event\DrupalEvent();
    $event->addParameter($account);

    symfony_event_dispatch('drupal.user_logout', $event);
}

/**
 * @param $users
 * @param $type
 * @return void
 */
function twentysteps_bricks_bridge_entity_load(&$users, $type)
{
    if ($type !== 'user') {
        return;
    }

    symfony_event_dispatch(
        'drupal.user_load',
        new \Ekino\Bundle\DrupalBundle\Event\DrupalEntitiesEvent($type, $users)
    );
}

/**
 * @param $user
 * @param $type
 * @return void
 */
function twentysteps_bricks_bridge_entity_insert($user, $type)
{
    if ($type !== 'user') {
        return;
    }

    symfony_event_dispatch(
        'drupal.user_insert',
        new \Ekino\Bundle\DrupalBundle\Event\DrupalEntityEvent($type, $user)
    );
}

/**
 * @param $user
 * @param $type
 * @return void
 */
function twentysteps_bricks_bridge_entity_update($user, $type)
{
    if ($type !== 'user') {
        return;
    }

    symfony_event_dispatch(
        'drupal.user_update',
        new \Ekino\Bundle\DrupalBundle\Event\DrupalEntityEvent($type, $user)
    );
}

/**
 * @param $user
 * @param $type
 * @return void
 */
function twentysteps_bricks_bridge_entity_presave($user, $type)
{
    if ($type !== 'user') {
        return;
    }

    symfony_event_dispatch(
        'drupal.user_presave',
        new \Ekino\Bundle\DrupalBundle\Event\DrupalEntityEvent($type, $user)
    );
}