
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
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_ORM_SqlBuilder) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, SqlBuilder, lynx, orm_sqlbuilder, lynx_orm_sqlbuilder_method_entry, 0);

	zend_declare_property_long(lynx_orm_sqlbuilder_ce, SL("type"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_sqlbuilder_ce, SL("limit"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(lynx_orm_sqlbuilder_ce, SL("offset"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_sqlbuilder_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_sqlbuilder_ce, SL("SELECT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_sqlbuilder_ce, SL("UPDATE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_sqlbuilder_ce, SL("DELETE"), 3 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_SqlBuilder, getLimit) {


	RETURN_MEMBER(this_ptr, "limit");

}

PHP_METHOD(Lynx_ORM_SqlBuilder, __construct) {

	zval *em;

	zephir_fetch_params(0, 1, 0, &em);



	if (!(zephir_instance_of_ev(em, lynx_orm_entitymanager_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STRW(spl_ce_InvalidArgumentException, "Parameter 'em' must be an instance of 'Lynx\\ORM\\EntityManager'");
		return;
	}
	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_SqlBuilder, select) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_SqlBuilder, delete) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 3);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_SqlBuilder, update) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 2);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_SqlBuilder, from) {



}

PHP_METHOD(Lynx_ORM_SqlBuilder, leftJoin) {



}

PHP_METHOD(Lynx_ORM_SqlBuilder, limit) {

	zval *limit_param = NULL, *_0;
	int limit;

	zephir_fetch_params(0, 1, 0, &limit_param);

	limit = zephir_get_intval(limit_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, limit);
	zephir_update_property_zval(this_ptr, SL("limit"), _0 TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_SqlBuilder, offset) {

	zval *offset_param = NULL, *_0;
	int offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, offset);
	zephir_update_property_zval(this_ptr, SL("offset"), _0 TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_SqlBuilder, getSQL) {

	zval *sql, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(_0, 1)) {
			break;
		}
	} while(0);

	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "", 1);
	RETURN_CCTOR(sql);

}

PHP_METHOD(Lynx_ORM_SqlBuilder, getQuery) {

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

