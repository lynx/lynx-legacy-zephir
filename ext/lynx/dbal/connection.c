
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
#include "kernel/fcall.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_DBAL_Connection) {

	ZEPHIR_REGISTER_CLASS(Lynx\\DBAL, Connection, lynx, dbal_connection, lynx_dbal_connection_method_entry, 0);

	zend_declare_property_null(lynx_dbal_connection_ce, SL("driver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_DBAL_Connection, getDriver) {


	RETURN_MEMBER(this_ptr, "driver");

}

PHP_METHOD(Lynx_DBAL_Connection, __construct) {

	zval *driver, *parameters;

	zephir_fetch_params(0, 2, 0, &driver, &parameters);



	zephir_update_property_this(this_ptr, SL("driver"), driver TSRMLS_CC);

}

PHP_METHOD(Lynx_DBAL_Connection, prepare) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement, *smt = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&smt, _0, "prepare", NULL, statement);
	zephir_check_call_status();
	RETURN_CCTOR(smt);

}

