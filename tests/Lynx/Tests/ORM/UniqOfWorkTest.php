<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\ORM;

use Lynx\DBAL\RawValue;
use Lynx\ORM;
use Lynx\DBAL;
use Lynx\Stdlib\Events\Manager;
use Lynx\Tests\Utils;
use Model\User;

class UniqOfWorkTest
	extends TestCase
{
    /**
     * @var ORM\EntityManager
     */
    protected $entityManager;

    /**
     * @var ORM\UnitOfWork
     */
    protected $unitOfWork;

    /**
     * Set connection
     */
    public function setUp()
    {
        $configuration = new ORM\Configuration();
        $eventsManager = new Manager();

        $this->entityManager = new ORM\EntityManager(Utils::getConnection(), $configuration, $eventsManager);
        $this->unitOfWork = $this->entityManager->getUnitOfWork();
    }

    public function testSimpleWorkflow()
    {
        $entity = new User();
        $entity->name = "Test string";
        $entity->group_id = 1;
        $entity->dateCreated = new RawValue('NOW()');

        $count = $this->entityManager->getRepository('Model\User')->count();

        $this->unitOfWork->insert($entity);
        $this->unitOfWork->commit();

        $this->assertInternalType('int', $entity->id);
        $newCount = $this->entityManager->getRepository('Model\User')->count();
        $count = $count+1;
        $this->assertSame($count, $newCount);

        $this->unitOfWork->delete($entity);
        $this->unitOfWork->commit();

        $newCount = $this->entityManager->getRepository('Model\User')->count();
        $this->assertSame($count-1, $newCount);
    }
}