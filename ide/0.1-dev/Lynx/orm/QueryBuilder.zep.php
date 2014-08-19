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
	public function __construct($em) {}

    /**
     * @param mixed $columns 
     */
	public function select($columns = null) {}


	public function delete() {}


	public function update() {}

    /**
     * @param mixed $from 
     * @param mixed $alias 
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
     */
	public function leftJoin($join, $alias) {}

    /**
     * @param mixed $join 
     * @param mixed $alias 
     */
	public function rightJoin($join, $alias) {}

    /**
     * @param mixed $join 
     * @param mixed $alias 
     */
	public function innerJoin($join, $alias) {}

    /**
     * @param mixed $join 
     * @param mixed $alias 
     */
	public function join($join, $alias) {}

    /**
     * @param mixed $column 
     * @param mixed $value 
     * @param mixed $comparison 
     */
	public function Where($column, $value, $comparison = Where::EQUAL) {}

    /**
     * @param mixed $statement 
     */
	public function orWhere($statement) {}

    /**
     * @param mixed $column 
     * @param mixed $value 
     * @param mixed $comparison 
     */
	protected function addWhere($column, $value, $comparison) {}

    /**
     * 
     * Set order by to the query
     * 	
     *
     * @param mixed $statement 
     * @param string $sort 
     * @return Query 
     */
	public function orderBy($statement, $sort = "DESC") {}

    /**
     * 
     * Set limit to the query
     *
     * @param int $limit 
     */
	public function limit($limit) {}

    /**
     * @param int $offset 
     */
	public function offset($offset) {}

    /**
     * @param string $id 
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
