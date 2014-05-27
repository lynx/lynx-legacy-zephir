<?php

namespace Lynx\ORM;

class UnitOfWork
{
    /**
     * 
     * @var EntityManager
     * 	
     */
    protected $em;

    protected $insertEntities;

    protected $updateEntities;

    protected $deleteEntities;

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
