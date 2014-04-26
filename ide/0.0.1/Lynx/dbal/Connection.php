<?php

namespace Lynx\DBAL;

class Connection
{
	protected $driver;

	public function getDriver() {}

	public function __construct($driver, $parameters) {}

	public function prepare($statement) {}

}
