<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\ORM;

use Lynx\ORM;

class QueryBuilderTest
	extends TestCase
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

    public function testLimitExceptionOnMinusLimit()
    {
        $queryBuilder = $this->_em->createQueryBuilder();
        $this->assertTrue($queryBuilder instanceof ORM\QueryBuilder);

        $this->setExpectedException('\Exception', '$limit must be >= 0');
        $queryBuilder->limit(-1);
    }

    public function testGetSQl()
    {
        $queryBuilder = $this->_em->createQueryBuilder();
        $queryBuilder->select()->from('Model\User', 'u');

        $this->assertTrue($queryBuilder instanceof ORM\QueryBuilder);

        $sql = $queryBuilder->getSQL();
        $this->assertTrue(is_string($sql));
    }

    public function testGetQuery()
    {
        $queryBuilder = $this->_em->createQueryBuilder();
        $queryBuilder->select()->from('Model\User', 'u');
        $this->assertTrue($queryBuilder instanceof ORM\QueryBuilder);

        $query = $queryBuilder->getQuery();
        $this->assertTrue($query instanceof ORM\Query);
    }

    public function testWhere()
    {
        $queryBuilder = $this->_em->createQueryBuilder();

        $queryBuilder = $this->_em->createQueryBuilder()->select()->from('Model\User', 'u')->where('u.id', ':id');
        $this->assertEquals('SELECT * FROM `users` u WHERE u.id = :id', $queryBuilder->getSQL());
        $query = $queryBuilder->getQuery()->bindParam('id', 1);
        $this->assertInternalType('array', $query->fetchArray());

        $queryBuilder = $this->_em->createQueryBuilder()->select()->from('Model\User', 'u')->where('u.id = :id')->orWhere('u.id = :id_next');
        $this->assertEquals('SELECT * FROM `users` u WHERE (u.id = :id OR u.id = :id_next)', $queryBuilder->getSQL());

        $query = $queryBuilder->getQuery()
            ->bindValue('id', 1)
            ->bindValue('id_next', 1);
        $this->assertInternalType('array', $query->fetchArray());

        $queryBuilder = $this->_em->createQueryBuilder()
            ->select()
            ->from('Model\User', 'u')
            ->where('u.id = :id')
            ->andWhere('u.group_id = :group_id');

        $this->assertEquals('SELECT * FROM `users` u WHERE u.id = :id AND u.group_id = :group_id', $queryBuilder->getSQL());

        $query = $queryBuilder->getQuery()
            ->bindValue('id', 1)
            ->bindValue('group_id', 1);

        $this->assertInternalType('array', $query->fetchArray());
    }

    public function testSimpleSelectQuery()
    {
        $queryBuilder = $this->_em->createQueryBuilder();

        $queryBuilder->select()->from('Model\User', 'u');
        $this->assertEquals('SELECT * FROM `users` u', $queryBuilder->getSQL());
        $query = $queryBuilder->getQuery();
        $this->assertInternalType('array', $query->fetchArray());

        $queryBuilder->select()->from('Model\User', 'u')->orderBy('u.id');
        $this->assertEquals('SELECT * FROM `users` u ORDER BY u.id DESC', $queryBuilder->getSQL());
        $query = $queryBuilder->getQuery();
        $this->assertInternalType('array', $query->fetchArray());

        $queryBuilder->limit(1);
        $this->assertEquals('SELECT * FROM `users` u ORDER BY u.id DESC LIMIT 1', $queryBuilder->getSQL());
        $query = $queryBuilder->getQuery();
        $this->assertInternalType('array', $query->fetchArray());

        $queryBuilder->offset(1);
        $this->assertEquals('SELECT * FROM `users` u ORDER BY u.id DESC LIMIT 1,1', $queryBuilder->getSQL());
        $query = $queryBuilder->getQuery();
        $this->assertInternalType('array', $query->fetchArray());

        $this->assertTrue($queryBuilder instanceof ORM\QueryBuilder);
    }

    public function testSelectWithLeftJoinQuery()
    {
        $queryBuilder = $this->_em->createQueryBuilder();
        $queryBuilder->select()->from('Model\User', 'u')->leftJoin('u.Group', 'g');
        $this->assertEquals('SELECT * FROM `users` u LEFT JOIN `groups` `g` ON `u`.`group_id` = `g`.`id`', $queryBuilder->getSQL());
    }
}
