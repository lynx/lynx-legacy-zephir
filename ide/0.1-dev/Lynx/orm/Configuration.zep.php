<?php

namespace Lynx\ORM;

class Configuration
{

    protected $cacheDriver;


	public function getCacheDriver() {}

    /**
     * 
     * Set Cache Driver
     *
     * @param mixed $cacheDriver 
     */
	public function setCacheDriver(\Cacher\Driver $cacheDriver) {}

}
