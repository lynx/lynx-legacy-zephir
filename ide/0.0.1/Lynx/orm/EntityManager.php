<?php

namespace Lynx\ORM;

class EntityManager
{
	/**
	 * @var UnitOfWork
	 */
	protected $unitOfWork;
	protected $connection;

	public function getConnection() {}

	public function __construct($connection) {}

	public function flush($entity) {}

	public function createQueryBuilder() {}

	public function createQuery($sql) {}

}
