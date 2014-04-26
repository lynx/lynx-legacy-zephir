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
	protected $where;
	protected $type;
	protected $limit;
	protected $offset;
	protected $em;

	public function getType() {}

	public function getLimit() {}

	public function getOffset() {}

	public function __construct($em) {}

	public function select() {}

	public function delete() {}

	public function update() {}

	public function from($from, $alias) {}

	public function leftJoin($join, $alias) {}

	public function rightJoin($join, $alias) {}

	public function join($join, $alias) {}

	public function where($statement) {}

	public function andWhere($statement) {}

	public function orWhere($statement) {}

	public function orderBy($sort) {}

	/**
	 * Set limit to the query
	 */
	public function limit($limit) {}

	public function offset($offset) {}

	inline protected function wrap($id) {}

	public function getSQL() {}

	public function getQuery() {}

}
