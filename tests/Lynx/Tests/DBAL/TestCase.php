<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\DBAL;

use Lynx\ORM,
    Lynx\DBAl;

class TestCase
	extends \PHPUnit_Framework_TestCase
{
    /**
     * @return string
     */
    public function getDriverName()
    {
        switch ($GLOBALS['db_type']) {
            case 'mysql':
            case 'pdo_mysql':
                return 'Mysql';
                break;
            case 'pgsql':
            case 'pdo_pgsql':
                return 'Pgsql';
                break;
        }
    }
}