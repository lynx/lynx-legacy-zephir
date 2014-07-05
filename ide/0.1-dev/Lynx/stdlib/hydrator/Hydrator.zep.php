<?php

namespace Lynx\Stdlib\Hydrator;

interface Hydrator
{

    /**
     * 
     * Hydrate values to object
     * 	
     *
     * @param array $data 
     * @param mixed $currentObject 
     */
	public static function hydrate($data, $currentObject);

    /**
     * 
     * Extract values from object
     * 	
     *
     * @param object $currentObject 
     */
	public static function extract($currentObject);

}
