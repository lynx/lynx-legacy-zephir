<?php

namespace Lynx\Cache;

class NativeArray extends \Lynx\Cache\CacheDriver
{

    protected $options;

    protected $instance = array();


	public function getInstance() {}

    /**
     * @param array $options 
     */
	public function __construct($options = null) {}

    /**
     * @param array $instance 
     */
	public function setInstance($instance) {}

    /**
     * @param string $id 
     * @param mixed $data 
     * @param mixed $lifeTime 
     */
	public function save($id, $data, $lifeTime = 3600) {}

    /**
     * @param string $id 
     * @return bool 
     */
	public function delete($id) {}

    /**
     * @param string $id 
     */
	public function get($id) {}


	public function flush() {}

}
