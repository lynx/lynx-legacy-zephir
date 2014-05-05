namespace Lynx\Stdlib\Hydrator;

class ClassProperties
{
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
}