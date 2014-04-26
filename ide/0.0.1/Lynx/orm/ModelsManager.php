<?php

namespace Lynx\ORM;

class ModelsManager
{
	const CACHE_LOAD_PER_GET = 0;
	const CACHE_LOAD_PER_GET_ALL = 1;
	/**
	 * @var EntityManager
	 */
	protected $em;
	private $cachedModels = array();
	protected $cacheLoaded = false;
	protected $cacheLoadType;

	public function __construct($em, $cacheLoadType = ) {}

	public function get($classname) {}

}
