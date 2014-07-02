<?php

namespace Lynx\Cache;

interface Driver
{

    /**
     * To initialize cache provider
     * 	
     */
	public function getInstance();

    /**
     * Save data
     * 	
     *
     * @param string $id 
     * @param mixed $data 
     * @param mixed $lifeTime 
     */
	public function save($id, $data, $lifeTime = 3600);

    /**
     * Save data by id
     * 	
     *
     * @param string $id 
     */
	public function delete($id);

    /**
     * Fetch data by id
     * 	
     *
     * @param string $id 
     */
	public function get($id);

    /**
     * Is value exist?
     * 	
     *
     * @param string $id 
     */
	public function exists($id);

    /**
     * Flush all values
     * 	
     */
	public function flush();

}
