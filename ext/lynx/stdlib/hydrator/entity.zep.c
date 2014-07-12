
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
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Lynx_Stdlib_Hydrator_Entity) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Stdlib\\Hydrator, Entity, lynx, stdlib_hydrator_entity, lynx_stdlib_hydrator_entity_method_entry, 0);

	zend_class_implements(lynx_stdlib_hydrator_entity_ce TSRMLS_CC, 1, lynx_stdlib_hydrator_hydrator_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Hydrator_Entity, hydrate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_8 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *data_param = NULL, *currentObject, *property = NULL, *value = NULL, *method = NULL, **_2, *_3 = NULL, *_7 = NULL;
	zval *data = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &currentObject);

	if (unlikely(Z_TYPE_P(data_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		data = data_param;

	ZEPHIR_SEPARATE_PARAM(currentObject);


	zephir_is_iterable(data, &_1, &_0, 0, 0);
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
		} else {
			ZEPHIR_CALL_FUNCTION(&_7, "property_exists", &_8, currentObject, property);
			zephir_check_call_status();
			if (zephir_is_true(_7)) {
				zephir_update_property_zval_zval(currentObject, property, value TSRMLS_CC);
			}
		}
	}
	RETURN_CCTOR(currentObject);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Hydrator_Entity, extract) {

	HashTable *_3, *_12;
	HashPosition _2, _11;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL, *_7 = NULL, *_8 = NULL, *_10 = NULL;
	zval *currentObject, *modelInfo = NULL, *methods = NULL, *method = NULL, *attribute = NULL, *attributes, *properties = NULL, *key = NULL, *value = NULL, **_4, _5 = zval_used_for_init, *_6 = NULL, *_9 = NULL, **_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &currentObject, &modelInfo);

	if (unlikely(Z_TYPE_P(currentObject) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'currentObject' must be an object") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (!modelInfo) {
		modelInfo = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(&methods, "get_class_methods", &_0, currentObject);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(attributes);
	array_init(attributes);
	ZEPHIR_CALL_FUNCTION(&properties, "get_object_vars", &_1, currentObject);
	zephir_check_call_status();
	zephir_is_iterable(methods, &_3, &_2, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(method, _4);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "/^get/", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, &_5, method);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, 3);
			ZEPHIR_CALL_FUNCTION(&attribute, "substr", &_8, method, &_5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_9, "lcfirst", &_10, attribute);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(attribute, _9);
			if (!zephir_array_isset(properties, attribute)) {
				ZEPHIR_CALL_METHOD(&_9, currentObject, Z_STRVAL_P(method),  NULL);
				zephir_check_call_status();
				zephir_array_update_zval(&attributes, attribute, &_9, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_unset(&properties, attribute, PH_SEPARATE);
			}
		}
	}
	zephir_is_iterable(properties, &_12, &_11, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
	  ; zephir_hash_move_forward_ex(_12, &_11)
	) {
		ZEPHIR_GET_HMKEY(key, _12, _11);
		ZEPHIR_GET_HVALUE(value, _13);
		zephir_array_update_zval(&attributes, key, &value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(attributes);

}

