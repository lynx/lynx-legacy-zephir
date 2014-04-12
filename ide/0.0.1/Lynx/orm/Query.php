<?php

namespace Lynx\ORM;

class Query
{
	protected $query;
	protected $em;

	public function __construct($query, $em) {}

	public function fetchArray($parameters = null) {}

	public function fetchAll($parameters = null) {}

	public function fetchObject($parameters = null) {}

	public function fetchOne($parameters = null) {}

}
