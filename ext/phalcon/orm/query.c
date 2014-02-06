
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


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Phalcon_ORM_Query) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\ORM, Query, phalcon, orm_query, phalcon_orm_query_method_entry, 0);

	zend_declare_property_null(phalcon_orm_query_ce, SL("query"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_orm_query_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_ORM_Query, __construct) {

	zval *query, *em;

	zephir_fetch_params(0, 2, 0, &query, &em);



	zephir_update_property_this(this_ptr, SL("query"), query TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);

}

PHP_METHOD(Phalcon_ORM_Query, fetchArray) {

	zval *parameters = NULL;

	zephir_fetch_params(0, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}



}

PHP_METHOD(Phalcon_ORM_Query, fetchAll) {

	zval *parameters = NULL;

	zephir_fetch_params(0, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}



}

PHP_METHOD(Phalcon_ORM_Query, fetchObject) {

	zval *parameters = NULL;

	zephir_fetch_params(0, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}



}

PHP_METHOD(Phalcon_ORM_Query, fetchOne) {

	zval *parameters = NULL;

	zephir_fetch_params(0, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}



}

