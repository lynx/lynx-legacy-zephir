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
			let extractValues = \Lynx\Stdlib\Hydrator\ClassProperties::extract(model);

			let insertValues = [];
			for key, value in extractValues {
				if (key == primaryField) {
					continue;
				}

				let property = modelInfo->getProperty(key);
				let insertValues[property["column"]["name"]] = value;
			}

			let result = this->em->getConnection()->insert(modelInfo->getTablename(), insertValues);
			if (result) {
				let lastInsertId = this->em->getConnection()->getDriver()->lastInsertId();
				if (primaryField) {
					let model->{primaryField} = lastInsertId;
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
