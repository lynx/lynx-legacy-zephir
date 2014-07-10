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

	protected columns = "*";

	protected where = [];

	protected type = self::SELECT {get};

	protected limit = null {get};

	protected offset = null {get};

	protected order = null {get};

	protected rootModel;

	protected em;

	public function __construct(<EntityManager> em)
	{
		let this->em = em;
	}

	public function select(var columns = null)
	{
		let this->type = self::SELECT;

		if (!is_null(columns)) {
			let this->columns  = columns;
		}

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

		let this->rootModel = this->em->getModelsManager()->get(this->from);
		if (is_null(this->rootModel)) {
			throw new \Exception("Cant find model by alias '" . this->from . "'");
		}

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
		var tmp, property;
		let tmp = explode("=", statement);

		let property = this->rootModel->getProperty(trim(tmp[0]));
		let statement = property["column"]["name"] . " =" . tmp[1];

		let this->where[] = statement;

		return this;
	}

	public function andWhere(var statement)
	{
		var tmp, property;

		let tmp = explode("=", statement);

		let property = this->rootModel->getProperty(trim(tmp[0]));
		let statement = property["column"]["name"] . " =" . tmp[1];

		let this->where[] = statement;

		return this;
	}

	public function orWhere(var statement)
	{
		var index;
		let index = key(this->where);

		let this->where[index] = "(" . this->where[index] . " OR " . statement . ")";

		return this;
	}

	/**
	 * Set order by to the query
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

		switch(this->type) {
			case self::SELECT:
				let sql = "SELECT " . this->columns;
				break;
			case self::UPDATE:
				let sql = "UPDATE ";
				break;
			case self::DELETE:
				let sql = "DELETE ";
				break;
		}

		let sql .= " FROM ".this->wrap(this->rootModel->getTablename())." ".this->alias;

		if (count(this->where) > 0) {
			let sql .= " WHERE ".implode(" AND ", this->where);
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
		var query, identityMap, sql;

		let sql = this->getSQL();
		let identityMap = new QueryIdentityMap();
		identityMap->setRootModel(this->rootModel);
		identityMap->setRootAlias(this->alias);

		let query = this->em->createQuery(sql);
		query->setIdentityMap(identityMap);

		return query;
	}
}