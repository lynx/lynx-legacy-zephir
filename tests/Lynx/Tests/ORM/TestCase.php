<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\ORM;

use Lynx\ORM,
    Lynx\DBAl,
    Lynx\Cache,
    Lynx\Annotation,
    Lynx\Stdlib\Events\Manager as EventsManager;

class TestCase
	extends \Lynx\Tests\TestCase
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
		$configuration->setCacheDriver(new \Cacher\Driver\NativeArray());

		$eventManager = new EventsManager();

		$this->_em = new ORM\EntityManager($connection, $configuration, $eventManager);
	}
} 