<?php

namespace Lynx\DBAL;

class Connection
{

    protected $driver;


	public function getDriver() {}

    /**
     * @param variable $parameters 
     * @param EventsManager $eventsManager 
     */
	public function __construct($parameters, $eventsManager = null) {}

    /**
     * @param variable $statement 
     */
	public function prepare($statement) {}

}
