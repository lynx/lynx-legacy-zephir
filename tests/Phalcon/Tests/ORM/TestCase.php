<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\Tests\ORM;

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

		$connection = \Phalcon\Tests\Utils::getConnection();
		$this->_em = new ORM\EntityManager($connection);
	}
} 