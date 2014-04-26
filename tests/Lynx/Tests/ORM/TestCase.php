<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\ORM;

use Lynx\ORM,
    Lynx\DBAl,
    Lynx\Cache,
    Lynx\Annotation,
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

		$configuration = new ORM\Configuration();
		$configuration->setCacheDriver(new Cache\NativeArray());


		$eventManager = new EventManager();

		$this->_em = new ORM\EntityManager($connection, $configuration, $eventManager);
	}
} 