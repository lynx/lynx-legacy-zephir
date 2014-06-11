
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
#include "kernel/concat.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"

ZEPHIR_INIT_CLASS(Lynx_ORM_QueryBuilder) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, QueryBuilder, lynx, orm_querybuilder, lynx_orm_querybuilder_method_entry, 0);

	zend_declare_property_string(lynx_orm_querybuilder_ce, SL("alias"), "default", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("parts"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("where"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(lynx_orm_querybuilder_ce, SL("type"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("limit"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("offset"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("order"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_querybuilder_ce, SL("SELECT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_querybuilder_ce, SL("UPDATE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_querybuilder_ce, SL("DELETE"), 3 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_QueryBuilder, getType) {


	RETURN_MEMBER(this_ptr, "type");

}

PHP_METHOD(Lynx_ORM_QueryBuilder, getLimit) {


	RETURN_MEMBER(this_ptr, "limit");

}

PHP_METHOD(Lynx_ORM_QueryBuilder, getOffset) {


	RETURN_MEMBER(this_ptr, "offset");

}

PHP_METHOD(Lynx_ORM_QueryBuilder, getOrder) {


	RETURN_MEMBER(this_ptr, "order");

}

PHP_METHOD(Lynx_ORM_QueryBuilder, __construct) {

	zval *em, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &em);



	if (!(zephir_instance_of_ev(em, lynx_orm_entitymanager_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'em' must be an instance of 'Lynx\\ORM\\EntityManager'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("where"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, select) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, delete) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 3);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, update) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 2);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, from) {

	zval *from, *alias;

	zephir_fetch_params(0, 2, 0, &from, &alias);



	zephir_update_property_this(this_ptr, SL("from"), from TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("alias"), alias TSRMLS_CC);
	RETURN_THISW();

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
	RETURN_THIS();

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
	RETURN_THIS();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, join) {

	zval *join, *alias;

	zephir_fetch_params(0, 2, 0, &join, &alias);



	RETURN_THISW();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, where) {

	zval *statement;

	zephir_fetch_params(0, 1, 0, &statement);



	zephir_update_property_array_append(this_ptr, SL("where"), statement TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, andWhere) {

	zval *statement;

	zephir_fetch_params(0, 1, 0, &statement);



	zephir_update_property_array_append(this_ptr, SL("where"), statement TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, orWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *statement, *index = NULL, *_0, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(&index, "key", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	zephir_array_fetch(&_3, _2, index, PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVSVS(_4, "(", _3, " OR ", statement, ")");
	zephir_update_property_array(this_ptr, SL("where"), index, _4 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, orderBy) {

	zval *sort = NULL;
	zval *statement, *sort_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement, &sort_param);

	if (!sort_param) {
		ZEPHIR_INIT_VAR(sort);
		ZVAL_STRING(sort, "DESC", 1);
	} else {
	if (unlikely(Z_TYPE_P(sort_param) != IS_STRING && Z_TYPE_P(sort_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sort' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(sort_param) == IS_STRING)) {
		sort = sort_param;
	} else {
		ZEPHIR_INIT_VAR(sort);
		ZVAL_EMPTY_STRING(sort);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VSV(_0, statement, " ", sort);
	zephir_update_property_this(this_ptr, SL("order"), _0 TSRMLS_CC);
	RETURN_THIS();

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "$limit must be >= 0", "lynx/ORM/QueryBuilder.zep", 123);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, limit);
	zephir_update_property_this(this_ptr, SL("limit"), _0 TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, offset) {

	zval *offset_param = NULL, *_0;
	int offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, offset);
	zephir_update_property_this(this_ptr, SL("offset"), _0 TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, wrap) {

	zval *id_param = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(id, id_param);


	ZEPHIR_CONCAT_SVS(return_value, "`", id, "`");
	RETURN_MM();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, getSQL) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sql = NULL, *_0, *rootModel = NULL, *_1, *_2 = NULL, *_3, *_4, *_5 = NULL, *_6 = NULL, *_7, *_8, *_9, *_10, *_11, *_12 = NULL, *_13, *_14, *_15, *_16;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "From field must be set", "lynx/ORM/QueryBuilder.zep", 148);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "getmodelsmanager",  NULL);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&rootModel, _2, "get", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(_4, 1)) {
			ZEPHIR_INIT_VAR(sql);
			ZVAL_STRING(sql, "SELECT *", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(_4, 2)) {
			ZEPHIR_INIT_NVAR(sql);
			ZVAL_STRING(sql, "UPDATE ", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(_4, 3)) {
			ZEPHIR_INIT_NVAR(sql);
			ZVAL_STRING(sql, "DELETE ", 1);
			break;
		}
	} while(0);

	ZEPHIR_CALL_METHOD(&_6, rootModel, "gettablename",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "wrap", NULL, _6);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("alias"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SVSV(_8, " FROM ", _5, " ", _7);
	zephir_concat_self(&sql, _8 TSRMLS_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	if (zephir_fast_count_int(_9 TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_10);
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
		zephir_fast_join_str(_10, SL(" AND "), _11 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_12);
		ZEPHIR_CONCAT_SV(_12, " WHERE ", _10);
		zephir_concat_self(&sql, _12 TSRMLS_CC);
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("order"), PH_NOISY_CC);
	if (zephir_is_true(_11)) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("order"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_12);
		ZEPHIR_CONCAT_SV(_12, " ORDER BY ", _13);
		zephir_concat_self(&sql, _12 TSRMLS_CC);
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("limit"), PH_NOISY_CC);
	if (!Z_TYPE_P(_11) == IS_NULL) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("limit"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_12);
		ZEPHIR_CONCAT_SV(_12, " LIMIT ", _13);
		zephir_concat_self(&sql, _12 TSRMLS_CC);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("offset"), PH_NOISY_CC);
		if (!Z_TYPE_P(_14) == IS_NULL) {
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("offset"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_16);
			ZEPHIR_CONCAT_SV(_16, ",", _15);
			zephir_concat_self(&sql, _16 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(sql);

}

PHP_METHOD(Lynx_ORM_QueryBuilder, getQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, *identityMap, *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(identityMap);
	object_init_ex(identityMap, lynx_orm_queryidentitymap_ce);
	if (zephir_has_constructor(identityMap TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, identityMap, "__construct", NULL);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("alias"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, identityMap, "setrootalias", NULL, _0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getsql",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, _1, "createquery", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, query, "setidentitymap", NULL, identityMap);
	zephir_check_call_status();
	RETURN_CCTOR(query);

}

