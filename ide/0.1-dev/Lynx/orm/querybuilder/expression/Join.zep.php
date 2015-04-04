<?php

namespace Lynx\ORM\QueryBuilder\Expression;

class Join
{

    const RIGHT_JOIN = "RIGHT";


    const INNER_JOIN = "INNER";


    const LEFT_JOIN = "LEFT";


    private $type;


    private $join;


    private $alias;


    private $condition;


    /**
     * @param string $type 
     * @param mixed $join 
     * @param mixed $alias 
     * @param mixed $condition 
     */
	public function __construct($type, $join, $alias, $condition = null) {}


	public function __toString() {}

}
