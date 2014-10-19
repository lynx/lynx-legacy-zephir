<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests;

use Lynx\DBAL;
use Lynx\Stdlib\Events\Manager;

class Utils
{
	public static function getConnection()
	{
        $eventsManager = new Manager();

        switch ($GLOBALS['db_type']) {
            case 'mysql':
            case 'pdo_mysql':
                $driver = new DBAl\Driver\Mysql('mysql:host=localhost;dbname='.$GLOBALS['db_name'].';charset=UTF8', $GLOBALS['db_username'], $GLOBALS['db_password'], array());
                break;
            case 'pgsql':
            case 'pdo_pgsql':
                $driver = new DBAl\Driver\Pgsql('pgsql:host=localhost;dbname='.$GLOBALS['db_name'], $GLOBALS['db_username'], $GLOBALS['db_password'], array());
                break;
            default:
                throw new \InvalidArgumentException('Unsupported db type : ' . $GLOBALS['db_type']);
                break;
        }

		$connection = new DBAL\Connection(['driver' => $driver], $eventsManager);

		return $connection;
	}
}
