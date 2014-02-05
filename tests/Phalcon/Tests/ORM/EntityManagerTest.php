<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\Tests\ORM;

use Phalcon\ORM;

class EntityManagerTest
	extends \Phalcon\Tests\TestCase
{
	public function testCreateQueryBuilder()
	{
		$queryBuilder = $this->_em->createQueryBuilder();
		$this->assertTrue($queryBuilder instanceof \Phalcon\ORM\QueryBuilder);
	}
}