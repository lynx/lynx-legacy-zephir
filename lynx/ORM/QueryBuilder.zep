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


	public function from(var from, var alias)
	{

	}

	public function leftJoin(var join, var alias)
	{
		var parentAlias;
		let parentAlias = substr(join, 0, strpos(join, '.'));
	}

	public function rightJoin(var join, var alias)
	{
		var parentAlias;
		let parentAlias = substr(join, 0, strpos(join, '.'));
	}

	public function join(var join, var alias)
	{

	}

	public function where(var statement)
	{

	}

	public function andWhere(var statement)
	{

	}

	public function orWhere(var statement)
	{

	}

	public function orderBy(var sort)
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