<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

class ParserTest extends \PHPUnit_Framework_TestCase
{
    public function testParseAnnotation()
    {
        $comment = <<<EOT
/**
 * @Entity ( name = Entity1 , value = Value1 )
 */
EOT;


        $this->assertTrue(true);
    }
} 