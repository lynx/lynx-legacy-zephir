<?php

namespace Lynx\Stdlib\Events;

class Event
{

    protected $_type;

    protected $_source;

    protected $_data;

    protected $_stopped = false;

    protected $_cancelable = true;

    /**
     * @param mixed $type 
     */
	public function setType($type) {}


	public function getType() {}


	public function getSource() {}

    /**
     * @param mixed $data 
     */
	public function setData($data) {}


	public function getData() {}


	public function getCancelable() {}

    /**
     * Phalcon\Events\Event constructor
     * 	
     * @param string type
     * @param object source
     * @param mixed data
     * @param boolean cancelable
     * 	
     *
     * @param string $type 
     * @param mixed $source 
     * @param mixed $data 
     * @param mixed $cancelable 
     */
	public function __construct($type, $source, $data = null, $cancelable = true) {}

    /**
     * Stops the event preventing propagation
     * 	
     */
	public function stop() {}

    /**
     * Check whether the event is currently stopped
     * 	
     * @return boolean
     * 	
     *
     * @return bool 
     */
	public function isStopped() {}

}
