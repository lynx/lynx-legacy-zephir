/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\ORM;

class EntityManager
{
    protected unitOfWork;

	protected connection {get};

	public function __construct(var connection)
	{
		let this->connection = connection;
		let this->unitOfWork = new UnitOfWork(this);
	}

	public function flush(var entity)
	{
		
	}

	public function createQueryBuilder()
	{
	    return new Phalcon\ORM\QueryBuilder();
	}
}