/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\DBAL\Driver;

class Pdo
{
	protected _pdo;

	public function __construct(string! dsn, var username = null, var password = null, array options = null)
	{
		let this->_pdo = new \PDO(dsn, username, password, options);
	}

	public function connect()
	{

	}

	public function query(string! sqlStatement, array bindParams = null, array bindTypes = null)
	{

	}
}