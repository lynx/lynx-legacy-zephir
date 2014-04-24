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
	 * @todo set alias to QueryBuilder
	 * @return QueryBuilder
	 */
	public function createQueryBuilder($alias) {}

	public function find($id) {}

	public function findAll() {}

	public function findBy() {}

	public function findOneBy() {}

}
