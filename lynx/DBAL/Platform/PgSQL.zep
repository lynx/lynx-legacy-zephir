
namespace Lynx\DBAL\Platform;

class Pgsql
{
    inline public function wrap(id)
    {
        return id;
    }
}