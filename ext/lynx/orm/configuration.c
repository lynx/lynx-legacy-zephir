
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
#include "kernel/exception.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Lynx_ORM_Configuration) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, Configuration, lynx, orm_configuration, lynx_orm_configuration_method_entry, 0);

	zend_declare_property_null(lynx_orm_configuration_ce, SL("cacheDriver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_Configuration, getCacheDriver) {


	RETURN_MEMBER(this_ptr, "cacheDriver");

}

/**
 * Set Cache Driver
 */
PHP_METHOD(Lynx_ORM_Configuration, setCacheDriver) {

	zval *cacheDriver;

	zephir_fetch_params(0, 1, 0, &cacheDriver);



	if (!(zephir_instance_of_ev(cacheDriver, lynx_cache_cachedriver_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'cacheDriver' must be an instance of 'Lynx\\Cache\\CacheDriver'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("cacheDriver"), cacheDriver TSRMLS_CC);

}

