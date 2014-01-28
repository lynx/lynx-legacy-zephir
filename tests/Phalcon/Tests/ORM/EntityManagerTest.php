<?php
/**
 * Created by PhpStorm.
 * User: zaets28rus
 * Date: 27.01.14
 * Time: 15:58
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