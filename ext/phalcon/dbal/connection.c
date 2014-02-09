
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
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Phalcon_DBAL_Connection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\DBAL, Connection, phalcon, dbal_connection, phalcon_dbal_connection_method_entry, 0);


	return SUCCESS;

}

PHP_METHOD(Phalcon_DBAL_Connection, __construct) {

	zval *parameters = NULL;
	zval *driver, *parameters_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &driver, &parameters_param);

		zephir_get_arrval(parameters, parameters_param);



}

