
namespace Lynx\Cache;

interface Driver
{
	/**
	 * To initialize cache provider
	 */
	public function getInstance();

	/**
	 * Save data
	 */
	public function save(string! id, data, lifeTime = 3600);

	/**
	 * Save data by id
	 */
	public function delete(string! id);

	/**
	 * Fetch data by id
	 */
	public function get(string! id);

	public function exists(string! id);
}