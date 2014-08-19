
namespace Lynx\ORM\QueryBuilder\Expression;

class Where
{
    const EQUAL     = "=";
    const EQUAL_GREATER     = ">=";
    const EQUAL_LESS     = "<=";
    const NOT_EQUAL     = "<>";
    const GREATER     = ">";
    const LESS     = "<";

    const $IN = "IN";
    const NOT_IN     = "NOT IN";

    const IS_NULL     = "IS NULL";
    const IS_NOT_NULL     = "IS NOT NULL";

	private type;

	private rightExpr;

	private leftExpr;

    public fn __construct(string type, var leftExpr, var rightExpr)
    {
		let this->type = type;
		let this->leftExpr = leftExpr;
		let this->rightExpr = rightExpr;
    }

	public fn __toString()
    {
        return this->leftExpr . " " . this->type . " " . this->rightExpr;
    }
}