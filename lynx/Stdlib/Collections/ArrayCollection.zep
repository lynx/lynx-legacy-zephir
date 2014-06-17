/**
 * @author: Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Stdlib\Collections;

use ArrayIterator;

class ArrayCollection extends Collection
{
	protected elements;

	public function __construct(array! elements = [])
	{
		let this->elements = elements;
	}

	public function add(element)
	{
		let this->elements[] = element;
	}

	public function first()
	{
		return reset(this->elements);
	}

	public function last()
	{
		return end(this->elements);
	}

  	public function getIterator() -> <ArrayIterator>
    {
        return new ArrayIterator(this->elements);
    }

	public function count() -> int
	{
		return count(this->elements);
	}
}