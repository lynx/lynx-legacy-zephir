<?php

namespace Lynx\Stdlib\Hydrator;

class Entity implements \Lynx\Stdlib\Hydrator\Hydrator
{

    /**
     * 
     * {@inheritDoc}
     * 	
     *
     * @param array $data 
     * @param mixed $currentObject 
     */
	public static function hydrate($data, $currentObject) {}

    /**
     * 
     * {@inheritDoc}
     * 	
     *
     * @param object $currentObject 
     * @param mixed $modelInfo 
     */
	public static function extract($currentObject, $modelInfo = null) {}

}
