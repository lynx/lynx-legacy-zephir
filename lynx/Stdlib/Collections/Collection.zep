/**
 * @author: Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Stdlib\Collections;

use Countable;
use IteratorAggregate;

class Collection implements Countable, IteratorAggregate
{
	abstract public function count();

	abstract public function getIterator();

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