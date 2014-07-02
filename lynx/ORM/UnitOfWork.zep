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

    protected insertEntities;

    protected updateEntities;

    protected deleteEntities;

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
    	var model, modelInfo;

		try {
			for model in this->insertEntities {
				let modelInfo = this->em->getModelsManager()->get(get_class(model));

				//this->em->getConnection()->insert(modelInfo->getTablename(), \Lynx\Stdlib\Hydrator\ClassProperties::hydrate(model));
			}

			//for model in this->deleteEntities {
				//this->connection->insert;
			//}
		}

		let this->insertEntities = null;
		let this->updateEntities = null;
		let this->deleteEntities = null;
    }
}
