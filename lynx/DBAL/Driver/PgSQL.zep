/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\DBAL\Driver;

class PgSQL
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

    inline public function isConnected() -> boolean
    {
        return !is_null(this->connection);
    }

    /**
     * Execute query and return result
     */
    public function execute(string! query) -> int
    {
        var e;
        this->connect();

        try {
            return this->connection->exec(query);
        } catch \Exception, e {
            var_dump(e->getMessage());
            die();
        }

    }

    public function getNewPlatform()
    {
        return new \Lynx\DBAL\Platform\PgSQL();
    }

    public function connect()
    {
        if (this->isConnected()) {
            return false;
        }

        let this->connection = new Pdo(
            this->dsn,
            this->username,
            this->password,
            this->driverOptions
        );
    }

    public function lastInsertId(string! seq_id)
    {
        this->connect();

        return this->connection->lastInsertId(seq_id);
    }

    public function prepare(var statement)
    {
        var e;
        this->connect();

        try {
            return this->connection->prepare(statement);
        } catch \Exception, e {
            var_dump(e->getMessage());
            die();
        }
    }
}
