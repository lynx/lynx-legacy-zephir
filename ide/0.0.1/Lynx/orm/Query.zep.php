<?php

namespace Lynx\ORM;

class Query
{

    protected $query;

    protected $em;

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

}
