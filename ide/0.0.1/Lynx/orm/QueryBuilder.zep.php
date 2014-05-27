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

    protected $where = array();

    protected $type;

    protected $limit;

    protected $offset;

    protected $order;

    protected $em;


	public function getType() {}


	public function getLimit() {}


	public function getOffset() {}


	public function getOrder() {}

    /**
     * @param EntityManager $em 
     */
	public function __construct($em) {}


	public function select() {}


	public function delete() {}


	public function update() {}

    /**
     * @param mixed $from 
     * @param mixed $alias 
     */
	public function from($from, $alias) {}

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
	public function join($join, $alias) {}

    /**
     * @param mixed $statement 
     */
	public function where($statement) {}

    /**
     * @param mixed $statement 
     */
	public function andWhere($statement) {}

    /**
     * @param mixed $statement 
     */
	public function orWhere($statement) {}

    /**
     * 
     * @param statement
     * @param string sort
     * @return $this
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
	inline protected function wrap($id) {}

    /**
     * @return string 
     */
	public function getSQL() {}

    /**
     * @return Query 
     */
	public function getQuery() {}

}
