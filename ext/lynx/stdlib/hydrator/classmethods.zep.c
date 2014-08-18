
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Lynx_Stdlib_Hydrator_ClassMethods) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Stdlib\\Hydrator, ClassMethods, lynx, stdlib_hydrator_classmethods, lynx_stdlib_hydrator_classmethods_method_entry, 0);

	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Hydrator_ClassMethods, hydrate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *data_param = NULL, *currentObject, *property = NULL, *value = NULL, *method = NULL, **_2, *_3 = NULL;
	zval *data = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &currentObject);

	if (unlikely(Z_TYPE_P(data_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		data = data_param;



	zephir_is_iterable(data, &_1, &_0, 0, 0, "lynx/Stdlib/Hydrator/ClassMethods.zep", 20);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(property, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_FUNCTION(&_3, "ucfirst", &_4, property);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(method);
		ZEPHIR_CONCAT_SV(method, "set", _3);
		if ((zephir_method_exists(currentObject, method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_INIT_NVAR(_5);
			array_init_size(_5, 2);
			zephir_array_fast_append(_5, value);
			ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_6, method, currentObject, _5);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(currentObject);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Hydrator_ClassMethods, extract) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL;
	zval *currentObject, *methods = NULL, *method = NULL, *attribute = NULL, *attributes, **_3, *_4 = NULL, *_5 = NULL, _7 = zval_used_for_init, *_9 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &currentObject);

	if (unlikely(Z_TYPE_P(currentObject) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'currentObject' must be an object") TSRMLS_CC);
		RETURN_MM_NULL();
	}



	ZEPHIR_CALL_FUNCTION(&methods, "get_class_methods", &_0, currentObject);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(attributes);
	array_init(attributes);
	zephir_is_iterable(methods, &_2, &_1, 0, 0, "lynx/Stdlib/Hydrator/ClassMethods.zep", 44);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(method, _3);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "/^get/", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "preg_match", &_6, _4, method);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, 3);
			ZEPHIR_CALL_FUNCTION(&attribute, "substr", &_8, method, &_7);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_9, "property_exists", &_10, currentObject, attribute);
			zephir_check_call_status();
			if (!zephir_is_true(_9)) {
				ZEPHIR_CALL_FUNCTION(&_11, "lcfirst", &_12, attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(attribute, _11);
				ZEPHIR_CALL_METHOD(&_11, currentObject, "attributes",  NULL);
				zephir_check_call_status();
				zephir_array_update_zval(&attributes, attribute, &_11, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(attributes);

}

