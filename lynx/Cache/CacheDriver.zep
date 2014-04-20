
namespace Lynx\Cache;


/**
 * Abstract class for Cache Drivers
 */
abstract class CacheDriver
{
	/**
	 * To initialize cache provider
	 */
	abstract protected function getInstance();

	/**
	 * Save data
	 */
    abstract public function save(string! id, data, lifeTime = 3600);

	/**
	 * Save data by id
	 */
    abstract public function delete(string! id);

	/**
	 * Fetch data by id
	 */
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
