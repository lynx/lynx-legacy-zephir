/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\DBAL;

class RawValue
{
    protected value { get };

    public fn __construct(string! value)
    {
        let this->value = value;
    }
}