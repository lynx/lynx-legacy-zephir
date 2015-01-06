
namespace Lynx\DBAL\Platform;

class Mysql
{
    inline public function wrap(id)
    {
        return "`" . id . "`";
    }
}