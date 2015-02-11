/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\DBAL\Driver;

use \Lynx\DBAL\Events;

class Pdo extends \PDO
{
    const PARAM_EXPRESSION = 10;

    public function __construct(string! dsn, var username = null, var password = null, array options = null)
    {
        parent::__construct(dsn, username, password, options);
        this->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
        this->setAttribute(\PDO::ATTR_STATEMENT_CLASS, ["\\Lynx\\DBAL\\Driver\\PDO\\Statement"]);
        this->setAttribute(\PDO::ATTR_DEFAULT_FETCH_MODE, \PDO::FETCH_ASSOC);
    }
}
