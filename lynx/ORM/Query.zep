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

	/**
	 * @return mixed
	 */
	public function getResult()
	{
		var connection, statement, result;
		let connection = this->em->getConnection();

		let statement = connection->prepare(this->query);
		statement->execute();
		let result = statement->fetchAll();

		if (count(result) == 0) {
			return false;
		}

		return result;
	}

	public function fetchAll(var parameters = null)
	{
		return this->getResult();
	}

	public function fetchObject(var parameters = null)
	{
		return this->getResult();
	}

	public function fetchOne(var parameters = null)
	{
		return this->getResult();
	}
}