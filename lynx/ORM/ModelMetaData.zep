

namespace Lynx\ORM;

class ModelMetaData
{
	protected classname {get};

	protected tablename {get};

	protected properties;

	public function __construct(classname)
	{
	    var parser, result;

		let this->classname = classname;

        let parser = new \Lynx\Annotation\ReflectionClassParser(classname);
        let result = parser->getClassAnnotations();


        let this->tablename = result["table"]["name"];
        let this->properties = parser->getPropertiesAnnotations();
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