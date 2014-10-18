<?php

namespace Lynx\DBAL;

class Connection
{
    /**
     * Current used driver
     * 	
     */
    protected $driver;

    /**
     * Current used driver
     * 	
     */
	public function getDriver() {}

    /**
     * Construct connection
     * 	
     *
     * @param mixed $parameters 
     * @param mixed $eventsManager 
     */
	public function __construct($parameters, $eventsManager = null) {}

    /**
     * Insert row to the table with spicifed data and types
     * return the nubmer of affected rows
     * 	
     *
     * @param string $table 
     * @param array $data 
     * @param array $types 
     * @return int 
     */
	public function insert($table, $data, $types = array()) {}

    /**
     * Update row(s) from table and return the number of updated rows
     * 	
     *
     * @param string $table 
     * @param array $data 
     * @param array $identifiers 
     * @param array $types 
     * @return int 
     */
	public function update($table, $data, $identifiers, $types = array()) {}

    /**
     * Delete rows where $column = $key from $table
     * return the nubmer of affected rows
     * 	
     *
     * @param string $table 
     * @param string $column 
     * @param mixed $value 
     * @param string $type 
     */
	public function deleteByColumn($table, $column, $value, $type = null) {}

    /**
     * Delete rows from tables where identifiers is spicifed
     * return the nubmer of affected rows
     * 	
     *
     * @param string $table 
     * @param array $identifiers 
     * @param array $types 
     * @return int 
     */
	public function delete($table, $identifiers, $types = array()) {}

    /**
     * Prepares a statement for execution and returns a statement
     * 	
     *
     * @param mixed $statement 
     */
	public function prepare($statement) {}

}
