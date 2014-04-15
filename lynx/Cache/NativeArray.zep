
namespace Lynx\Cache;

class NativeArray extends CacheDriver
{
    protected options;

    protected instance = [];

    public function __construct(array options = null)
    {
        let this->options = options;
    }

    public function setInstance(array! instance)
    {
        let this->instance = instance;
    }

    protected function getInstance()
    {
    }

    public function save(string! id, data, lifeTime = 3600)
    {
        let this->instance[id] = data;
    }

    public function delete(string! id) -> boolean
    {
        if (isset(this->instance[id])) {
            unset(this->instance[id]);

            return true;
        }

        return false;
    }

    public function get(string! id)
    {
        var result;

        if fetch result, this->instance[id] {
            return result;
        }

        return false;
    }

    public function flush()
    {
        let this->instance = [];
    }
}
