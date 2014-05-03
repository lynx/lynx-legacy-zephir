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

	public function setEventsManager($eventsManager) {}

	public function getEventsManager() {}

	public function __construct($dsn, $username = null, $password = null, $driverOptions = array()) {}

	public function connect() {}

	public function prepare($statement) {}

}
