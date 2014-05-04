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
     * @param string alias
     * @return QueryBuilder
     */
    public function createQueryBuilder(string! alias) -> <QueryBuilder>
    {
        return this->em->createQueryBuilder()
        	->from(this->modelWrapper->classname, alias);
    }

	/**
	 * Find entity by primary key
	 */
    public function find(var id)
    {
		return this->createQueryBuilder("find_")
			->where("find_.id = ".id, id)
			->limit(1)
			->getQuery()
			->fetchOne();
    }

	/**
	 * Find all entities from repository
	 */
    public function findAll()
    {
		return this->createQueryBuilder("findall_")
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