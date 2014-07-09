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
	 * @param $id
	 * @return object|boolean
	 */
    public function find(var id)
    {
		return this->createQueryBuilder("find_")
			->where("find_.id = :id")
			->limit(1)
			->getQuery()
			->bindValue("id", id, \PDO::PARAM_INT)
			->fetchOne();
    }

	/**
	 * Count all rows
	 */
    public function count() -> int
    {
    	return this->createQueryBuilder("count_")
    		->select("COUNT(*)")
    		->getQuery()
    		->getScalarResult(ORM\Query::FETCH_INT);
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

	/**
	 * Find all entities from repository by column = :value
	 * @param string $column
	 * @param $value
	 * @return object|boolean
	 */
    public function findBy(string! column, var value)
    {
		return this->createQueryBuilder("find_")
			->where("find_." .column. " = :column")
			->getQuery()
			->bindValue("column", value, \PDO::PARAM_INT)
			->fetchAll();
    }

	/**
	 * Find one entity from repository by column = :value
	 * @param string $column
	 * @param $value
	 * @return object|boolean
	 */
    public function findOneBy(string! column, var value)
    {
		return this->createQueryBuilder("find_")
			->where("find_.`" .column. "` = :column")
			->limit(1)
			->getQuery()
			->bindValue("column", value, \PDO::PARAM_INT)
			->fetchOne();
    }
}