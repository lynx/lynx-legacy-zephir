/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\ORM\QueryBuilder\Expression;

class Join
{
    const RIGHT_JOIN     = "RIGHT";

    const INNER_JOIN    = "INNER";

    const LEFT_JOIN     = "LEFT";

    private type;

    private join;

    private alias;

    private condition;

    public fn __construct(string type, var join, var alias, var condition = null)
    {
        let this->type = type;
        let this->join = join;
        let this->alias = alias;
        let this->condition = condition;
    }

    public fn __toString()
    {
        return this->type . " JOIN " . this->join
             . (this->alias ? " " . this->alias : "")
             . " ON "
             . (this->condition ? this->condition : "");
    }
}
