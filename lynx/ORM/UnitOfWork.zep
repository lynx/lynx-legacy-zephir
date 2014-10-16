/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

class UnitOfWork
{
	const STATE_MANAGED = 1;

	const STATE_NEW = 2;

	/**
	 * @var EntityManager
	 */
    protected em;

    protected insertEntities = [];

    protected updateEntities = [];

    protected deleteEntities = [];

    public function __construct(<EntityManager> em)
    {
        let this->em = em;
    }

    public function insert(object! entity)
    {
		let this->insertEntities[] = entity;
    }

    public function update(object! entity)
    {
    	let this->updateEntities[] = entity;
    }

    public function delete(object! entity)
    {
		let this->deleteEntities[] = entity;
    }

	protected function convertToScalar(var value, var columnType = null)
	{
		switch(columnType) {
			case "datetime":
				if value instanceof \DateTime {
					return value->format("Y-m-d H:i:s");
				}

				return value;
				break;
			default:
				return value;
				break;
		}
	}

    public function commit(var entity = null)
    {
    	var model, modelInfo, result, primaryField;

		/**
		 * Remove try catch from hear because bug in Zephir :(
		 * @link https://github.com/lynx/lynx/issues/2
		 */

		for model in this->insertEntities {
			var lastInsertId, extractValues, insertValues, property, value, key;

			let modelInfo = this->em->getModelsManager()->get(get_class(model));
			let primaryField = modelInfo->getPrimaryFieldName();
			let extractValues = \Lynx\Stdlib\Hydrator\Entity::extract(model, modelInfo);

			let insertValues = [];
			for key, value in extractValues {
				if (key == primaryField) {
					continue;
				}

				let property = modelInfo->getColumn(key);
				if (!property) {
					continue;
				}

				let insertValues[property->name] = this->convertToScalar(value, property->type);
			}

			let result = this->em->getConnection()->insert(modelInfo->getTablename(), insertValues);
			if (result) {
			    /**
			     * @todo fetch seq id
			     */
				let lastInsertId = this->em->getConnection()->getDriver()->lastInsertId(modelInfo->getTablename() . "_id_seq");
				if (primaryField) {
					let model->{primaryField} = (int) lastInsertId;
				}
			}
		}

		for model in this->updateEntities {
			var data, identifiers;

			let modelInfo = this->em->getModelsManager()->get(get_class(model));

			let data = \Lynx\Stdlib\Hydrator\ClassProperties::extract(model);

			let primaryField = modelInfo->getPrimaryFieldName();
			if (primaryField) {
				let identifiers = [
					primaryField : data[primaryField]
				];
			} else {
				throw new \Exception("Entity`s PrimaryField is not set.");
			}

			this->em->getConnection()->update(modelInfo->getTablename(), data, identifiers);
		}

		for model in this->deleteEntities {
			let modelInfo = this->em->getModelsManager()->get(get_class(model));
			this->em->getConnection()->delete(modelInfo->getTablename(), \Lynx\Stdlib\Hydrator\ClassProperties::extract(model));
		}


		let this->insertEntities = [];
		let this->updateEntities = [];
		let this->deleteEntities = [];
    }
}
