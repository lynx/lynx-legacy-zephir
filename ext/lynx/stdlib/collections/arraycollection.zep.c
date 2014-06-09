
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


/**
 * @author: Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_Stdlib_Collections_ArrayCollection) {

	ZEPHIR_REGISTER_CLASS_EX(Lynx\\Stdlib\\Collections, ArrayCollection, lynx, stdlib_collections_arraycollection, lynx_stdlib_collections_collection_ce, lynx_stdlib_collections_arraycollection_method_entry, 0);

	zend_declare_property_null(lynx_stdlib_collections_arraycollection_ce, SL("elements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, __construct) {

	zval *elements_param = NULL;
	zval *elements = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &elements_param);

	if (!elements_param) {
		ZEPHIR_INIT_VAR(elements);
		array_init(elements);
	} else {
	if (unlikely(Z_TYPE_P(elements_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'elements' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		elements = elements_param;

	}


	zephir_update_property_this(this_ptr, SL("elements"), elements TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, add) {

	zval *element;

	zephir_fetch_params(0, 1, 0, &element);



	zephir_update_property_array_append(this_ptr, SL("elements"), element TSRMLS_CC);

}

PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, getIterator) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zend_class_entry *_0;

	ZEPHIR_MM_GROW();

	_0 = zend_fetch_class(SL("ArrayIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

