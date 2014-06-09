/**
 * @author: Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Stdlib\Collections;

use ArrayIterator;

class ArrayCollection extends Collection
{
	protected elements;

  	public function getIterator()
    {
        return new ArrayIterator(this->elements);
    }

	public function count()
	{
		return count(this->elements);
	}
}