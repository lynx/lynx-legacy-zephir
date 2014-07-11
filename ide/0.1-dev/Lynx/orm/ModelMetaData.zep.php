<?php

namespace Lynx\ORM;

class ModelMetaData
{

    protected $classname;

    protected $tablename;

    protected $properties;


	public function getClassname() {}


	public function getTablename() {}

    /**
     * @param mixed $classname 
     */
	public function __construct($classname) {}


	public function getObject() {}


	public function getProperties() {}

    /**
     * @param string $key 
     */
	public function getProperty($key) {}


	public function getPrimaryKey() {}


	public function getPrimaryFieldName() {}

    /**
     * @param mixed $field 
     */
	public function getFieldNameByColumn($field) {}

}
