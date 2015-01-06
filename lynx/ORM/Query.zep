/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

class Query
{
	/**
	 * Sql plain query
	 */
	protected query {get};

	protected em;

	protected statement;

	/**
	 * IdentityMap for SQL. need for hydrate data with many relations (joins)
	 */
	protected identityMap {get, set};

	const FETCH_INT = 1;

	const FETCH_FLOAT = 1;

	public function __construct(var query, <EntityManager> em)
	{
		let this->query = query;
		let this->em = em;

		let this->statement = this->em->getConnection()->prepare(this->query);
	}

	/**
	 * Binds a value to a parameter
	 */
	public function bindValue(var parameter, var value, var data_type = \PDO::PARAM_STR) -> <Query>
	{
		this->statement->bindValue(":".parameter, value, data_type);
		return this;
	}

	/**
	 * Binds a parameter to the specified variable name
	 */
	public function bindParam(var parameter, var value, var data_type = \PDO::PARAM_STR, var length = null, var driver_options = null) -> <Query>
	{
		this->statement->bindParam(":".parameter, value, data_type, length, driver_options);
		return this;
	}

	public function getResult() -> array|bool
	{
		var result;

		this->statement->execute();
		let result = this->statement->fetchAll();

		if (count(result) == 0) {
			return false;
		}

		return result;
	}

	public function fetchArray(var parameters = null) -> array|boolean
	{
		return this->getResult();
	}

	public function fetchAll(var parameters = null) -> object|boolean
	{
		var result, model, property, key, value, collection;
		let result = this->getResult();

		this->statement->execute();
		let result = this->statement->fetchAll();

		if (count(result) == 0) {
			return false;
		}

		let collection = new \Lynx\Stdlib\Collections\ArrayCollection();

		return collection;
	}

	public function fetchObject(var parameters = null) -> object|boolean
	{
		return this->getResult();
	}

	public function fetchOne(var parameters = null) -> object|boolean
	{
		var result, model, columnName, key, value;
		let result = this->getResult();

		if (!result || count(result) == 0) {
			return false;
		}

		let model = this->identityMap->getRootModel()->getObject();

		var insertValues = [];
		for key, value in result[0] {
			let columnName = this->identityMap->getRootModel()->getColumnNameByFieldName(key);
			if (columnName) {
				let insertValues[columnName] = value;
			}
		}

		let model = \Lynx\Stdlib\Hydrator\Entity::hydrate(insertValues, model);

		return model;
	}

	public function execute(var parameters, var hydrationMod = null)
	{

	}

	/**
	 * Fetch a statement and converts it to the first column to type if it is specified
	 */
	public function getScalarResult(var type = null)
	{
		var result;
		this->statement->execute();

		let result = this->statement->fetchColumn();

		switch(type) {
			case self::FETCH_INT:
				return (int) result;
			case self::FETCH_FLOAT:
				return (float) result;
			default:
				return result;
				break;
		}
	}
}