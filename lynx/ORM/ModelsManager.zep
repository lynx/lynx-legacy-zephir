
namespace Lynx\ORM;

class ModelsManager
{
	private cachedModels = [];

	public function get(string! classname)
	{
		if (isset(this->cachedModels[classname])) {
			return this->cachedModels[classname];
		}

		let this->cachedModels[classname] = new ModelMetaData(classname);
		return this->cachedModels[classname];
	}
}