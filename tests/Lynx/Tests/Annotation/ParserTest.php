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

    public function testReflectionClassParser()
    {
        $class = '\Model\User';
        $annotationsReflector = new \Lynx\Annotation\ReflectionClassParser($class);
        $returnValue = $annotationsReflector->getClassAnnotations();
        $this->assertInternalType('array', $returnValue);
        $this->assertCount(2, $returnValue);
    }
} 