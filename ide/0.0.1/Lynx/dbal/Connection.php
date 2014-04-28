<?php

namespace Lynx\DBAL;

class Connection
{
	protected $driver;

	public function getDriver() {}

	public function __construct($driver, $parameters, $eventsManager = null) {}

	public function prepare($statement) {}

}
