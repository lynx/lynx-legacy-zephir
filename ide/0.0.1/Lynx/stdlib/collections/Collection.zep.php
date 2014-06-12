<?php

namespace Lynx\Stdlib\Collections;

class Collection implements \Countable, \IteratorAggregate
{


	abstract public function count();


	abstract public function getIterator();

    /**
     * Add element to collection
     * 	
     *
     * @param mixed $element 
     */
	abstract public function add($element);

}
