/**
 * @author: Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Stdlib\Collections;

use ArrayIterator;

class ArrayCollection extends Collection
{
	protected elements;

	/**
	 * {@inheritDoc}
	 */
	public function __construct(array! elements = [])
	{
		let this->elements = elements;
	}

	/**
	 * {@inheritDoc}
	 */
	public function add(element)
	{
		let this->elements[] = element;
	}

	/**
	 * {@inheritDoc}
	 */
	public function map(<\Closure> func)
	{
		let this->elements = array_map(func, this->elements);
	}

	/**
	 * {@inheritDoc}
	 */
	public function filter(func)
	{
		let this->elements = array_filter(this->elements, func);
	}

	/**
	 * {@inheritDoc}
	 */
	public function first()
	{
		return reset(this->elements);
	}

	/**
	 * {@inheritDoc}
	 */
	public function last()
	{
		return end(this->elements);
	}

	/**
	 * {@inheritDoc}
	 */
  	public function getIterator() -> <ArrayIterator>
    {
        return new ArrayIterator(this->elements);
    }

	/**
	 * {@inheritDoc}
	 */
	public function count() -> int
	{
		return count(this->elements);
	}
}