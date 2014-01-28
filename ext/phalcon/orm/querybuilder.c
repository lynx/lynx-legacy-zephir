
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
ZEPHIR_INIT_CLASS(Phalcon_ORM_QueryBuilder) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\ORM, QueryBuilder, phalcon, orm_querybuilder, NULL, 0);


	return SUCCESS;

}

