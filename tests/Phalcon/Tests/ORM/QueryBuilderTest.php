<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\Tests\ORM;

use Phalcon\ORM;

class QueryBuilderTest
	extends \Phalcon\Tests\TestCase
{
	public function testLimit()
	{
		$queryBuilder = $this->_em->createQueryBuilder();
		$this->assertTrue($queryBuilder instanceof ORM\QueryBuilder);

		$queryBuilder->limit(1);
		$this->assertTrue($queryBuilder->getLimit() === 1);
		$queryBuilder->limit(100);
		$this->assertTrue($queryBuilder->getLimit() === 100);
	}

	public function testGetSQl()
	{
		$queryBuilder = $this->_em->createQueryBuilder();
		$this->assertTrue($queryBuilder instanceof ORM\QueryBuilder);

		$sql = $queryBuilder->getSQL();
		$this->assertTrue(is_string($sql));
	}

	public function testGetQuery()
	{
		$queryBuilder = $this->_em->createQueryBuilder();
		$this->assertTrue($queryBuilder instanceof ORM\QueryBuilder);

		$query = $queryBuilder->getQuery();
		$this->assertTrue($query instanceof ORM\Query);
	}
} 