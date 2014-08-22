<?php

namespace Lynx\Cache;

abstract class CacheDriver implements \Lynx\Cache\Driver
{

    /**
     * Get data by id
     * 	
     *
     * @param string $id 
     */
	abstract public function get($id);

    /**
     * Data with id exists?
     * 	
     *
     * @param string $id 
     */
	public function exists($id) {}

}
