<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\Tests;


class TestCase
	extends \PHPUnit_Framework_TestCase
{
	protected $_em;

	function setUp()
	{
		parent::setUp();

		$connection = true;
		$this->_em = new \Phalcon\ORM\EntityManager($connection);
	}
} 