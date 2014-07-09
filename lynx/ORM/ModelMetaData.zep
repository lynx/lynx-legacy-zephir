

namespace Lynx\ORM;

use Lynx\Annotation\ReflectionClassParser;

class ModelMetaData
{
	protected classname {get};

	protected tablename {get};

	protected properties;

	public function __construct(classname)
	{
	    var parser, result;

		let this->classname = classname;

        let parser = new ReflectionClassParser(classname);
        let result = parser->getClassAnnotations();


        let this->tablename = result["table"]["name"];
        let this->properties = parser->getPropertiesAnnotations();
	}

	public function getObject()
	{
		var tmp, classname;

		let classname = this->classname;
		let tmp = new {classname}();

		return tmp;
	}

	public function getProperties()
	{
		if (!is_null(this->properties)) {
			return this->properties;
		}

		return [];
	}

	public function getProperty(string! key)
	{
		var properties;
		let properties = this->getProperties();

		return properties[key];
	}

	public function getPrimaryKey()
	{
		return this->getProperty("id");
	}
}