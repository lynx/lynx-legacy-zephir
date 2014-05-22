<?php

namespace Lynx\Stdlib\Events;

class Manager implements \Lynx\Stdlib\Events\EventsManager
{

    protected $_events;

    protected $_collect = false;

    protected $_enablePriorities = false;

    protected $_responses;

    /**
     * 
     * 	 * Attach a listener to the events manager
     * 	 *
     * 	 * @param string eventType
     * 	 * @param object handler
     * 	 * @param int priority
     * 	
     *
     * @param string $eventType 
     * @param variable $handler 
     * @param int $priority 
     */
	public function attach($eventType, $handler, $priority = 100) {}

    /**
     * 
     * 	 * Set if priorities are enabled in the EventsManager
     * 	 *
     * 	 * @param boolean enablePriorities
     * 	
     *
     * @param bool $enablePriorities 
     */
	public function enablePriorities($enablePriorities) {}

    /**
     * 
     * 	 * Returns if priorities are enabled
     * 	 *
     * 	 * @return boolean
     * 	
     *
     * @return bool 
     */
	public function arePrioritiesEnabled() {}

    /**
     * 
     * 	 * Tells the event manager if it needs to collect all the responses returned by every
     * 	 * registered listener in a single fire
     * 	 *
     * 	 * @param boolean collect
     * 	
     *
     * @param bool $collect 
     */
	public function collectResponses($collect) {}

    /**
     * 
     * 	 * Check if the events manager is collecting all all the responses returned by every
     * 	 * registered listener in a single fire
     * 	
     *
     * @return bool 
     */
	public function isCollecting() {}

    /**
     * 
     * 	 * Returns all the responses returned by every handler executed by the last 'fire' executed
     * 	 *
     * 	 * @return array
     * 	
     */
	public function getResponses() {}

    /**
     * 
     * 	 * Removes all events from the EventsManager
     * 	 *
     * 	 * @param string type
     * 	
     *
     * @param string $type 
     */
	public function dettachAll($type = null) {}

    /**
     * 
     * 	 * Internal handler to call a queue of events
     * 	 *
     * 	 * @param \SplPriorityQueue|array queue
     * 	 * @param Phalcon\Events\Event event
     * 	 * @return mixed
     * 	
     *
     * @param variable $queue 
     * @param variable $event 
     */
	public function fireQueue($queue, $event) {}

    /**
     * 
     * 	 * Fires an event in the events manager causing that active listeners be notified about it
     * 	 *
     * 	 *<code>
     * 	 *	$eventsManager->fire('db', $connection);
     * 	 *</code>
     * 	 *
     * 	 * @param string eventType
     * 	 * @param object source
     * 	 * @param mixed  data
     * 	 * @param boolean cancelable
     * 	 * @return mixed
     * 	
     *
     * @param string $eventType 
     * @param mixed $source 
     * @param mixed $data 
     * @param bool $cancelable 
     */
	public function fire($eventType, $source, $data = null, $cancelable = true) {}

    /**
     * 
     * 	 * Check whether certain type of event has listeners
     * 	 *
     * 	 * @param string type
     * 	 * @return boolean
     * 	
     *
     * @param string $type 
     * @return bool 
     */
	public function hasListeners($type) {}

    /**
     * 
     * 	 * Returns all the attached listeners of a certain type
     * 	 *
     * 	 * @param string type
     * 	 * @return array
     * 	
     *
     * @param string $type 
     */
	public function getListeners($type) {}

}
