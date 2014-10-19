
namespace Lynx\DBAL\Platform;

class Mysql
{
    public function wrap(id)
    {
        return "`" . id . "`";
    }
}