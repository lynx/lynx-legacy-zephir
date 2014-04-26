
namespace Lynx\ORM;

class ModelsManager
{
	/**
	 * @var EntityManager
	 */
    protected em;

	private cachedModels = [];

	protected cacheLoaded = false;

	protected cacheLoadType;

	const CACHE_LOAD_PER_GET = 0;

	const CACHE_LOAD_PER_GET_ALL = 1;

    public function __construct(<EntityManager> em, var cacheLoadType = self::CACHE_LOAD_PER_GET_ALL)
    {
        let this->em = em;
        let this->cacheLoadType = cacheLoadType;
    }

	public function get(string! classname)
	{
        if (this->cacheLoaded) {
	    	var cacheDriver;
        	let cacheDriver = this->em->getConfiguration()->getCacheDriver();

    		if (cacheDriver) {

    		}
        }

		if (isset(this->cachedModels[classname])) {
			return this->cachedModels[classname];
		}

		let this->cachedModels[classname] = new ModelMetaData(classname);
		return this->cachedModels[classname];
	}
}