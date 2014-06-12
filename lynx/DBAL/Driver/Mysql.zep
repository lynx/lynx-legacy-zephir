
namespace Lynx\DBAL\Driver;

class Mysql
{
	protected eventsManager {set, get};

	protected dsn;

	protected username;

	protected password;

	protected driverOptions;

	protected connection;

	public function __construct(string! dsn, var username = null, var password = null, array driverOptions = [])
	{
		let this->dsn = dsn;
		let this->username = username;
		let this->password = password;
		let this->driverOptions = driverOptions;
	}

	public function connect()
	{
		if (!is_null(this->connection)) {
			return false;
		}

		let this->connection = new Pdo(
			this->dsn,
			this->username,
			this->password,
			this->driverOptions
		);
	}

	public function prepare(var statement)
	{
		this->connect();

		return this->connection->prepare(statement);
	}
}