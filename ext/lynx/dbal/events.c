
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
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_DBAL_Events) {

	ZEPHIR_REGISTER_CLASS(Lynx\\DBAL, Events, lynx, dbal_events, NULL, 0);

	zend_declare_class_constant_string(lynx_dbal_events_ce, SL("AFTER_CONNECT"), "afterConnect" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_dbal_events_ce, SL("BEFORE_QUERY"), "beforeQuery" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_dbal_events_ce, SL("AFTER_QUERY"), "afterQuery" TSRMLS_CC);

	return SUCCESS;

}

