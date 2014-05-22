<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\ORM;

use Lynx\ORM,
    Lynx\DBAL;

class EntityRepositoryTest
	extends TestCase
{
    /**
     * @return ORM\EntityRepository
     */
    protected function getUserRepository()
	{
        return $this->_em->getRepository('Model\User');
	}

    public function testFindAll()
    {
        $repository = $this->getUserRepository();
        $this->assertTrue($repository->findAll() !== false);
    }

    public function testFind()
    {
        $repository = $this->getUserRepository();
        $this->assertTrue($repository->find(1) !== false);

        /**
         * not found
         */
        $this->assertFalse($repository->find(999));
    }
}