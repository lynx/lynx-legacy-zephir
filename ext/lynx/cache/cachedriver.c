
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

}

/**
 * Save data by id
 */
PHP_METHOD(Lynx_Cache_CacheDriver, delete) {

}

/**
 * Fetch data by id
 */
PHP_METHOD(Lynx_Cache_CacheDriver, get) {

}

/**
 * Data with id exists?
 */
PHP_METHOD(Lynx_Cache_CacheDriver, exists) {

}

