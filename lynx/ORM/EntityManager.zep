/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

use Lynx\DBAL\Connection;
use Lynx\Stdlib\EventManager;

class EntityManager
{
    /**
     * @var UnitOfWork
     */
    protected unitOfWork;

	protected connection {get};

	protected modelsManager {get};

	protected eventManager {get};

	protected repositories;

	public function __construct(<Connection> connection, <EventManager> eventManager)
	{
		let this->eventManager = eventManager;
		let this->connection = connection;
		let this->unitOfWork = new UnitOfWork(this);
		let this->modelsManager = new ModelsManager();
	}

	public function flush(var entity)
	{

	}

	public function remove(object! entity)
	{

	}

	public function beginTransaction()
	{
		this->connection->beginTransaction();
	}

    public function commit()
    {
        this->connection->commit();
    }


    public function rollback()
    {
        this->connection->rollback();
    }

    
	public function getRepository(string! entityName)
	{
		var modelInfo;

		if (isset(this->repositories[entityName])) {
			return this->repositories[entityName];
		}

       	let modelInfo = this->modelsManager->get(entityName);
       	let this->repositories[entityName] = new EntityRepository(this, modelInfo);
       	return this->repositories[entityName];
	}

	public function createQueryBuilder() -> <QueryBuilder>
	{
	    return new QueryBuilder(this);
	}

	public function createQuery(var sql) -> <Query>
	{
		return new Query(sql, this);
	}
}