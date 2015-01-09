<?php

namespace Lynx\ORM;

class QueryBuilder
{

    const SELECT = 1;

    const UPDATE = 2;

    const DELETE = 3;

    protected $alias = "default";

    protected $from;

    protected $parts;

    protected $columns = "*";

    protected $where = array();

    protected $type;

    protected $limit;

    protected $offset;

    protected $order;

    protected $joins = array();

    protected $rootModel;

    protected $em;


	public function getType() {}


	public function getLimit() {}


	public function getOffset() {}


	public function getOrder() {}


	public function getJoins() {}

    /**
     * @param mixed $em 
     */
	public function __construct(EntityManager $em) {}

    /**
     * @param mixed $columns 
     * @return QueryBuilder 
     */
	public function select($columns = null) {}

    /**
     * @return QueryBuilder 
     */
	public function delete() {}

    /**
     * @return QueryBuilder 
     */
	public function update() {}

    /**
     * @param mixed $from 
     * @param mixed $alias 
     * @return QueryBuilder 
     */
	public function from($from, $alias) {}

    /**
     * @param mixed $joinType 
     * @param mixed $parentAlias 
     * @param mixed $modelName 
     * @param mixed $alias 
     */
	protected function prepareJoin($joinType, $parentAlias, $modelName, $alias) {}

    /**
     * @param mixed $join 
     * @param mixed $alias 
     * @return QueryBuilder 
     */
	public function leftJoin($join, $alias) {}

    /**
     * @param mixed $join 
     * @param mixed $alias 
     * @return QueryBuilder 
     */
	public function rightJoin($join, $alias) {}

    /**
     * @param mixed $join 
     * @param mixed $alias 
     * @return QueryBuilder 
     */
	public function innerJoin($join, $alias) {}

    /**
     * @param mixed $join 
     * @param mixed $alias 
     * @return QueryBuilder 
     */
	public function join($join, $alias) {}

    /**
     * @param mixed $column 
     * @param mixed $value 
     * @param mixed $comparison 
     * @return QueryBuilder 
     */
	public function where($column, $value, $comparison = Where::EQUAL) {}

    /**
     * @param mixed $column 
     * @param mixed $value 
     * @param mixed $comparison 
     * @return QueryBuilder 
     */
	public function orWhere($column, $value, $comparison = Where::EQUAL) {}

    /**
     * @param mixed $column 
     * @param mixed $value 
     * @param mixed $comparison 
     */
	protected function prepareWhereStatement($column, $value, $comparison) {}

    /**
     * 
     * Set order by to the query
     *
     * @param mixed $statement 
     * @param string $sort 
     * @return QueryBuilder 
     */
	public function orderBy($statement, $sort = "DESC") {}

    /**
     * 
     * Set limit to the query
     *
     * @param int $limit 
     * @return QueryBuilder 
     */
	public function limit($limit) {}

    /**
     * @param int $offset 
     * @return QueryBuilder 
     */
	public function offset($offset) {}

    /**
     * @param string $id 
     * @return string 
     */
	protected function wrap($id) {}

    /**
     * @return string 
     */
	public function getSQL() {}

    /**
     * @return Query 
     */
	public function getQuery() {}

}
