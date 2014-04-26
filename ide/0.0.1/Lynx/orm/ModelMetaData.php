<?php

namespace Lynx\ORM;

class ModelMetaData
{
	protected $classname;
	protected $tablename;
	protected $properties;

	public function getClassname() {}

	public function getTablename() {}

	public function __construct($classname) {}

	public function getProperties() {}

	public function getProperty($key) {}

	public function getPrimaryKey() {}

}
