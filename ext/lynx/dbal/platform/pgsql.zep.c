
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
#include "kernel/memory.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_DBAL_Platform_Pgsql) {

	ZEPHIR_REGISTER_CLASS(Lynx\\DBAL\\Platform, Pgsql, lynx, dbal_platform_pgsql, lynx_dbal_platform_pgsql_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Lynx_DBAL_Platform_Pgsql, wrap) {

	zval *id;

	zephir_fetch_params(0, 1, 0, &id);



	RETVAL_ZVAL(id, 1, 0);
	return;

}

