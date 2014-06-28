
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
#include "kernel/operators.h"
#include "Zend/zend_closures.h"


/**
 * @author: Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_Stdlib_Collections_ArrayCollection) {

	ZEPHIR_REGISTER_CLASS_EX(Lynx\\Stdlib\\Collections, ArrayCollection, lynx, stdlib_collections_arraycollection, lynx_stdlib_collections_collection_ce, lynx_stdlib_collections_arraycollection_method_entry, 0);

	zend_declare_property_null(lynx_stdlib_collections_arraycollection_ce, SL("elements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
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

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, add) {

	zval *element;

	zephir_fetch_params(0, 1, 0, &element);



	zephir_update_property_array_append(this_ptr, SL("elements"), element TSRMLS_CC);

}

/**
 * Checks is collection empty?
 */
PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, isEmpty) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count",  NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_LONG(_0, 0));

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, map) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *func, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &func);



	if (!(zephir_instance_of_ev(func, zend_ce_closure TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'func' must be an instance of 'Closure'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_map", &_2, func, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("elements"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *func, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &func);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_filter", &_2, _0, func);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("elements"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, first) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("reset", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, last) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("end", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
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

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

