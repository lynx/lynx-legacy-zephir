<?php

namespace Lynx\ORM;

class EntityManager
{
    /**
     * @var UnitOfWork
     */
    protected $unitOfWork;

    protected $connection;

    protected $modelsManager;

    protected $eventManager;

    protected $repositories;

    protected $configuration;

    /**
     * @return UnitOfWork 
     */
	public function getUnitOfWork() {}


	public function getConnection() {}


	public function getModelsManager() {}


	public function getEventManager() {}


	public function getConfiguration() {}

    /**
     * @param mixed $connection 
     * @param mixed $configuration 
     * @param mixed $eventManager 
     */
	public function __construct(\Lynx\DBAL\Connection $connection, Configuration $configuration, \Lynx\Stdlib\Events\Manager $eventManager) {}

    /**
     * @param mixed $entity 
     */
	public function flush($entity) {}

    /**
     * @param object $entity 
     */
	public function remove($entity) {}


	public function beginTransaction() {}


	public function commit() {}


	public function rollback() {}

    /**
     * @param string $entityName 
     * @return bool|EntityRepository 
     */
	public function getRepository($entityName) {}

    /**
     * @return QueryBuilder 
     */
	public function createQueryBuilder() {}

    /**
     * @param mixed $sql 
     * @return Query 
     */
	public function createQuery($sql) {}

}
