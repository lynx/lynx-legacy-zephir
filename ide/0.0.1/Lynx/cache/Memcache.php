<?php

namespace Lynx\Cache;

class Memcache extends \Lynx\Cache\CacheDriver
{
	protected $options;
	protected $instance;

	public function __construct($options = null) {}

	public function setInstance($instance) {}

	protected function getInstance() {}

	public function save($id, $data, $lifeTime = 3600) {}

	public function delete($id) {}

	public function get($id) {}

	public function flush() {}

}
