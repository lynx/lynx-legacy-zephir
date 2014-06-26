/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\DBAL;

use Lynx\Stdlib\Events\Manager as EventsManager;

class Connection
{
	/**
	 * Current used driver
	 */
	protected driver {get};

	/**
	 * Construct connection
	 */
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

	/**
	 * Insert row to the table with spicifed data and types
	 * return the nubmer of affected rows
	 */
	public function insert(string! table, array! data, array! types = []) -> int
	{
		var query;
		let query = "INSERT INTO " . table . " (" . implode(", ", array_keys(data)) . ")" .
			" VALUES (" . implode(", ", data) . ")";

		/**
		 * @todo implement work with types
		 */
		return this->driver->execute(query);
	}

	/**
	 * Update row(s) from table and return the number of updated rows
	 */
	public function update(string! table, array! data, array! identifiers, array! types = []) -> int
	{
		string query;

   		var set = [], stmt, columnName, value;

		for columnName, value in data {
			let set[] = "`" . columnName . "` = ?";
		}

		let query =  "UPDATE " . table . " SET " . implode(', ', set) . " WHERE " . implode(" = ? AND ", array_keys(identifiers));
		let stmt = this->driver->prepare(query);

		return stmt->execute(array_merge(array_values(data), array_values(identifiers)));
	}

	/**
	 * Delete rows where $column = $key from $table
	 * return the nubmer of affected rows
	 */
	public function deleteByColumn(string! table, string! column, string! value, string! type = null)
	{
		/**
		 * @todo implement work with type
		 */
		return this->driver->execute("DELETE FROM " . table . " WHERE " . column . " = " . value);
	}

	/**
	 * Delete rows from tables where identifiers is spicifed
	 * return the nubmer of affected rows
	 */
	public function delete(string! table, array! identifiers, array! types = []) -> int
	{
		var query, key, value;
		boolean first = true;

		let query = "DELETE FROM " . table . " WHERE ";

		for key, value in identifiers {
			if (!first) {
				let query .= " AND";
			} else {
				let first = false;
			}

			let query = " " . key . " = " . value;
		}

		/**
		 * @todo implement work with type
		 */
		return this->driver->execute(query);
	}

	/**
	 * Prepares a statement for execution and returns a statement
	 */
	public function prepare(var statement)
	{
		var smt;
		let smt = this->driver->prepare(statement);
		return smt;
	}
}