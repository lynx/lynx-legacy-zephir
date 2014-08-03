<?php

namespace Lynx\ORM\QueryBuilder\Expression;

class Join
{

    const RIGHT_JOIN = RIGHT;

    const INNER_JOIN = INNER;

    const LEFT_JOIN = LEFT;

    private $type;


	public function getType() {}

    /**
     * @param string $type 
     */
	public function __construct($type) {}

}
