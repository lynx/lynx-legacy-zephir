<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests;

use Lynx\DBAL;

class Utils
{
	public static function getConnection()
	{
		$driver = new DBAl\Driver\Pdo('mysql:host=localhost;dbname='.$GLOBALS['db_name'], $GLOBALS['db_username'], $GLOBALS['db_password'], array());
		$connection = new DBAL\Connection($driver, null);

		return $connection;
	}
}
