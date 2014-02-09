
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Phalcon_DBAL_Driver_Pdo) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\DBAL\\Driver, Pdo, phalcon, dbal_driver_pdo, phalcon_dbal_driver_pdo_method_entry, 0);

	zend_declare_property_null(phalcon_dbal_driver_pdo_ce, SL("_pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_DBAL_Driver_Pdo, __construct) {

	zval *options = NULL;
	zval *dsn_param = NULL, *username = NULL, *password = NULL, *options_param = NULL;
	zval *dsn = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &dsn_param, &username, &password, &options_param);

	if (Z_TYPE_P(dsn_param) != IS_STRING && Z_TYPE_P(dsn_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dsn' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(dsn_param) == IS_STRING) {
		dsn = dsn_param;
	} else {
		ZEPHIR_INIT_VAR(dsn);
		ZVAL_EMPTY_STRING(dsn);
	}
	if (!username) {
		username = ZEPHIR_GLOBAL(global_null);
	}
	if (!password) {
		password = ZEPHIR_GLOBAL(global_null);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}



}

PHP_METHOD(Phalcon_DBAL_Driver_Pdo, connect) {



}

PHP_METHOD(Phalcon_DBAL_Driver_Pdo, query) {

	zval *bindParams = NULL, *bindTypes = NULL;
	zval *sqlStatement_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL;
	zval *sqlStatement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlStatement_param, &bindParams_param, &bindTypes_param);

	if (Z_TYPE_P(sqlStatement_param) != IS_STRING && Z_TYPE_P(sqlStatement_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlStatement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(sqlStatement_param) == IS_STRING) {
		sqlStatement = sqlStatement_param;
	} else {
		ZEPHIR_INIT_VAR(sqlStatement);
		ZVAL_EMPTY_STRING(sqlStatement);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(bindParams);
		array_init(bindParams);
	} else {
		zephir_get_arrval(bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(bindTypes);
		array_init(bindTypes);
	} else {
		zephir_get_arrval(bindTypes, bindTypes_param);
	}



}

