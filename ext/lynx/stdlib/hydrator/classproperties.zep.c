
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/hash.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Lynx_Stdlib_Hydrator_ClassProperties) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Stdlib\\Hydrator, ClassProperties, lynx, stdlib_hydrator_classproperties, lynx_stdlib_hydrator_classproperties_method_entry, 0);

	zend_class_implements(lynx_stdlib_hydrator_classproperties_ce TSRMLS_CC, 1, lynx_stdlib_hydrator_hydrator_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Hydrator_ClassProperties, hydrate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *data_param = NULL, *currentObject, *property = NULL, *value = NULL, **_2, *_3 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &currentObject);

	data = data_param;

	ZEPHIR_SEPARATE_PARAM(currentObject);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "lynx/Stdlib/Hydrator/ClassProperties.zep", 18);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(property, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_FUNCTION(&_3, "property_exists", &_4, currentObject, property);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			zephir_update_property_zval_zval(currentObject, property, value TSRMLS_CC);
		}
	}
	RETVAL_ZVAL(currentObject, 1, 0);
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Hydrator_ClassProperties, extract) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *currentObject;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &currentObject);

	if (unlikely(Z_TYPE_P(currentObject) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'currentObject' must be an object") TSRMLS_CC);
		RETURN_MM_NULL();
	}



	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", &_0, currentObject);
	zephir_check_call_status();
	RETURN_MM();

}

