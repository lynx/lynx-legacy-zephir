/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Lynx\Stdlib\Events;


interface EventsManager
{

	/**
	 * Attach a listener to the events manager
	 *
	 * @param string eventType
	 * @param object handler
	 */
	public function attach(eventType, handler);

	/**
	 * Removes all events from the EventsManager
	 *
	 * @param string type
	 */
	public function dettachAll(type=null);

	/**
	 * Fires a event in the events manager causing that the acive listeners will be notified about it
	 *
	 * @param string eventType
	 * @param object source
	 * @param mixed  data
	 * @return mixed
	 */
	public function fire(eventType, source, data=null);

	/**
	 * Returns all the attached listeners of a certain type
	 *
	 * @param string type
	 * @return array
	 */
	public function getListeners(type);
}