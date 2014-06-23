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
     * @param mixed $parameters 
     * @param EventsManager $eventsManager 
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
     * Delete rows where $column = $key from $table
     * return the nubmer of affected rows
     * 	
     *
     * @param string $table 
     * @param string $column 
     * @param string $value 
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
     * @param mixed $statement 
     */
	public function prepare($statement) {}

}
