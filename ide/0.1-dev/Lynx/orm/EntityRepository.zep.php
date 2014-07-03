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

    /**
     * @param EntityManager $em 
     * @param ModelMetaData $modelWrapper 
     */
	public function __construct($em, $modelWrapper) {}

    /**
     * @param string $alias 
     * @param string  s
     * @return QueryBuilder 
     */
	public function createQueryBuilder($alias) {}

    /**
     * Find entity by primary key
     * @param $id
     * @return object|boolean
     * 	
     *
     * @param mixed $id 
     */
	public function find($id) {}

    /**
     * Count all rows
     * 	
     *
     * @return int 
     */
	public function count() {}

    /**
     * Find all entities from repository
     * 	
     */
	public function findAll() {}

    /**
     * Find all entities from repository by column = :value
     * @param string $column
     * @param $value
     * @return object|boolean
     * 	
     *
     * @param string $column 
     * @param mixed $value 
     */
	public function findBy($column, $value) {}

    /**
     * Find one entity from repository by column = :value
     * @param string $column
     * @param $value
     * @return object|boolean
     * 	
     *
     * @param string $column 
     * @param mixed $value 
     */
	public function findOneBy($column, $value) {}

}
