<?php

namespace Lynx\Stdlib\Collections;

class Collection implements \Countable, \IteratorAggregate
{

    /**
     * Get elements count from collection
     * 	
     */
	abstract public function count();

    /**
     * Get iterator
     * 	
     */
	abstract public function getIterator();

    /**
     * Execute fuction to each element in the collection
     * 	
     *
     * @param \Closure $func 
     */
	abstract public function map($func);

    /**
     * Execute fuction to each element in the collection and
     * remove element from collection if executed function return false
     * 	
     *
     * @param mixed $func 
     */
	abstract public function filter($func);

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
