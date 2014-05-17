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


	public function getConnection() {}


	public function getModelsManager() {}


	public function getEventManager() {}


	public function getConfiguration() {}

    /**
     * @param Connection $connection 
     * @param Configuration $configuration 
     * @param EventsManager $eventManager 
     */
	public function __construct($connection, $configuration, $eventManager) {}

    /**
     * @param variable $entity 
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
     * @return EntityRepository n
     */
	public function getRepository($entityName) {}

    /**
     * @return QueryBuilder 
     */
	public function createQueryBuilder() {}

    /**
     * @param variable $sql 
     * @return Query 
     */
	public function createQuery($sql) {}

}
