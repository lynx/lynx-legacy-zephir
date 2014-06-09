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
	 * Add element to collection
	 */
	abstract public function add(var element);
}