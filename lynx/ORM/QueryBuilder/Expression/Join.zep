
namespace Lynx\ORM\QueryBuilder\Expression;

class Join
{
    const RIGHT_JOIN     = 'RIGHT';

    const INNER_JOIN    = 'INNER';

    const LEFT_JOIN     = 'LEFT';

	private type {get};

    public fn __construct(string! type, var join, var alias, var conditionType, var condition = null)
    {
		let this->type = type;
    }
}