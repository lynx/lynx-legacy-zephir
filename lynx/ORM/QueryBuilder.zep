/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

class QueryBuilder
{
	const SELECT = 1;
	const UPDATE = 2;
	const DELETE = 3;

	protected type = self::SELECT;

	protected limit = null {get};

	protected offset = 0;

	protected em;

	public function __construct(<EntityManager> em)
	{
		let this->em = em;
	}

	public function select()
	{
		let this->type = self::SELECT;
	}

	public function delete()
	{
		let this->type = self::DELETE;
	}

	public function update()
	{
		let this->type = self::UPDATE;
	}

	public function from()
	{

	}

	public function leftJoin()
	{

	}

	public function rightJoin()
	{

	}

	public function join()
	{

	}

    /**
     * Set limit to the query
     */
	public function limit(int limit)
	{
	    if (limit <= 0) {
	        throw new \Exception("$limit must be >= 0");
	    }

		let this->limit = limit;
	}

	public function offset(int offset)
	{
		let this->offset = offset;
	}

	public function getSQL() -> string
	{
		var sql;

		switch(this->type) {
			case self::SELECT:
				let sql = "SELECT ";
				break;
			case self::UPDATE:
				let sql = "UPDATE ";
				break;
			case self::DELETE:
				let sql = "DELETE ";
				break;
		}

		return sql;
	}

	public function getQuery()
	{
		var query;
		let query = this->em->createQuery(this->getSQL());


		return query;
	}
}