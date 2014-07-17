<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\Stdlib;


class TestObject1
{
    public $property1;

    public $property2;

    public $property3;
}

class EntityHydratorTest extends TestCase
{
    public function testObject1()
    {
        $object = new TestObject1();

        \Lynx\Stdlib\Hydrator\Entity::hydrate(array(
            'property1' => 1,
            'property2' => "test string",
            'property3' => true
        ), $object);

        $this->assertSame(1, $object->property1);
        $this->assertSame("test string", $object->property2);
        $this->assertSame(true, $object->property3);
    }
}
