/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

use \Lynx\ORM\QueryBuilder\Expression\Join;

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

	protected joins = null {get};

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

	inline protected function prepareJoin(var joinType, var parentAlias, var modelName, var alias)
	{
		var relationModel, targetProperty;
		//let relationModel = this->em->getModelsManager()->get(modelName);

		let targetProperty = this->rootModel->getProperty(modelName);
//		var_dump(targetProperty);
//		die();
		//let this->joins = new QueryBuilder\Expression\Join(joinType, x);
	}

	public function leftJoin(var join, var alias)
	{
		var aliases;
		let aliases = explode(".", join);

		this->prepareJoin(Join::LEFT_JOIN, aliases[0], aliases[1], alias);

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
		let this->where[] = this->prepareWhereStatement(statement);

		return this;
	}

	public function andWhere(var statement)
	{
		let this->where[] = this->prepareWhereStatement(statement);

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

		if (count(this->joins) > 0) {
		}

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

	inline protected function prepareWhereStatement(statement)
	{
		var tmp, property, tmpField;
		let tmp = explode("=", statement);

		let tmpField = explode(".", trim(tmp[0]));
		if (is_array(tmpField)) {
			let property = this->rootModel->getColumn(trim(tmpField[1]));;
			let statement = tmpField[0] . "." . property->name . " =" . tmp[1];
		} else {
			let property = this->rootModel->getColumn(trim(tmp[0]));
			let statement = property->name . " =" . tmp[1];
		}

		return statement;
	}
}