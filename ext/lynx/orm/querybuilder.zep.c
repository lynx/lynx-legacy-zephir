
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
#include "kernel/fcall.h"
#include "concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/hash.h"

ZEPHIR_INIT_CLASS(Lynx_ORM_QueryBuilder) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, QueryBuilder, lynx, orm_querybuilder, lynx_orm_querybuilder_method_entry, 0);

	zend_declare_property_string(lynx_orm_querybuilder_ce, SL("alias"), "default", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("parts"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(lynx_orm_querybuilder_ce, SL("columns"), "*", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("where"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(lynx_orm_querybuilder_ce, SL("type"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("limit"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("offset"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("order"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("joins"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_ce, SL("rootModel"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

PHP_METHOD(Lynx_ORM_QueryBuilder, getJoins) {


	RETURN_MEMBER(this_ptr, "joins");

}

PHP_METHOD(Lynx_ORM_QueryBuilder, __construct) {

	zval *em, *_0, *_1;

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
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("joins"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, select) {

	zval *columns = NULL, *_0;

	zephir_fetch_params(0, 0, 1, &columns);

	if (!columns) {
		columns = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);
	if (!Z_TYPE_P(columns) == IS_NULL) {
		zephir_update_property_this(this_ptr, SL("columns"), columns TSRMLS_CC);
	}
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *from, *alias, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &from, &alias);



	zephir_update_property_this(this_ptr, SL("from"), from TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("alias"), alias TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "getmodelsmanager",  NULL);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "get", NULL, _3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("rootModel"), _2 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("rootModel"), PH_NOISY_CC);
	if (Z_TYPE_P(_4) == IS_NULL) {
		ZEPHIR_INIT_VAR(_5);
		object_init_ex(_5, zend_exception_get_default(TSRMLS_C));
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SVS(_7, "Cant find model by alias '", _6, "'");
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5, "lynx/ORM/QueryBuilder.zep", 77 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, prepareJoin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *joinType, *parentAlias, *modelName, *alias, *relationModel = NULL, *targetProperty = NULL, *condition, *_0, *_1, *_2 = NULL, *_3, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL, *_8 = NULL, *_9, *_10, *_11 = NULL, *_12 = NULL, *_13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &joinType, &parentAlias, &modelName, &alias);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rootModel"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&targetProperty, _0, "getproperty", NULL, modelName);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "getmodelsmanager",  NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, targetProperty, SL("targetEntity"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&relationModel, _2, "get", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "wrap", NULL, parentAlias);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property(&_6, targetProperty, SL("name"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "wrap", NULL, _6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "wrap", NULL, alias);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_9);
	zephir_read_property(&_9, targetProperty, SL("referencedColumnName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "wrap", NULL, _9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(condition);
	ZEPHIR_CONCAT_VSVSVSV(condition, _4, ".", _5, " = ", _7, ".", _8);
	ZEPHIR_INIT_VAR(_10);
	object_init_ex(_10, lynx_orm_querybuilder_expression_join_ce);
	ZEPHIR_CALL_METHOD(&_12, relationModel, "gettablename",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "wrap", NULL, _12);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "wrap", NULL, alias);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, joinType, _11, _13, condition);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("joins"), alias, _10 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, leftJoin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *join, *alias, *aliases, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &join, &alias);



	ZEPHIR_INIT_VAR(aliases);
	zephir_fast_explode_str(aliases, SL("."), join, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_0, aliases, 0, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 99 TSRMLS_CC);
	zephir_array_fetch_long(&_1, aliases, 1, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 99 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "LEFT", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "preparejoin", NULL, _2, _0, _1, alias);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, rightJoin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *join, *alias, *aliases, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &join, &alias);



	ZEPHIR_INIT_VAR(aliases);
	zephir_fast_explode_str(aliases, SL("."), join, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_0, aliases, 0, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 109 TSRMLS_CC);
	zephir_array_fetch_long(&_1, aliases, 1, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 109 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "RIGHT", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "preparejoin", NULL, _2, _0, _1, alias);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, innerJoin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *join, *alias, *aliases, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &join, &alias);



	ZEPHIR_INIT_VAR(aliases);
	zephir_fast_explode_str(aliases, SL("."), join, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_0, aliases, 0, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 119 TSRMLS_CC);
	zephir_array_fetch_long(&_1, aliases, 1, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 119 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "INNER", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "preparejoin", NULL, _2, _0, _1, alias);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, join) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *join, *alias, *aliases, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &join, &alias);



	ZEPHIR_INIT_VAR(aliases);
	zephir_fast_explode_str(aliases, SL("."), join, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_0, aliases, 0, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 129 TSRMLS_CC);
	zephir_array_fetch_long(&_1, aliases, 1, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 129 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "preparejoin", NULL, _2, _0, _1, alias);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, Where) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *column, *value, *comparison = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &column, &value, &comparison);

	if (!comparison) {
		ZEPHIR_INIT_VAR(comparison);
		ZVAL_STRING(comparison, "=", 1);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "addwhere", NULL, column, value, comparison);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("where"), _0 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, orWhere) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *column, *value, *comparison = NULL, *index = NULL, *statement = NULL, *_0, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &column, &value, &comparison);

	if (!comparison) {
		ZEPHIR_INIT_VAR(comparison);
		ZVAL_STRING(comparison, "=", 1);
	}


	ZEPHIR_CALL_METHOD(&statement, this_ptr, "addwhere", NULL, column, value, comparison);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(&index, "key", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	zephir_array_fetch(&_3, _2, index, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 148 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVSVS(_4, "(", _3, " OR ", statement, ")");
	zephir_update_property_array(this_ptr, SL("where"), index, _4 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Lynx_ORM_QueryBuilder, addWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *column, *value, *comparison, *tmpField, *property = NULL, *propertyStatement = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &column, &value, &comparison);



	ZEPHIR_INIT_VAR(tmpField);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_trim(_0, column, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_fast_explode_str(tmpField, SL("."), _0, LONG_MAX TSRMLS_CC);
	if (Z_TYPE_P(tmpField) == IS_ARRAY) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("rootModel"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		zephir_array_fetch_long(&_3, tmpField, 1, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 160 TSRMLS_CC);
		zephir_fast_trim(_2, _3, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&property, _1, "getcolumn", NULL, _2);
		zephir_check_call_status();
		//missing empty
		zephir_array_fetch_long(&_4, tmpField, 0, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 161 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_5);
		zephir_read_property(&_5, property, SL("name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(propertyStatement);
		ZEPHIR_CONCAT_VSV(propertyStatement, _4, ".", _5);
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("rootModel"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		zephir_array_fetch_long(&_3, tmpField, 0, PH_NOISY | PH_READONLY, "lynx/ORM/QueryBuilder.zep", 163 TSRMLS_CC);
		zephir_fast_trim(_2, _3, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&property, _1, "getcolumn", NULL, _2);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(propertyStatement);
		zephir_read_property(&propertyStatement, property, SL("name"), PH_NOISY_CC);
	}
	object_init_ex(return_value, lynx_orm_querybuilder_expression_where_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, propertyStatement, value, comparison);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set order by to the query
 */
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "$limit must be >= 0", "lynx/ORM/QueryBuilder.zep", 186);
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

	HashTable *_10;
	HashPosition _9;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *sql = NULL, *value = NULL, *_0, *_1, *_2, *_3 = NULL, *_4 = NULL, *_5, *_6, *_7, *_8, **_11, *_12 = NULL, *_13, *_14 = NULL, *_15, *_16, *_17;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "From field must be set", "lynx/ORM/QueryBuilder.zep", 211);
		return;
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(_1, 1)) {
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("columns"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(sql);
			ZEPHIR_CONCAT_SV(sql, "SELECT ", _2);
			break;
		}
		if (ZEPHIR_IS_LONG(_1, 2)) {
			ZEPHIR_INIT_NVAR(sql);
			ZVAL_STRING(sql, "UPDATE ", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(_1, 3)) {
			ZEPHIR_INIT_NVAR(sql);
			ZVAL_STRING(sql, "DELETE ", 1);
			break;
		}
	} while(0);

	_2 = zephir_fetch_nproperty_this(this_ptr, SL("rootModel"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _2, "gettablename",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "wrap", NULL, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("alias"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SVSV(_6, " FROM ", _3, " ", _5);
	zephir_concat_self(&sql, _6 TSRMLS_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("joins"), PH_NOISY_CC);
	if (zephir_fast_count_int(_7 TSRMLS_CC) > 0) {
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("joins"), PH_NOISY_CC);
		zephir_is_iterable(_8, &_10, &_9, 0, 0, "lynx/ORM/QueryBuilder.zep", 232);
		for (
		  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HVALUE(value, _11);
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_SV(_12, " ", value);
			zephir_concat_self(&sql, _12 TSRMLS_CC);
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	if (zephir_fast_count_int(_2 TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_13);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
		zephir_fast_join_str(_13, SL(" AND "), _8 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_12);
		ZEPHIR_CONCAT_SV(_12, " WHERE ", _13);
		zephir_concat_self(&sql, _12 TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("order"), PH_NOISY_CC);
	if (zephir_is_true(_2)) {
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("order"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_14);
		ZEPHIR_CONCAT_SV(_14, " ORDER BY ", _8);
		zephir_concat_self(&sql, _14 TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("limit"), PH_NOISY_CC);
	if (!Z_TYPE_P(_2) == IS_NULL) {
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("limit"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_14);
		ZEPHIR_CONCAT_SV(_14, " LIMIT ", _8);
		zephir_concat_self(&sql, _14 TSRMLS_CC);
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("offset"), PH_NOISY_CC);
		if (!Z_TYPE_P(_15) == IS_NULL) {
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("offset"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_17);
			ZEPHIR_CONCAT_SV(_17, ",", _16);
			zephir_concat_self(&sql, _17 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(sql);

}

PHP_METHOD(Lynx_ORM_QueryBuilder, getQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, *identityMap, *sql = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&sql, this_ptr, "getsql",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(identityMap);
	object_init_ex(identityMap, lynx_orm_queryidentitymap_ce);
	if (zephir_has_constructor(identityMap TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, identityMap, "__construct", NULL);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rootModel"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, identityMap, "setrootmodel", NULL, _0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("alias"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, identityMap, "setrootalias", NULL, _1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _2, "createquery", NULL, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, query, "setidentitymap", NULL, identityMap);
	zephir_check_call_status();
	RETURN_CCTOR(query);

}

