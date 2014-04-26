
namespace Lynx\ORM;

class Configuration
{
	protected cacheDriver {get};

	/**
	 * Set Cache Driver
	 */
	public function setCacheDriver(<\Lynx\Cache\CacheDriver> cacheDriver)
	{
		let this->cacheDriver = cacheDriver;
	}
}