<?php

namespace Lynx\ORM;

class SqlBuilder
{
	const SELECT = 1;
	const UPDATE = 2;
	const DELETE = 3;
	protected $type;
	protected $limit;
	protected $offset;
	protected $em;

	public function getLimit() {}

	public function __construct($em) {}

	public function select() {}

	public function delete() {}

	public function update() {}

	public function from() {}

	public function leftJoin() {}

	public function limit($limit) {}

	public function offset($offset) {}

	public function getSQL() {}

	public function getQuery() {}

}
