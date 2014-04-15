<?php

namespace Lynx\Cache;

class NativeArray extends \Lynx\Cache\CacheDriver
{
	protected $options;
	protected $instance = array();

	public function __construct($options = null) {}

	public function setInstance($instance) {}

	protected function getInstance() {}

	public function save($id, $data, $lifeTime = 3600) {}

	public function delete($id) {}

	public function get($id) {}

	public function flush() {}

}
