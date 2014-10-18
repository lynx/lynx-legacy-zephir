<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\DBAL;

use Lynx\ORM;
use Lynx\DBAl;
use Lynx\Tests\Utils;

class ConnectionTest
	extends TestCase
{
	/**
	 * @var ORM\EntityManager
	 */
	protected $_connection;

    /**
     * Set connection
     */
    public function setUp()
	{
		$this->_connection = Utils::getConnection();
	}

    public function testGetDriver()
    {
        $this->assertTrue(true);
        $this->assertInstanceOf('Lynx\DBAL\Driver\\' . $this->getDriverName(), $this->_connection->getDriver());
    }

    public function testPrepare()
    {
        $sql = 'SELECT * FROM `users`';
        $this->assertInstanceOf('Lynx\DBAL\Driver\PDO\Statement', $this->_connection->prepare($sql));
    }

	public function testIsConnection()
	{
		$this->assertTrue($this->_connection instanceof DBAL\Connection);
	}
}