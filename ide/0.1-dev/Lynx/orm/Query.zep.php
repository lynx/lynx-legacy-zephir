<?php

namespace Lynx\ORM;

class Query
{

    const FETCH_INT = 1;


    const FETCH_FLOAT = 1;

    /**
     * Sql plain query
     */
    protected $query;


    protected $em;


    protected $statement;

    /**
     * IdentityMap for SQL. need for hydrate data with many relations (joins)
     */
    protected $identityMap;


    /**
     * Sql plain query
     */
	public function getQuery() {}

    /**
     * IdentityMap for SQL. need for hydrate data with many relations (joins)
     */
	public function getIdentityMap() {}

    /**
     * IdentityMap for SQL. need for hydrate data with many relations (joins)
     *
     * @param mixed $identityMap 
     */
	public function setIdentityMap($identityMap) {}

    /**
     * @param mixed $query 
     * @param mixed $em 
     */
	public function __construct($query, EntityManager $em) {}

    /**
     * Binds a value to a parameter
     *
     * @param mixed $parameter 
     * @param mixed $value 
     * @param mixed $data_type 
     * @return Query 
     */
	public function bindValue($parameter, $value, $data_type = \PDO::PARAM_STR) {}

    /**
     * Binds a parameter to the specified variable name
     *
     * @param mixed $parameter 
     * @param mixed $value 
     * @param mixed $data_type 
     * @param mixed $length 
     * @param mixed $driver_options 
     * @return Query 
     */
	public function bindParam($parameter, $value, $data_type = \PDO::PARAM_STR, $length = null, $driver_options = null) {}

    /**
     * @return array|bool 
     */
	public function getResult() {}

    /**
     * @param mixed $parameters 
     * @return array|bool 
     */
	public function fetchArray($parameters = null) {}

    /**
     * @param mixed $parameters 
     * @return object|bool 
     */
	public function fetchAll($parameters = null) {}

    /**
     * @param mixed $parameters 
     * @return object|bool 
     */
	public function fetchObject($parameters = null) {}

    /**
     * @param mixed $parameters 
     * @return object|bool 
     */
	public function fetchOne($parameters = null) {}

    /**
     * @param mixed $parameters 
     * @param mixed $hydrationMod 
     */
	public function execute($parameters, $hydrationMod = null) {}

    /**
     * Fetch a statement and converts it to the first column to type if it is specified
     *
     * @param mixed $type 
     */
	public function getScalarResult($type = null) {}

}
