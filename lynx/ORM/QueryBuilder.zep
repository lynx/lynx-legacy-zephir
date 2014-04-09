/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

class QueryBuilder
{
	const SELECT = 1;
	const UPDATE = 2;
	const DELETE = 3;

	protected alias;

	protected from;

	protected parts;

	protected where = null;

	protected type = self::SELECT {get};

	protected limit = null {get};

	protected offset = null {get};

	protected em;

	public function __construct(<EntityManager> em)
	{
		let this->em = em;
	}

	public function select()
	{
		let this->type = self::SELECT;

		return this;
	}

	public function delete()
	{
		let this->type = self::DELETE;

		return this;
	}

	public function update()
	{
		let this->type = self::UPDATE;

		return this;
	}


	public function from(var from, var alias)
	{
		let this->from = from;
		let this->alias = alias;

		return this;
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
		let this->where[] = statement;
	}

	public function andWhere(var statement)
	{
		let this->where[] = statement;
	}

	public function orWhere(var statement)
	{
		var index;
		let index = this->parts["where"];

		let this->where[index][] = statement;
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

		if (is_null(this->from)) {
			throw new \Exception("From field must be set");
		}

		switch(this->type) {
			case self::SELECT:
				let sql = "SELECT *";
				break;
			case self::UPDATE:
				let sql = "UPDATE ";
				break;
			case self::DELETE:
				let sql = "DELETE ";
				break;
		}

		let sql .= " FROM ".this->from;

		if (!is_null(this->limit)) {
			let sql .= " LIMIT ".this->limit;

			if (!is_null(this->offset)) {
				let sql .= ",".this->offset;
			}
		}

		return sql;
	}

	public function getQuery()
	{
		var query;
		let query = this->em->createQuery(this->getSQL());

		if (!is_null(this->where)) {

		}

		return query;
	}
}