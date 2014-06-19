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
     * {@inheritDoc}
     * 	
     *
     * @param string $id 
     * @param mixed $data 
     * @param mixed $lifeTime 
     */
	public function save($id, $data, $lifeTime = 3600) {}

    /**
     * {@inheritDoc}
     * 	
     *
     * @param string $id 
     * @return bool 
     */
	public function delete($id) {}

    /**
     * {@inheritDoc}
     * 	
     *
     * @param string $id 
     */
	public function get($id) {}

    /**
     * {@inheritDoc}
     * 	
     */
	public function flush() {}

}
