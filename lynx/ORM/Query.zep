/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

class Query
{
	protected query;

	protected em;

	public function __construct(var query, <EntityManager> em)
	{
		let this->query = query;
		let this->em = em;
	}

	public function fetchArray(var parameters = null)
	{
		return this->getResult();
	}

	public function getResult()
	{
		var connection, statement;
		let connection = this->em->getConnection();

		let statement = connection->prepare(this->query);
		statement->execute();
		return statement->fetchAll();
	}

	public function fetchAll($parameters = null)
	{
		return this->getResult();
	}

	public function fetchObject($parameters = null)
	{
		return this->getResult();
	}

	public function fetchOne($parameters = null)
	{
		return this->getResult();
	}
}