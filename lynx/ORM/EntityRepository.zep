/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

use Lynx\ORM;

class EntityRepository
{
    /**
     * @var EntityManager
     */
    protected em {get};

    /**
     * @var ModelMetaData
     */
    protected modelWrapper;

    public function __construct(<EntityManager> em, <ModelMetaData> modelWrapper)
    {
        let this->em = em;
        let this->modelWrapper = modelWrapper;
    }

    /**
     * @todo set alias to QueryBuilder
     * @return QueryBuilder
     */
    public function createQueryBuilder(var alias) -> <QueryBuilder>
    {
        return this->em->createQueryBuilder();
    }

    public function find(var id)
    {

    }

    public function findAll()
    {

    }

    public function findBy()
    {

    }

    public function findOneBy()
    {

    }
}