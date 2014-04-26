/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\DBAL;

class Connection
{
	protected driver {get};

	public function __construct(var driver, var parameters)
	{
		let this->driver = driver;
	}

	public function prepare(var statement)
	{
		var smt;
		let smt = this->driver->prepare(statement);
		return smt;
	}
}