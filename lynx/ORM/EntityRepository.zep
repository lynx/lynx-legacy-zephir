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

	/**
	 * Find entity by primary key
	 */
    public function find(var id)
    {
		return this->em->createQueryBuilder("find_")
			->limit(1)
			->getQuery()
			->fetchOne();
    }

	/**
	 * Find all entities from repository
	 */
    public function findAll()
    {
		return this->em->createQueryBuilder("find_")
			->limit(1)
			->getQuery()
			->fetchAll();
    }

    public function findBy()
    {

    }

    public function findOneBy()
    {

    }
}