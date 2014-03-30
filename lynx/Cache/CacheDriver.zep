
namespace Lynx\Cache;

abstract class CacheDriver
{
    abstract public function save(string! id, data, lifeTime = 0) {}

    abstract public function delete(string! id) {}

    abstract public function get(string! id) {}

    abstract public function exists(string! id) {}
}