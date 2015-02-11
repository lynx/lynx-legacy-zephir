/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Stdlib\Hydrator;

class Entity implements Hydrator
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
            } else {
                if (property_exists(currentObject, property)) {
                    let currentObject->{property} = value;
                }
            }
        }

        return currentObject;
    }

    /**
     * {@inheritDoc}
     */
    public static function extract(object! currentObject, var modelInfo = null)
    {
        var methods, method, attribute, attributes, properties, key, value;

        let methods = get_class_methods(currentObject);

        let attributes = [];
        let properties = get_object_vars(currentObject);

        for method in methods {
            if (preg_match("/^get/", method)) {
                let attribute = substr(method, 3);
                let attribute = lcfirst(attribute);

                if (!isset(properties[attribute])) {
                    let attributes[attribute] = currentObject->{method}();
                } else {
                    unset(properties[attribute]);
                }
            }
        }

        for key, value in properties {
            let attributes[key] = value;
        }

        return attributes;
    }
}
