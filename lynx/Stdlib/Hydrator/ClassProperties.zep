/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Stdlib\Hydrator;

class ClassProperties implements Hydrator
{
    /**
     * {@inheritDoc}
     */
    public static function hydrate(array! data, var currentObject)
    {
        var property, value;

        for property, value in data {
            if (property_exists(currentObject, property)) {
                let currentObject->{property} = value;
            }
        }

        return currentObject;
    }

    /**
     * {@inheritDoc}
     */
    public static function extract(object! currentObject)
    {
        return get_object_vars(currentObject);
    }
}
