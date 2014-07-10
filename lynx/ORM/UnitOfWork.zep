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
    	var model, modelInfo, result;

		/**
		 * Remove try catch from hear because bug in Zephir :(
		 */

		for model in this->insertEntities {
			var lastInsertId, primaryField;

			let modelInfo = this->em->getModelsManager()->get(get_class(model));
			let result = this->em->getConnection()->insert(modelInfo->getTablename(), \Lynx\Stdlib\Hydrator\ClassProperties::extract(model));

			if (result) {
				let lastInsertId = this->em->getConnection()->getDriver()->lastInsertId();

				let primaryField = modelInfo->getPrimaryFieldName();
				if (primaryField) {
					let model->{primaryField} = lastInsertId;
				}
			}
		}

		for model in this->updateEntities {
			var data, identifiers;

			let modelInfo = this->em->getModelsManager()->get(get_class(model));

			let data = \Lynx\Stdlib\Hydrator\ClassProperties::extract(model);
			let identifiers = [
				"id" : data["id"]
			];

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
