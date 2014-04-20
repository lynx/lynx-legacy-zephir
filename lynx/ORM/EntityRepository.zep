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
    protected em;

    public function __construct(<EntityManager> em)
    {
        let this->em = em;
    }

    /**
     * @todo set alias to QueryBuilder
     * @return QueryBuilder
     */
    public function createQueryBuilder(var alias) -> <QueryBuilder>
    {
        return this->em->createQueryBuilder();
    }
}