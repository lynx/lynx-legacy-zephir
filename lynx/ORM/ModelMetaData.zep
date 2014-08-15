

namespace Lynx\ORM;

use Lynx\Annotation\ReflectionClassParser;

class ModelMetaData
{
	protected classname {get};

	protected tablename {get};

	protected properties;

	protected columns;

	public function __construct(classname)
	{
	    var parser, result, properties, column, key, value;

		let this->classname = classname;

        let parser = new ReflectionClassParser(classname);
        let result = parser->getClassAnnotations();


        let this->tablename = result["table"]["name"];

        let properties = parser->getPropertiesAnnotations();

		for key, value in properties {
			if (isset(value["joincolumn"])) {
				let column = new ModelMetaData\Property();

				if (isset(value["onetoone"])) {
					let column->type = 1;

					/**
					 * @todo: move to const
					 */
					let column->targetEntity = value["onetoone"]["targetEntity"];
				}

				let column->name = value["joincolumn"]["name"];
				let column->referencedColumnName = value["joincolumn"]["referencedColumnName"];

				let this->properties[key] = column;
			}
		}

		for key, value in properties {
			if (isset(value["column"])) {
				let column = new ModelMetaData\Column();

				if (isset(value["id"])) {
					let column->id = true;
				}

				let column->type = value["column"]["type"];

				if (isset(value["column"]["name"])) {
					let column->name = value["column"]["name"];
				} else {
					let column->name = key;
				}

				let this->columns[key] = column;
			}
		}
	}

	public function getObject()
	{
		var tmp, classname;

		let classname = this->classname;
		let tmp = new {classname}();

		return tmp;
	}

	public function getColumns()
	{
		if (!is_null(this->columns)) {
			return this->columns;
		}

		return [];
	}

	public function getProperties()
	{
		if (!is_null(this->properties)) {
			return this->properties;
		}

		return [];
	}

	public function getColumn(string! key)
	{
		var columns;

		let columns = this->getColumns();
		if (isset(columns[key])) {
			return columns[key];
		}

		return false;
	}

	public function getProperty(string! key)
	{
		var properties;

		let properties = this->getProperties();
		if (isset(properties[key])) {
			return properties[key];
		}

		return false;
	}

	public function getPrimaryKey()
	{
		return this->getColumn(this->getPrimaryFieldName());
	}

	public function getPrimaryFieldName()
	{
		return "id";
	}

	public function getFieldNameByColumn(var field)
	{
		var properties, columnName, info;

		let properties = this->getProperties();

		for columnName, info in properties {
			if (info->name == field) {
				return columnName;
			}
		}

		return false;
	}
}