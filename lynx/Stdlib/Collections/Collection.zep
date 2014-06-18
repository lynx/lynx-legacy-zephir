/**
 * @author: Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Stdlib\Collections;

use Countable;
use IteratorAggregate;

class Collection implements Countable, IteratorAggregate
{
	/**
	 * Get elements count from collection
	 */
	abstract public function count();

	/**
	 * Get iterator
	 */
	abstract public function getIterator();

	/**
	 * Execute fuction to each element in the collection
	 */
	abstract public function map(<\Closure> func);

	/**
	 * Execute fuction to each element in the collection and
	 * remove element from collection if executed function return false
	 */
	abstract public function filter(<\Closure> func);

	/**
	 * Set current element to the first element and return it
	 */
	abstract public function first();

	/**
	 * Set current element to the last element and return it
	 */
	abstract public function last();

	/**
	 * Add element to collection
	 */
	abstract public function add(var element);
}