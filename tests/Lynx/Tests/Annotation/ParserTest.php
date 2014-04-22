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

        $returnValue = \Lynx\Annotation\Parser::parseAnnotations($comment);
        $this->assertInternalType('array', $returnValue);
        $this->assertCount(1, $returnValue);
    }
} 