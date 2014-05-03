<?php

namespace Lynx\DBAL\Driver;

class Pdo extends \PDO
{
	protected $eventsManager;
	protected $dsn;
	protected $username;
	protected $password;
	protected $options;
	protected $isConnect = false;

	public function setEventsManager($eventsManager) {}

	public function getEventsManager() {}

	public function __construct($dsn, $username = null, $password = null, $options = null) {}

}
