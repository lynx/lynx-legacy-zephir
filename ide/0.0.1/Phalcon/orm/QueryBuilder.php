<?php

namespace Phalcon\ORM;

class QueryBuilder {
	const SELECT = 1;
	const UPDATE = 2;
	const DELETE = 3;
	public function getLimit() {}
	public function __construct() {}
	public function select() {}
	public function delete() {}
	public function update() {}
	public function from() {}
	public function leftJoin() {}
	public function limit() {}
	public function offset() {}
	public function getSQL() {}
	public function getQuery() {}
}