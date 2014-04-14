
namespace Lynx\Cache;

class Memcached extends CacheDriver
{
    protected options;

    protected instance;

    public function __construct(array options = null)
    {
        let this->options = options;
    }

    public function setInstance(<\Memcached> instance)
    {
        let this->instance = instance;
    }

    protected function getInstance() -> <\Memcached>
    {
        if (is_null(this->instance)) {
            let this->instance = new \Memcached;
            this->instance->connect("localhost", 11211);

            return this->instance;
        }

        return this->instance;
    }

    public function save(string! id, data, lifeTime = 3600)
    {
        return this->getInstance()->set(id, data, lifeTime);
    }

    public function delete(string! id)
    {
        return this->getInstance()->delete(id);
    }

    public function get(string! id)
    {
        return this->getInstance()->get(id);
    }

    public function flush()
    {
        return this->getInstance()->flush();
    }
}
