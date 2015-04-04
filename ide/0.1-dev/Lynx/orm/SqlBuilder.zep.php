<?php

namespace Lynx\ORM;

class SqlBuilder
{

    const SELECT = 1;


    const UPDATE = 2;


    const DELETE = 3;


    protected $type = self::SELECT;


    protected $limit = null;


    protected $offset = null;


    protected $em;



	public function getLimit() {}

    /**
     * @param mixed $em 
     */
	public function __construct(EntityManager $em) {}


	public function select() {}


	public function delete() {}


	public function update() {}


	public function from() {}


	public function leftJoin() {}

    /**
     * @param int $limit 
     */
	public function limit($limit) {}

    /**
     * @param int $offset 
     */
	public function offset($offset) {}


	public function getSQL() {}


	public function getQuery() {}

}
