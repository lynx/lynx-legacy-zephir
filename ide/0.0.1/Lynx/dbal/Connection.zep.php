<?php

namespace Lynx\DBAL;

class Connection
{

    protected $driver;


	public function getDriver() {}

    /**
     * @param mixed $parameters 
     * @param EventsManager $eventsManager 
     */
	public function __construct($parameters, $eventsManager = null) {}

    /**
     * @param mixed $statement 
     */
	public function prepare($statement) {}

}
