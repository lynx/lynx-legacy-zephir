/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

class Query
{
	protected query;

	protected em;

	protected statement;

	public function __construct(var query, <EntityManager> em)
	{
		let this->query = query;
		let this->em = em;

		let this->statement = this->em->getConnection()->prepare(this->query);
	}

	public function fetchArray(var parameters = null)
	{
		return this->getResult();
	}

	/**
	 * Binds a value to a parameter
	 */
	public function bindValue(var parameter, var value, var data_type = \PDO::PARAM_STR)
	{
		this->statement->bindValue(":".parameter, value, data_type);
		return this;
	}

	/**
	 * Binds a parameter to the specified variable name
	 */
	public function bindParam(var parameter, var value, var data_type = \PDO::PARAM_STR, var lenght = null, var driver_options = null)
	{
		this->statement->bindParam(":".parameter, value, data_type, lenght, driver_options);
		return this;
	}

	/**
	 * @return mixed
	 */
	public function getResult()
	{
		var result;

		this->statement->execute();
		let result = this->statement->fetchAll();

		if (count(result) == 0) {
			return false;
		}

		return result;
	}

	/**
	 * @return array|boolean
	 */
	public function fetchAll(var parameters = null)
	{
		return this->getResult();
	}

	/**
	 * @return object|boolean
	 */
	public function fetchObject(var parameters = null)
	{
		return this->getResult();
	}

	public function fetchOne(var parameters = null)
	{
		return this->getResult();
	}

	public function execute(var parameters, var hydrationMod = null)
	{
		
	}

	public function getScalarResult()
	{
		return this->getResult();	
	}
}