/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

use Lynx\ORM\QueryBuilder\Expression\Join;
use Lynx\ORM\QueryBuilder\Expression\Where;

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

	protected joins = [] {get};

	protected rootModel;

	protected em;

	public function __construct(<EntityManager> em)
	{
		let this->em = em;
	}

	public function select(var columns = null) -> <QueryBuilder>
	{
		let this->type = self::SELECT;

		if (!is_null(columns)) {
			let this->columns  = columns;
		}

		return this;
	}

	public function delete() -> <QueryBuilder>
	{
		let this->type = self::DELETE;

		return this;
	}

	public function update() -> <QueryBuilder>
	{
		let this->type = self::UPDATE;

		return this;
	}

	public function from(var from, var alias) -> <QueryBuilder>
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
		var relationModel, targetProperty, condition;

		let targetProperty = this->rootModel->getProperty(modelName);
		let relationModel = this->em->getModelsManager()->get(targetProperty->targetEntity);

		let condition = this->wrap(parentAlias) . "." . this->wrap(targetProperty->name) . " = " . this->wrap(alias) . "." . this->wrap(targetProperty->referencedColumnName);
		let this->joins[alias] = new Join(joinType, this->wrap(relationModel->getTableName()), this->wrap(alias), condition);
	}

	public function leftJoin(var join, var alias) -> <QueryBuilder>
	{
		var aliases;
		let aliases = explode(".", join);

		this->prepareJoin(Join::LEFT_JOIN, aliases[0], aliases[1], alias);

		return this;
	}

	public function rightJoin(var join, var alias) -> <QueryBuilder>
	{
		var aliases;
		let aliases = explode(".", join);

		this->prepareJoin(Join::RIGHT_JOIN, aliases[0], aliases[1], alias);

		return this;
	}

	public function innerJoin(var join, var alias) -> <QueryBuilder>
	{
		var aliases;
		let aliases = explode(".", join);

		this->prepareJoin(Join::INNER_JOIN, aliases[0], aliases[1], alias);

		return this;
	}

	public function join(var join, var alias) -> <QueryBuilder>
	{
		var aliases;
		let aliases = explode(".", join);

		this->prepareJoin("", aliases[0], aliases[1], alias);

		return this;
	}

	public function where(var column, var value, var comparison = Where::EQUAL) -> <QueryBuilder>
	{
		let this->where[] = this->prepareWhereStatement(column, value, comparison);

		return this;
	}

	public function orWhere(var column, var value, var comparison = Where::EQUAL) -> <QueryBuilder>
	{
		var index, statement;

		let statement = this->prepareWhereStatement(column, value, comparison);
		let index = key(this->where);

		let this->where[index] = "(" . this->where[index] . " OR " . statement . ")";

		return this;
	}

	inline protected function prepareWhereStatement(var column, var value, var comparison)
	{
		var tmpField, property, propertyStatement;

		let tmpField = explode(".", trim(column));

		if (is_array(tmpField)) {
			let property = this->rootModel->getColumn(trim(tmpField[1]));;
			let propertyStatement = tmpField[0] . "." . property->name;
		} else {
			let property = this->rootModel->getColumn(trim(tmpField[0]));
			let propertyStatement = property->name;
		}

		return new Where(propertyStatement, value, comparison);
	}

	/**
	 * Set order by to the query
	 */
	public function orderBy(var statement, string! sort = "DESC") -> <QueryBuilder>
	{
		let this->order = statement . " " . sort;

		return this;
	}

    /**
     * Set limit to the query
     */
	public function limit(int limit) -> <QueryBuilder>
	{
	    if (limit <= 0) {
	        throw new \Exception("$limit must be >= 0");
	    }

		let this->limit = limit;

		return this;
	}

	public function offset(int offset) -> <QueryBuilder>
	{
		let this->offset = offset;

		return this;
	}

	inline protected function wrap(string id) -> string
    {
		return this->em->getConnection()->getPlatform()->wrap(id);
    }

	public function getSQL() -> string
	{
		var sql, value;

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
			for value in this->joins {
				let sql .= " " . value;
			}
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
				let sql .= " OFFSET ".this->offset;
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