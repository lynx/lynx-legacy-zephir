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

	public function __construct($connection, $configuration, $eventManager) {}

	public function flush($entity) {}

	public function remove($entity) {}

	public function beginTransaction() {}

	public function commit() {}

	public function rollback() {}

	/**
	 * @param string $entityName
	 * @return EntityRepository|boolean
	 */
	public function getRepository($entityName) {}

	public function createQueryBuilder() {}

	public function createQuery($sql) {}

}
