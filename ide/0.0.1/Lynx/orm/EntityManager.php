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
	protected $repositories;

	public function getConnection() {}

	public function getModelsManager() {}

	public function __construct($connection) {}

	public function flush($entity) {}

	public function commit() {}

	public function rollback() {}

	public function getRepository($entityName) {}

	public function createQueryBuilder() {}

	public function createQuery($sql) {}

}
