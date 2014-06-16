
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Lynx_Cache_Driver) {

	ZEPHIR_REGISTER_INTERFACE(Lynx\\Cache, Driver, lynx, cache_driver, lynx_cache_driver_method_entry);

	return SUCCESS;

}

/**
 * To initialize cache provider
 */
ZEPHIR_DOC_METHOD(Lynx_Cache_Driver, getInstance);

/**
 * Save data
 */
ZEPHIR_DOC_METHOD(Lynx_Cache_Driver, save);

/**
 * Save data by id
 */
ZEPHIR_DOC_METHOD(Lynx_Cache_Driver, delete);

/**
 * Fetch data by id
 */
ZEPHIR_DOC_METHOD(Lynx_Cache_Driver, get);

/**
 * Is row exist?
 */
ZEPHIR_DOC_METHOD(Lynx_Cache_Driver, exists);

