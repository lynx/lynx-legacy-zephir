<?php

namespace Lynx\ORM;

class Query
{

    protected $query;

    protected $em;

    protected $statement;

    /**
     * @param variable $query 
     * @param EntityManager $em 
     */
	public function __construct($query, $em) {}

    /**
     * @param variable $parameters 
     */
	public function fetchArray($parameters = null) {}

    /**
     * 	 * Binds a value to a parameter
     * 	
     *
     * @param variable $parameter 
     * @param variable $value 
     * @param variable $data_type 
     */
	public function bindValue($parameter, $value, $data_type = \PDO::PARAM_STR) {}

    /**
     * 	 * Binds a parameter to the specified variable name
     * 	
     *
     * @param variable $parameter 
     * @param variable $value 
     * @param variable $data_type 
     * @param variable $lenght 
     * @param variable $driver_options 
     */
	public function bindParam($parameter, $value, $data_type = \PDO::PARAM_STR, $lenght = null, $driver_options = null) {}

    /**
     * 	 * @return mixed
     * 	
     */
	public function getResult() {}

    /**
     * @param variable $parameters 
     */
	public function fetchAll($parameters = null) {}

    /**
     * @param variable $parameters 
     */
	public function fetchObject($parameters = null) {}

    /**
     * @param variable $parameters 
     */
	public function fetchOne($parameters = null) {}

    /**
     * @param variable $parameters 
     * @param variable $hydrationMod 
     */
	public function execute($parameters, $hydrationMod = null) {}


	public function getScalarResult() {}

}
