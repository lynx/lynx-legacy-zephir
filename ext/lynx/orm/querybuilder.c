
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_ORM_QueryBuilder) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, QueryBuilder, lynx, orm_querybuilder, lynx_orm_querybuilder_method_entry, 0);

	zend_declare_property_long(lynx_orm_querybuilder_ce, SL("type"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("limit"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(lynx_orm_querybuilder_ce, SL("offset"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_querybuilder_ce, SL("SELECT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_querybuilder_ce, SL("UPDATE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_querybuilder_ce, SL("DELETE"), 3 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_QueryBuilder, getLimit) {


	RETURN_MEMBER(this_ptr, "limit");

}

PHP_METHOD(Lynx_ORM_QueryBuilder, __construct) {

	zval *em;

	zephir_fetch_params(0, 1, 0, &em);



	if (!(zephir_instance_of_ev(em, lynx_orm_entitymanager_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'em' must be an instance of 'Lynx\\ORM\\EntityManager'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_QueryBuilder, select) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_QueryBuilder, delete) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 3);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_QueryBuilder, update) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 2);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_QueryBuilder, from) {

	zval *from, *alias;

	zephir_fetch_params(0, 2, 0, &from, &alias);




}

PHP_METHOD(Lynx_ORM_QueryBuilder, leftJoin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *join, *alias, *parentAlias = NULL, _0, *_1, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &join, &alias);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, '.');
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, join, &_0, 0 );
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_FUNCTION(&parentAlias, "substr", &_3, join, &_2, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, rightJoin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *join, *alias, *parentAlias = NULL, _0, *_1, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &join, &alias);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, '.');
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, join, &_0, 0 );
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_FUNCTION(&parentAlias, "substr", &_3, join, &_2, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, join) {

	zval *join, *alias;

	zephir_fetch_params(0, 2, 0, &join, &alias);




}

PHP_METHOD(Lynx_ORM_QueryBuilder, where) {

	zval *statement;

	zephir_fetch_params(0, 1, 0, &statement);




}

PHP_METHOD(Lynx_ORM_QueryBuilder, andWhere) {

	zval *statement;

	zephir_fetch_params(0, 1, 0, &statement);




}

PHP_METHOD(Lynx_ORM_QueryBuilder, orWhere) {

	zval *statement;

	zephir_fetch_params(0, 1, 0, &statement);




}

PHP_METHOD(Lynx_ORM_QueryBuilder, orderBy) {

	zval *sort;

	zephir_fetch_params(0, 1, 0, &sort);




}

/**
 * Set limit to the query
 */
PHP_METHOD(Lynx_ORM_QueryBuilder, limit) {

	zval *limit_param = NULL, *_0;
	int limit;

	zephir_fetch_params(0, 1, 0, &limit_param);

	limit = zephir_get_intval(limit_param);


	if (limit <= 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "$limit must be >= 0", "lynx/ORM/QueryBuilder.zep", 90);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, limit);
	zephir_update_property_zval(this_ptr, SL("limit"), _0 TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_QueryBuilder, offset) {

	zval *offset_param = NULL, *_0;
	int offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, offset);
	zephir_update_property_zval(this_ptr, SL("offset"), _0 TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_QueryBuilder, getSQL) {

	zval *sql = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(_0, 1)) {
			ZEPHIR_INIT_VAR(sql);
			ZVAL_STRING(sql, "SELECT ", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 2)) {
			ZEPHIR_INIT_NVAR(sql);
			ZVAL_STRING(sql, "UPDATE ", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 3)) {
			ZEPHIR_INIT_NVAR(sql);
			ZVAL_STRING(sql, "DELETE ", 1);
			break;
		}
	} while(0);

	RETURN_CCTOR(sql);

}

PHP_METHOD(Lynx_ORM_QueryBuilder, getQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getsql",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, _0, "createquery", NULL, _1);
	zephir_check_call_status();
	RETURN_CCTOR(query);

}

