<?php

namespace Lynx\ORM\QueryBuilder\Expression;

class Where
{

    const EQUAL = "=";


    const EQUAL_GREATER = ">=";


    const EQUAL_LESS = "<=";


    const NOT_EQUAL = "<>";


    const GREATER = ">";


    const LESS = "<";


    const IN = "IN";


    const NOT_IN = "NOT IN";


    const IS_NULL = "IS NULL";


    const IS_NOT_NULL = "IS NOT NULL";


    private $type;


    private $leftExpr;


    private $rightExpr;


    /**
     * @param mixed $leftExpr 
     * @param mixed $rightExpr 
     * @param string $type 
     */
	public function __construct($leftExpr, $rightExpr, $type) {}


	public function __toString() {}

}
