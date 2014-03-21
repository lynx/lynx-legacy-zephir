
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
ZEPHIR_INIT_CLASS(Lynx_ORM_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Lynx\\ORM, Exception, lynx, orm_exception, zend_exception_get_default(TSRMLS_C), NULL, 0);

	return SUCCESS;

}

