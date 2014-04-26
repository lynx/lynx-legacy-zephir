<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

use Lynx\Annotation\RegexDocParser;
use Lynx\Annotation\ReflectionClassParser;

class ParserTest extends \PHPUnit_Framework_TestCase
{
    public function testParseAnnotation()
    {
        $comment = <<<EOT
/**
 * @Entity ( name = Entity1 , value = Value1 )
 */
EOT;

        $returnValue = RegexDocParser::parseAnnotations($comment);
        $this->assertInternalType('array', $returnValue);
        $this->assertCount(1, $returnValue);
    }

    protected function reflectionClassParserTest($class)
    {
        $annotationsReflector = new ReflectionClassParser($class);
        $returnValue = $annotationsReflector->getClassAnnotations();
        $this->assertInternalType('array', $returnValue);
        $this->assertCount(2, $returnValue);
    }

    public function testReflectionClassParserFromSttingClassName()
    {
        $class = '\Model\User';
        $this->reflectionClassParserTest($class);
    }

    public function testReflectionClassParserFromSttingClassInstance()
    {
        $class = new Model\User();
        $this->reflectionClassParserTest($class);
    }

    public function testReflectionClassParseContructWrontParameterException()
    {
        $this->setExpectedException('\Exception', '$parameter must be class name (string) or object instance (object)');
        $this->reflectionClassParserTest(12345);
    }
} 