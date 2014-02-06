/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\ORM;

class QueryBuilder
{
	protected limit = null {get};

	protected offset = 0;

	protected em;

	public function __construct(<EntityManager> em)
	{
		let this->em = em;
	}

	public function select()
	{

	}

	public function delete()
	{

	}

	public function update()
	{

	}

	public function from()
	{

	}

	public function leftJoin()
	{

	}

	public function limit(int limit)
	{
		let this->limit = limit;
	}

	public function offset(int offset)
	{
		let this->offset = offset;
	}

	public function getSQL()
	{
		var sql;

		let sql = "";

		return sql;
	}

	public function getQuery()
	{
		var query;
		let query = this->em->createQuery(this->getSQL());


		return query;
	}
}