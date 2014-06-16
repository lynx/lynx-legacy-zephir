
namespace Lynx\Cache;


/**
 * Abstract class for Cache Drivers
 */
abstract class CacheDriver implements Driver
{
	//zephir bug :D
	abstract public function get(string! id);

    /**
     * Data with id exists?
     *
     * @param string $id
     * @return boolean
     */
    public function exists(string! id)
    {
        var result;
        let result = this->get(id);
        return result !== false;
    }
}
