<?php

namespace Lynx\Cache;

class Memcached extends \Lynx\Cache\CacheDriver
{

    protected $options;

    protected $instance;

    /**
     * @param array $options 
     */
	public function __construct($options = null) {}

    /**
     * @param \Memcached $instance 
     */
	public function setInstance($instance) {}

    /**
     * @return \Memcached 
     */
	public function getInstance() {}

    /**
     * @param string $id 
     * @param mixed $data 
     * @param mixed $lifeTime 
     */
	public function save($id, $data, $lifeTime = 3600) {}

    /**
     * @param string $id 
     */
	public function delete($id) {}

    /**
     * @param string $id 
     */
	public function get($id) {}


	public function flush() {}

}
