/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

use Lynx\DBAL\Connection;

class EntityManager
{
    /**
     * @var UnitOfWork
     */
    protected unitOfWork;

	protected connection {get};

	public function __construct(<Connection> connection)
	{
		let this->connection = connection;
		let this->unitOfWork = new UnitOfWork(this);
	}

	public function flush(var entity)
	{

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