/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Stdlib\Hydrator;

class ClassMethods
{
    /**
     * {@inheritDoc}
     */
    public static function hydrate(array! data, var currentObject)
    {
        var property, value, method;

        for property, value in data {
            let method = "set" . ucfirst(property);

            if (method_exists(currentObject, method)) {
                call_user_func(method, currentObject, [value]);
            }
        }

        return currentObject;
    }

    /**
     * {@inheritDoc}
     */
    public static function extract(object! currentObject)
    {
        var methods, method, attribute, attributes;

        let methods = get_class_methods(currentObject);

        let attributes = [];

        for method in methods {
            if (preg_match("/^get/", method)) {
                let attribute = substr(method, 3);
                if (!property_exists(currentObject, attribute)) {
                    let attribute = lcfirst(attribute);
                    let attributes[attribute] = currentObject->attributes();
                }
            }
        }

        return attributes;
    }
}
