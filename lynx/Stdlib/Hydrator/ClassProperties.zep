namespace Lynx\Stdlib\Hydrator;

class ClassProperties
{
	/**
	 * @param arrray $data
	 * $param object $currentObject
	 * @return object
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

    public static function extract(object! currentObject)
    {
    	return get_object_vars(currentObject);
    }
}