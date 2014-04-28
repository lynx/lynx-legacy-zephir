/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\DBAL;

use Lynx\Stdlib\Events\Manager as EventsManager;

class Connection
{
	protected driver {get};

	public function __construct(var driver, var parameters, <EventsManager> eventsManager = null)
	{
	    if (is_null(eventsManager)) {
	        let eventsManager = new EventsManager();
	    }

	    driver->setEventsManager(eventsManager);
		let this->driver = driver;
	}

	public function prepare(var statement)
	{
		var smt;
		let smt = this->driver->prepare(statement);
		return smt;
	}
}