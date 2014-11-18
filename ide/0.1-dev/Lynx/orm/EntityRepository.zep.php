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
     * @return EntityManager 
     */
	public function getEm() {}

    /**
     * @param mixed $em 
     * @param mixed $modelWrapper 
     */
	public function __construct(EntityManager $em, ModelMetaData $modelWrapper) {}

    /**
     * @param string $alias 
     * @return QueryBuilder 
     */
	public function createQueryBuilder($alias) {}

    /**
     * Find an entity by its primary key
     *
     * @param mixed $id 
     * @param $id  
     * @return object|boolean 
     */
	public function find($id) {}

    /**
     * Count all rows
     *
     * @return int 
     */
	public function count() {}

    /**
     * Find all entities from a repository
     */
	public function findAll() {}

    /**
     * Find all entities from a repository by column = :value
     *
     * @param string $column 
     * @param mixed $value 
     * @param string $$column 
     * @param $value  
     * @return object|boolean 
     */
	public function findBy($column, $value) {}

    /**
     * Find one entity from a repository by column = :value
     *
     * @param string $column 
     * @param mixed $value 
     * @param string $$column 
     * @param $value  
     * @return object|boolean 
     */
	public function findOneBy($column, $value) {}

}
