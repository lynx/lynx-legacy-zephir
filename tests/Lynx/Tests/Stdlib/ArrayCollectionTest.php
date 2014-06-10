<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\Stdlib;

use Lynx\Stdlib\Collections\ArrayCollection;

class ArrayCollectionTest
	extends TestCase
{
    public function testCount()
    {
        $collection = new ArrayCollection();
        $this->assertEquals(0, count($collection));

        $collection = new ArrayCollection([1]);
        $this->assertEquals(1, count($collection));

        $collection = new ArrayCollection([1, 2, 3, 4, 5]);
        $this->assertEquals(5, count($collection));
    }

    public function testGetArrayIterator()
    {
        $collection = new ArrayCollection();
        $this->assertInstanceOf('ArrayIterator', $collection->getIterator());
    }

    public function testAdd()
    {
        $collection = new ArrayCollection();
        $this->assertEquals(0, count($collection));

        $collection->add($this->getTestObjectElement());
        $this->assertEquals(1, count($collection));

        $collection->add($this->getTestObjectElement());
        $collection->add($this->getTestObjectElement());
        $collection->add($this->getTestObjectElement());
        $collection->add($this->getTestObjectElement());
        $this->assertEquals(5, count($collection));
    }
}