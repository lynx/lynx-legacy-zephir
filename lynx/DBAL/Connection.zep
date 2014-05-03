/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\DBAL;

use Lynx\Stdlib\Events\Manager as EventsManager;

class Connection
{
	protected driver {get};

	public function __construct(var parameters, <EventsManager> eventsManager = null)
	{
	    if (is_null(eventsManager)) {
	        let eventsManager = new EventsManager();
	    }

	    /**
	     * Current step no support for inst drivers
	     */
		if (isset(parameters["driver"])) {
			let this->driver = parameters["driver"];
		} else {
			throw new \Exception("Driver didn`t find in $parameters");
		}

	    this->driver->setEventsManager(eventsManager);
	}

	public function prepare(var statement)
	{
		var smt;
		let smt = this->driver->prepare(statement);
		return smt;
	}
}