/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\ORM;

class Query
{
	protected query;

	protected em;

	public function __construct(var query, <EntityManager> em)
	{
		let this->query = query;
		let this->em = em;
	}

	public function fetchArray($parameters = null)
	{

	}

	public function fetchAll($parameters = null)
	{

	}

	public function fetchObject($parameters = null)
	{

	}

	public function fetchOne($parameters = null)
	{

	}
}