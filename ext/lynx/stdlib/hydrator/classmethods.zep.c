
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
		}
	}
	RETURN_CCTOR(currentObject);

}

