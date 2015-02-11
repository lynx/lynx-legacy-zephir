/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Stdlib\Hydrator;

interface Hydrator
{
    /**
     * Hydrate values to object
     */
    public static function hydrate(array! data, var currentObject);

    /**
     * Extract values from object
     */
    public static function extract(object! currentObject);
}
