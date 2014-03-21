<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\DBAL;

use Lynx\ORM,
    Lynx\DBAl;

class ConnectionTest
	extends TestCase
{
	/**
	 * @var ORM\EntityManager
	 */
	protected $_connection;

	function setUp()
	{
		parent::setUp();

		$this->_connection = \Lynx\Tests\Utils::getConnection();
	}

	public function testIsConnection()
	{
		$this->assertTrue($this->_connection instanceof DBAL\Connection);
	}

	public function testIsConnected()
	{
//		$this->assertTrue($this->_connection->isConnected());
	}
}