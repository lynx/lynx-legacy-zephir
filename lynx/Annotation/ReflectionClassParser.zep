
namespace Lynx\Annotation;

class ReflectionClassParser
{
    protected reflectionClass;

    public function __construct(var parameter)
    {
        if (is_string(parameter)) {
            let this->reflectionClass = new \ReflectionClass(parameter);
        }
    }

    public function getClassAnnotations()
    {
        var docComment, result;
        let docComment = this->reflectionClass->getDocComment();

        let result = Parser::parseAnnotations(docComment);
        return result;
    }
}