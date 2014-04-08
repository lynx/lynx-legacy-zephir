
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"


/**
 * Abstract class for Cache Drivers
 */
ZEPHIR_INIT_CLASS(Lynx_Cache_CacheDriver) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Cache, CacheDriver, lynx, cache_cachedriver, lynx_cache_cachedriver_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * To initialize cache provider
 */
PHP_METHOD(Lynx_Cache_CacheDriver, getInstance) {



}

/**
 * Save data
 */
PHP_METHOD(Lynx_Cache_CacheDriver, save) {

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



}

/**
 * Save data by id
 */
PHP_METHOD(Lynx_Cache_CacheDriver, delete) {

	zval *id_param = NULL;
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



}

/**
 * Fetch data by id
 */
PHP_METHOD(Lynx_Cache_CacheDriver, get) {

	zval *id_param = NULL;
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



}

/**
 * Data with id exists?
 */
PHP_METHOD(Lynx_Cache_CacheDriver, exists) {

	zval *id_param = NULL;
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



}

