<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\Tests;

use Phalcon\ORM;

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

		$connection = true;
		$this->_em = new ORM\EntityManager($connection);
	}
} 