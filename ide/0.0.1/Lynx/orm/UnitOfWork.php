<?php

namespace Lynx\ORM;

class UnitOfWork
{
	/**
	 * @var EntityManager
	 */
	protected $em;
	protected $insertEntities;
	protected $updateEntities;
	protected $deleteEntities;

	public function __construct($em) {}

	public function insert($entity) {}

	public function update($entity) {}

	public function delete($entity) {}

	public function commit($entity = null) {}

}
