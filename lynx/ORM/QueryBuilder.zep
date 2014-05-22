/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

class QueryBuilder
{
	const SELECT = 1;
	const UPDATE = 2;
	const DELETE = 3;

	protected alias = "default";

	protected from;

	protected parts;

	protected where = [];

	protected type = self::SELECT {get};

	protected limit = null {get};

	protected offset = null {get};

	protected order = null {get};

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

		return this;
	}

	public function rightJoin(var join, var alias)
	{
		var parentAlias;
		let parentAlias = substr(join, 0, strpos(join, '.'));

		return this;
	}

	public function join(var join, var alias)
	{
		return this;
	}

	public function where(var statement)
	{
		let this->where[] = statement;

		return this;
	}

	public function andWhere(var statement)
	{
		let this->where[] = statement;

		return this;
	}

	public function orWhere(var statement)
	{
		var index;
		let index = this->parts["where"];

		let this->where[index][] = statement;

		return this;
	}

	/**
	 * @param statement
	 * @param string sort
	 * @return $this
	 */
	public function orderBy(var statement, string! sort = "DESC") -> <Query>
	{
		let this->order = statement . " " . sort;

		return this;
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

		return this;
	}

	public function offset(int offset)
	{
		let this->offset = offset;

		return this;
	}

	inline protected function wrap(string id)
    {
        return "`" . id . "`";
    }

	public function getSQL() -> string
	{
		var sql;

		if (is_null(this->from)) {
			throw new \Exception("From field must be set");
		}

		var rootModel;
		let rootModel = this->em->getModelsManager()->get(this->from);

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

		let sql .= " FROM ".this->wrap(rootModel->getTablename())." ".this->alias;

		if (count(this->where) > 0) {
			let sql .= " WHERE ".this->where[0];
		}

		if (this->order) {
			let sql .= " ORDER BY ".this->order;
		}

		if (!is_null(this->limit)) {
			let sql .= " LIMIT ".this->limit;

			if (!is_null(this->offset)) {
				let sql .= ",".this->offset;
			}
		}

		return sql;
	}

	public function getQuery() -> <Query>
	{
		var query, identityMap;

		let identityMap = new QueryIdentityMap();
		let query = this->em->createQuery(this->getSQL());

		return query;
	}
}