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

	public function testCreateQuery()
	{
		$sql = "SELECT * FROM `table`";

		$queryBuilder = $this->_em->createQuery($sql);
		$this->assertTrue($queryBuilder instanceof \Phalcon\ORM\Query);
	}
}