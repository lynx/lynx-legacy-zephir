<?php

namespace Lynx\ORM;

class UnitOfWork
{

    const STATE_MANAGED = 1;

    const STATE_NEW = 2;
    /**
     * 
     * @var EntityManager
     * 	
     */
    protected $em;

    protected $insertEntities = array();

    protected $updateEntities = array();

    protected $deleteEntities = array();

    /**
     * @param EntityManager $em 
     */
	public function __construct($em) {}

    /**
     * @param object $entity 
     */
	public function insert($entity) {}

    /**
     * @param object $entity 
     */
	public function update($entity) {}

    /**
     * @param object $entity 
     */
	public function delete($entity) {}

    /**
     * @param mixed $entity 
     */
	public function commit($entity = null) {}

}
