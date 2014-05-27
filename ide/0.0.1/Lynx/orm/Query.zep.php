<?php

namespace Lynx\ORM;

class Query
{

    protected $query;

    protected $em;

    protected $statement;

    /**
     * @param mixed $query 
     * @param EntityManager $em 
     */
	public function __construct($query, $em) {}

    /**
     * @param mixed $parameters 
     */
	public function fetchArray($parameters = null) {}

    /**
     * Binds a value to a parameter
     * 	
     *
     * @param mixed $parameter 
     * @param mixed $value 
     * @param mixed $data_type 
     */
	public function bindValue($parameter, $value, $data_type = \PDO::PARAM_STR) {}

    /**
     * Binds a parameter to the specified variable name
     * 	
     *
     * @param mixed $parameter 
     * @param mixed $value 
     * @param mixed $data_type 
     * @param mixed $lenght 
     * @param mixed $driver_options 
     */
	public function bindParam($parameter, $value, $data_type = \PDO::PARAM_STR, $lenght = null, $driver_options = null) {}

    /**
     * @return mixed
     * 	
     */
	public function getResult() {}

    /**
     * @return array|boolean
     * 	
     *
     * @param mixed $parameters 
     */
	public function fetchAll($parameters = null) {}

    /**
     * @return object|boolean
     * 	
     *
     * @param mixed $parameters 
     */
	public function fetchObject($parameters = null) {}

    /**
     * @param mixed $parameters 
     */
	public function fetchOne($parameters = null) {}

    /**
     * @param mixed $parameters 
     * @param mixed $hydrationMod 
     */
	public function execute($parameters, $hydrationMod = null) {}


	public function getScalarResult() {}

}
