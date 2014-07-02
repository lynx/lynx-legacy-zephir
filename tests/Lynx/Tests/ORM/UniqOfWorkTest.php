<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\ORM;

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

    public function testInsertData()
    {
        $new = new User();
        $new->name = "Test string";
        $new->group_id = 1;

        $collection = $this->entityManager->getRepository('Model\User')->findAll();

        $this->unitOfWork->insert($new);
        $this->unitOfWork->commit();

        $newCollection = $this->entityManager->getRepository('Model\User')->findAll();
        $this->assertSame(count($collection)+1, count($newCollection));
    }
}