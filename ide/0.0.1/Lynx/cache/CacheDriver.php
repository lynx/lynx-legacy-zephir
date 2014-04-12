<?php

namespace Lynx\Cache;

abstract class CacheDriver
{

	/**
	 * To initialize cache provider
	 */
	abstract protected function getInstance();

	/**
	 * Save data
	 */
	abstract public function save($id, $data, $lifeTime = 3600);

	/**
	 * Save data by id
	 */
	abstract public function delete($id);

	/**
	 * Fetch data by id
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
