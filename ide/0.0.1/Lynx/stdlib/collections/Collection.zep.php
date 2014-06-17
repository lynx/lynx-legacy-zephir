<?php

namespace Lynx\Stdlib\Collections;

class Collection implements \Countable, \IteratorAggregate
{


	abstract public function count();


	abstract public function getIterator();

    /**
     * Set current element to the first element and return it
     * 	
     */
	abstract public function first();

    /**
     * Set current element to the last element and return it
     * 	
     */
	abstract public function last();

    /**
     * Add element to collection
     * 	
     *
     * @param mixed $element 
     */
	abstract public function add($element);

}
