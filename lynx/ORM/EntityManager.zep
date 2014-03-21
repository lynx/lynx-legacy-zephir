/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

use Lynx\DBAL\Connection;

class EntityManager
{
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

	public function createQueryBuilder()
	{
	    return new QueryBuilder(this);
	}

	public function createQuery(var sql)
	{
		return new Query(sql, this);
	}
}