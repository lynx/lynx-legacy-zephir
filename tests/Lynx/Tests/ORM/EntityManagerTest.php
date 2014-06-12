<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\ORM;

use Lynx\ORM,
    Lynx\DBAL;

class EntityManagerTest
	extends TestCase
{
	public function testCreateQueryBuilder()
	{
		$queryBuilder = $this->_em->createQueryBuilder();
		$this->assertTrue($queryBuilder instanceof ORM\QueryBuilder);
	}

	public function testFlush()
	{
		$this->_em->flush(array());
	}

	public function testGetConnection()
	{
		$this->assertTrue($this->_em->getConnection() instanceof DBAL\Connection);
	}

	public function testCreateQuery()
	{
		$sql = "SELECT * FROM `table`";

		$queryBuilder = $this->_em->createQuery($sql);
		$this->assertTrue($queryBuilder instanceof ORM\Query);
	}

    public function testGetRepositorySuccess()
    {
        $result = $this->_em->getRepository('Model\User');
        $this->assertInstanceOf('Lynx\\ORM\\EntityRepository', $result);
    }

	public function testGetModelsManager()
	{
		$result = $this->_em->getModelsManager();
		$this->assertInstanceOf('Lynx\\ORM\\ModelsManager', $result);
	}
}