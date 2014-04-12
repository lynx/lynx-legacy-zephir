<?php

namespace Lynx\DBAL\Driver;

class Pdo
{
	protected $_pdo;

	public function __construct($dsn, $username = null, $password = null, $options = null) {}

	public function connect() {}

	public function query($sqlStatement, $bindParams = null, $bindTypes = null) {}

}
