
namespace Lynx\ORM;

class Configuration
{
	protected cacheDriver {get};

	/**
	 * Set Cache Driver
	 */
	public function setCacheDriver(<\Cacher\Driver> cacheDriver)
	{
		let this->cacheDriver = cacheDriver;
	}
}