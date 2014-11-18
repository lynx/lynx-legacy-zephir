<?php

namespace Lynx\ORM;

class ModelsManager
{

    const CACHE_LOAD_PER_GET = 0;

    const CACHE_LOAD_PER_GET_ALL = 1;
    /**
     * 
     *
     * @var EntityManager
     */
    protected $em;

    private $cachedModels = array();

    protected $cacheLoaded = false;

    protected $cacheLoadType;

    /**
     * @param mixed $em 
     * @param mixed $cacheLoadType 
     */
	public function __construct(EntityManager $em, $cacheLoadType = self::CACHE_LOAD_PER_GET_ALL) {}

    /**
     * @param string $classname 
     */
	public function get($classname) {}

}
