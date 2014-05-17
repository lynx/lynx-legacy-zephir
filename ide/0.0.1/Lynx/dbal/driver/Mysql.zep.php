<?php

namespace Lynx\DBAL\Driver;

class Mysql
{

    protected $eventsManager;

    protected $dsn;

    protected $username;

    protected $password;

    protected $driverOptions;

    protected $connection;

    /**
     * @param variable $eventsManager 
     */
	public function setEventsManager($eventsManager) {}


	public function getEventsManager() {}

    /**
     * @param string $dsn 
     * @param variable $username 
     * @param variable $password 
     * @param array $driverOptions 
     */
	public function __construct($dsn, $username = null, $password = null, $driverOptions = array()) {}


	public function connect() {}

    /**
     * @param variable $statement 
     */
	public function prepare($statement) {}

}
