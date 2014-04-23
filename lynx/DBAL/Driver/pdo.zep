/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\DBAL\Driver;

class Pdo extends \PDO
{
	public function __construct(string! dsn, var username = null, var password = null, array options = null)
	{
		parent::__construct(dsn, username, password, options);
		this->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
		this->setAttribute(\PDO::ATTR_STATEMENT_CLASS, ["Lynx\\DBAL\\Driver\\PDO\\Statement", []]);
	}
}