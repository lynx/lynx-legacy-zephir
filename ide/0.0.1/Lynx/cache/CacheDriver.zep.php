<?php

namespace Lynx\Cache;

abstract class CacheDriver implements \Lynx\Cache\Driver
{

    /**
     * @param string $id 
     */
	abstract public function get($id);

    /**
     * Data with id exists?
     *
     * @param string $id 
     * @return boolean 
     */
	public function exists($id) {}

}
