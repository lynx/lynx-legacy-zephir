
namespace Lynx\DBAL\Platform;

class MySQL
{
    inline public function wrap(id)
    {
        return "`" . id . "`";
    }
}