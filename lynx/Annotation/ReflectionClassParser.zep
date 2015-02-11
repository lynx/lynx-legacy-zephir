/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Annotation;

class ReflectionClassParser
{
    /**
     * @var \ReflectionClass
     */
    protected reflectionClass;

    public function __construct(var parameter)
    {
        if (is_string(parameter) || is_object(parameter)) {
            let this->reflectionClass = new \ReflectionClass(parameter);
        } else {
            throw new \Exception("$parameter must be class name (string) or object instance (object)");
        }
    }

    public function getClassAnnotations()
    {
        var docComment, result;
        let docComment = this->reflectionClass->getDocComment();

        let result = RegexDocParser::parseAnnotations(docComment);
        return result;
    }

    public function getPropertiesAnnotations()
    {
        var properties, property, result = [];
        let properties = this->reflectionClass->getProperties();

        for property in properties {
            let result[property->getName()] = RegexDocParser::parseAnnotations(property->getDocComment());
        }

        return result;
    }
}
