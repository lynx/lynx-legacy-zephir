<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\Tests;

use Phalcon\ORM,
	Phalcon\DBAl;

class TestCase
	extends \PHPUnit_Framework_TestCase
{
	/**
	 * @var ORM\EntityManager
	 */
	protected $_em;

	function setUp()
	{
		parent::setUp();

		$driver = new DBAl\Driver\Pdo('dsn', 'root', 'root', array());
		$connection = new DBAL\Connection($driver, null);

		$this->_em = new ORM\EntityManager($connection);
	}
} 