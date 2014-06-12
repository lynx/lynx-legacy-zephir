
namespace Lynx\ORM;

use Lynx\Cache\CacheDriver;

class Configuration
{
	protected cacheDriver {get};

	/**
	 * Set Cache Driver
	 */
	public function setCacheDriver(<CacheDriver> cacheDriver)
	{
		let this->cacheDriver = cacheDriver;
	}
}