
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"

ZEPHIR_INIT_CLASS(Lynx_Cache_NativeArray) {

	ZEPHIR_REGISTER_CLASS_EX(Lynx\\Cache, NativeArray, lynx, cache_nativearray, lynx_cache_cachedriver_ce, lynx_cache_nativearray_method_entry, 0);

	zend_declare_property_null(lynx_cache_nativearray_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_cache_nativearray_ce, SL("instance"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_Cache_NativeArray, getInstance) {


	RETURN_MEMBER(this_ptr, "instance");

}

PHP_METHOD(Lynx_Cache_NativeArray, __construct) {

	zval *options_param = NULL, *_0;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("instance"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_Cache_NativeArray, setInstance) {

	zval *instance_param = NULL;
	zval *instance = NULL;

	zephir_fetch_params(0, 1, 0, &instance_param);

	if (unlikely(Z_TYPE_P(instance_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'instance' must be an array") TSRMLS_CC);
		RETURN_NULL();
	}

		instance = instance_param;



	zephir_update_property_this(this_ptr, SL("instance"), instance TSRMLS_CC);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Cache_NativeArray, save) {

	zval *id_param = NULL, *data, *lifeTime = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &id_param, &data, &lifeTime);

	if (unlikely(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(id_param) == IS_STRING)) {
		id = id_param;
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}
	if (!lifeTime) {
		ZEPHIR_INIT_VAR(lifeTime);
		ZVAL_LONG(lifeTime, 3600);
	}


	zephir_update_property_array(this_ptr, SL("instance"), id, data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Cache_NativeArray, delete) {

	zval *id_param = NULL, *_0, *_1;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (unlikely(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(id_param) == IS_STRING)) {
		id = id_param;
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	if (zephir_array_isset(_0, id)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
		zephir_array_unset(&_1, id, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Cache_NativeArray, get) {

	zval *id_param = NULL, *result, *_0;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (unlikely(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(id_param) == IS_STRING)) {
		id = id_param;
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&result, _0, id, 1 TSRMLS_CC)) {
		RETURN_CTOR(result);
	}
	RETURN_MM_BOOL(0);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Cache_NativeArray, flush) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("instance"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

