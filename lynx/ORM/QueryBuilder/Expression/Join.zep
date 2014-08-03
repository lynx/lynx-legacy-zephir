
namespace Lynx\ORM\QueryBuilder\Expression;

class Join
{
    const RIGHT_JOIN     = 'RIGHT';

    const INNER_JOIN    = 'INNER';

    const LEFT_JOIN     = 'LEFT';

	private type {get};

    public fn __construct(string! type)
    {
		let this->type = type;
    }
}