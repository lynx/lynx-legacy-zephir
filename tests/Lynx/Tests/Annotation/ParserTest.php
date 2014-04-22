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

        $a = \Lynx\Annotation\Parser::parseAnnotations($comment);
        var_dump($a);

//        $hasAnnotations = preg_match_all(
//            '/@(\w+)(?:\s*(?:\(\s*)?(.*?)(?:\s*\))?)??\s*(?:\n|\*\/)/',
//            $comment,
//            $matches,
//            PREG_SET_ORDER
//        );
//        var_dump($matches);
    }
} 