/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

class UnitOfWork
{
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
    }

    public function update(object! entity)
    {
    }

    public function delete(object! entity)
    {
    }

    public function commit(var entity = null)
    {
		let this->insertEntities = null;
		let this->updateEntities = null;
		let this->deleteEntities = null;
    }
}
