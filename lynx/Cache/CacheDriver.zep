
namespace Lynx\Cache;


/**
 * Abstract class for Cache Drivers
 */
abstract class CacheDriver implements Driver
{
	/**
	 * Get data by id
	 */
	abstract public function get(string! id);

	/**
	 * Data with id exists?
	 */
	public function exists(string! id)
	{
		var result;
		let result = this->get(id);
		return result !== false;
	}
}
