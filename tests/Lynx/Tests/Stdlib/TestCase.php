<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\Stdlib;

class TestCase
	extends \PHPUnit_Framework_TestCase
{
    public function getTestObjectElement($id = 1, $value = "test")
    {
        $object = new \stdClass();

        $object->id = $id;
        $object->value = $value;

        return $object;
    }
} 