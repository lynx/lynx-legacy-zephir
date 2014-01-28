/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Phalcon\ORM;

class UnitOfWork
{
    protected em;

    public function __construct(<EntityManager> em)
    {
        let this->em = em;
    }
}