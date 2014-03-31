
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


ZEPHIR_INIT_CLASS(Lynx_Cache_Memcache) {

	ZEPHIR_REGISTER_CLASS_EX(Lynx\\Cache, Memcache, lynx, cache_memcache, lynx_cache_cachedriver_ce, lynx_cache_memcache_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Lynx_Cache_Memcache, save) {

	zval *id_param = NULL, *data, *lifeTime = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &id_param, &data, &lifeTime);

	if (Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(id_param) == IS_STRING) {
		id = id_param;
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}
	if (!lifeTime) {
		ZEPHIR_INIT_VAR(lifeTime);
		ZVAL_LONG(lifeTime, 0);
	}



}

PHP_METHOD(Lynx_Cache_Memcache, delete) {

	zval *id_param = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(id_param) == IS_STRING) {
		id = id_param;
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}



}

PHP_METHOD(Lynx_Cache_Memcache, get) {

	zval *id_param = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(id_param) == IS_STRING) {
		id = id_param;
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}



}

PHP_METHOD(Lynx_Cache_Memcache, exists) {

	zval *id_param = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(id_param) == IS_STRING) {
		id = id_param;
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}



}

