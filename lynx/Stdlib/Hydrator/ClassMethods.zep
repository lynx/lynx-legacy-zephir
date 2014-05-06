namespace Lynx\Stdlib\Hydrator;

class ClassMethods
{
	/**
	 * @param arrray $data
	 * $param object $currentObject
	 * @return object
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
}