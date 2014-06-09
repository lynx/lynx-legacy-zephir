<?php

namespace Lynx\Stdlib\Collections;

class ArrayCollection extends \Lynx\Stdlib\Collections\Collection
{

    protected $elements;

    /**
     * @param array $elements 
     */
	public function __construct($elements = array()) {}

    /**
     * @param mixed $element 
     */
	public function add($element) {}

    /**
     * @return ArrayIterator 
     */
	public function getIterator() {}

    /**
     * @return int 
     */
	public function count() {}

}
