<?php

namespace Lynx\ORM;

class EntityRepository
{
	/**
	 * @var EntityManager
	 */
	protected $em;
	/**
	 * @var ModelMetaData
	 */
	protected $modelWrapper;

	/**
	 * @var EntityManager
	 */
	public function getEm() {}

	public function __construct($em, $modelWrapper) {}

	/**
	 * @param string alias
	 * @return QueryBuilder
	 */
	public function createQueryBuilder($alias) {}

	/**
	 * Find entity by primary key
	 */
	public function find($id) {}

	/**
	 * Find all entities from repository
	 */
	public function findAll() {}

	public function findBy() {}

	public function findOneBy() {}

}
