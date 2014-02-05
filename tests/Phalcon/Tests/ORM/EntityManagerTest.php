<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\Tests\ORM;

use Phalcon\ORM;

class EntityManagerTest
	extends \PHPUnit_Framework_TestCase
{
	protected $_em;

	function setUp()
	{
		parent::setUp();

		$connection = true;
		$this->_em = new \Phalcon\ORM\EntityManager($connection);
	}

	public function testCreateQueryBuilder()
	{
		$queryBuilder = $this->_em->createQueryBuilder();
		$this->assertTrue($queryBuilder instanceof \Phalcon\ORM\QueryBuilder);
	}
} 