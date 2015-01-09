
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_DBAL_RawValue) {

	ZEPHIR_REGISTER_CLASS(Lynx\\DBAL, RawValue, lynx, dbal_rawvalue, lynx_dbal_rawvalue_method_entry, 0);

	zend_declare_property_null(lynx_dbal_rawvalue_ce, SL("value"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_DBAL_RawValue, getValue) {


	RETURN_MEMBER(this_ptr, "value");

}

PHP_METHOD(Lynx_DBAL_RawValue, __construct) {

	zval *value_param = NULL;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	if (unlikely(Z_TYPE_P(value_param) != IS_STRING && Z_TYPE_P(value_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(value_param) == IS_STRING)) {
		zephir_get_strval(value, value_param);
	} else {
		ZEPHIR_INIT_VAR(value);
		ZVAL_EMPTY_STRING(value);
	}


	zephir_update_property_this(this_ptr, SL("value"), value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

