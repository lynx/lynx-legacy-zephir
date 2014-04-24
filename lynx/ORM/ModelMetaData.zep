

namespace Lynx\ORM;

class ModelMetaData
{
	protected classname {get};

	protected tablename {get};

	protected columns;

	public function __construct(classname)
	{
	    var parser, result;

		let this->classname = classname;

        let parser = new \Lynx\Annotation\ReflectionClassParser(classname);
        let result = parser->getClassAnnotations();


        let this->tablename = result["table"]["name"];
	}
}