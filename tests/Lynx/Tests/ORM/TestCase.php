<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\ORM;

use Lynx\ORM,
    Lynx\DBAl,
    Lynx\Stdlib\EventManager;

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

		$connection = \Lynx\Tests\Utils::getConnection();
		$this->_em = new ORM\EntityManager($connection, new EventManager());
	}
} 