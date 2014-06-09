<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\Stdlib;

class TestCase
	extends \PHPUnit_Framework_TestCase
{
    public function getTestObjectElement()
    {
        $object = new \stdClass();

        return $object;
    }
} 