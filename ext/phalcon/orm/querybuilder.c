
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
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Phalcon_ORM_QueryBuilder) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\ORM, QueryBuilder, phalcon, orm_querybuilder, phalcon_orm_querybuilder_method_entry, 0);

	zend_declare_property_null(phalcon_orm_querybuilder_ce, SL("type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_orm_querybuilder_ce, SL("limit"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_orm_querybuilder_ce, SL("offset"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_orm_querybuilder_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_orm_querybuilder_ce, SL("SELECT"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_orm_querybuilder_ce, SL("UPDATE"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_orm_querybuilder_ce, SL("DELETE"), 3 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_ORM_QueryBuilder, getLimit) {


	RETURN_MEMBER(this_ptr, "limit");

}

PHP_METHOD(Phalcon_ORM_QueryBuilder, __construct) {

	zval *em;

	zephir_fetch_params(0, 1, 0, &em);



	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);

}

PHP_METHOD(Phalcon_ORM_QueryBuilder, select) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);

}

PHP_METHOD(Phalcon_ORM_QueryBuilder, delete) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 3);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);

}

PHP_METHOD(Phalcon_ORM_QueryBuilder, update) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 2);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);

}

PHP_METHOD(Phalcon_ORM_QueryBuilder, from) {



}

PHP_METHOD(Phalcon_ORM_QueryBuilder, leftJoin) {



}

PHP_METHOD(Phalcon_ORM_QueryBuilder, limit) {

	zval *limit_param = NULL, *_0;
	int limit;

	zephir_fetch_params(0, 1, 0, &limit_param);

		limit = zephir_get_intval(limit_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, limit);
	zephir_update_property_zval(this_ptr, SL("limit"), _0 TSRMLS_CC);

}

PHP_METHOD(Phalcon_ORM_QueryBuilder, offset) {

	zval *offset_param = NULL, *_0;
	int offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

		offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, offset);
	zephir_update_property_zval(this_ptr, SL("offset"), _0 TSRMLS_CC);

}

PHP_METHOD(Phalcon_ORM_QueryBuilder, getSQL) {

	zval *sql;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "", 1);
	RETURN_CCTOR(sql);

}

PHP_METHOD(Phalcon_ORM_QueryBuilder, getQuery) {

	zval *query, *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, this_ptr, "getsql");
	ZEPHIR_INIT_VAR(query);
	zephir_call_method_p1(query, _0, "createquery", _1);
	RETURN_CCTOR(query);

}

