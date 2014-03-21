/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM;

class UnitOfWork
{
    protected em;

    public function __construct(<EntityManager> em)
    {
        let this->em = em;
    }
}