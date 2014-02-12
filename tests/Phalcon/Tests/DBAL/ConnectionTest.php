<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\Tests\DBAL;

use Phalcon\ORM,
	Phalcon\DBAl;

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

		$this->_connection = \Phalcon\Tests\Utils::getConnection();
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