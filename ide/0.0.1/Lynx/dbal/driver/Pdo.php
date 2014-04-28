<?php

namespace Lynx\DBAL\Driver;

class Pdo extends \PDO
{
	protected $eventsManager;

	public function setEventsManager($eventsManager) {}

	public function getEventsManager() {}

	public function __construct($dsn, $username = null, $password = null, $options = null) {}

	public function connect($dsn, $username, $password, $options) {}

}
