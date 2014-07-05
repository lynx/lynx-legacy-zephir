
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
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_DBAL_Connection) {

	ZEPHIR_REGISTER_CLASS(Lynx\\DBAL, Connection, lynx, dbal_connection, lynx_dbal_connection_method_entry, 0);

	/**
	 * Current used driver
	 */
	zend_declare_property_null(lynx_dbal_connection_ce, SL("driver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Current used driver
 */
PHP_METHOD(Lynx_DBAL_Connection, getDriver) {


	RETURN_MEMBER(this_ptr, "driver");

}

/**
 * Construct connection
 */
PHP_METHOD(Lynx_DBAL_Connection, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *parameters, *eventsManager = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &eventsManager);

	if (!eventsManager) {
		ZEPHIR_CPY_WRT(eventsManager, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(eventsManager);
	}


	_0 = Z_TYPE_P(eventsManager) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(eventsManager, lynx_stdlib_events_manager_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'eventsManager' must be an instance of 'Lynx\\Stdlib\\Events\\Manager'", "", 0);
		return;
	}
	if (Z_TYPE_P(eventsManager) == IS_NULL) {
		ZEPHIR_INIT_NVAR(eventsManager);
		object_init_ex(eventsManager, lynx_stdlib_events_manager_ce);
		if (zephir_has_constructor(eventsManager TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "__construct", NULL);
			zephir_check_call_status();
		}
	}
	if (zephir_array_isset_string(parameters, SS("driver"))) {
		zephir_array_fetch_string(&_1, parameters, SL("driver"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("driver"), _1 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Driver didn`t find in $parameters", "lynx/DBAL/Connection.zep", 31);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "seteventsmanager", NULL, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Insert row to the table with spicifed data and types
 * return the nubmer of affected rows
 */
PHP_METHOD(Lynx_DBAL_Connection, insert) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *data = NULL, *types = NULL;
	zval *table_param = NULL, *data_param = NULL, *types_param = NULL, *query, *stmt = NULL, *value = NULL, *set, *columnName = NULL, **_2, *_3 = NULL, *_4, *_5, *_6, *_7;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &data_param, &types_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(table_param) == IS_STRING)) {
		table = table_param;
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (unlikely(Z_TYPE_P(data_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		data = data_param;

	if (!types_param) {
		ZEPHIR_INIT_VAR(types);
		array_init(types);
	} else {
	if (unlikely(Z_TYPE_P(types_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'types' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		types = types_param;

	}
	ZEPHIR_INIT_VAR(set);
	array_init(set);


	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(columnName, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVS(_3, ":", columnName, "");
		zephir_array_append(&set, _3, PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_VAR(_5);
	zephir_array_keys(_5, data TSRMLS_CC);
	zephir_fast_join_str(_4, SL(","), _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_fast_join_str(_6, SL(","), set TSRMLS_CC);
	ZEPHIR_INIT_VAR(query);
	ZEPHIR_CONCAT_SVSVSVS(query, "INSERT INTO ", table, " (", _4, ")  VALUES (", _6, ")");
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&stmt, _7, "prepare", NULL, query);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(stmt, "execute", NULL, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Update row(s) from table and return the number of updated rows
 */
PHP_METHOD(Lynx_DBAL_Connection, update) {

	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *data = NULL, *identifiers = NULL, *types = NULL;
	zval *table_param = NULL, *data_param = NULL, *identifiers_param = NULL, *types_param = NULL, *set, *stmt = NULL, *columnName = NULL, *value = NULL, **_2, *_3 = NULL, *_4, *_5, *_6, *_7, *_8, *_9 = NULL, *_11 = NULL;
	zval *table = NULL, *query = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &table_param, &data_param, &identifiers_param, &types_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(table_param) == IS_STRING)) {
		table = table_param;
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (unlikely(Z_TYPE_P(data_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		data = data_param;

	if (unlikely(Z_TYPE_P(identifiers_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'identifiers' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		identifiers = identifiers_param;

	if (!types_param) {
		ZEPHIR_INIT_VAR(types);
		array_init(types);
	} else {
	if (unlikely(Z_TYPE_P(types_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'types' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		types = types_param;

	}
	ZEPHIR_INIT_VAR(set);
	array_init(set);


	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(columnName, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "`", columnName, "` = ?");
		zephir_array_append(&set, _3, PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(", "), set TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_INIT_VAR(_6);
	zephir_array_keys(_6, identifiers TSRMLS_CC);
	zephir_fast_join_str(_5, SL(" = ? AND "), _6 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_SVSVSV(_3, "UPDATE ", table, " SET ", _4, " WHERE ", _5);
	zephir_get_strval(query, _3);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&stmt, _7, "prepare", NULL, query);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CALL_FUNCTION(&_9, "array_values", &_10, data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_11, "array_values", &_10, identifiers);
	zephir_check_call_status();
	zephir_fast_array_merge(_8, &(_9), &(_11) TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(stmt, "execute", NULL, _8);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Delete rows where $column = $key from $table
 * return the nubmer of affected rows
 */
PHP_METHOD(Lynx_DBAL_Connection, deleteByColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *column_param = NULL, *value_param = NULL, *type_param = NULL, *_0;
	zval *table = NULL, *column = NULL, *value = NULL, *type = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &table_param, &column_param, &value_param, &type_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(table_param) == IS_STRING)) {
		table = table_param;
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (unlikely(Z_TYPE_P(column_param) != IS_STRING && Z_TYPE_P(column_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'column' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(column_param) == IS_STRING)) {
		column = column_param;
	} else {
		ZEPHIR_INIT_VAR(column);
		ZVAL_EMPTY_STRING(column);
	}
	if (unlikely(Z_TYPE_P(value_param) != IS_STRING && Z_TYPE_P(value_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(value_param) == IS_STRING)) {
		value = value_param;
	} else {
		ZEPHIR_INIT_VAR(value);
		ZVAL_EMPTY_STRING(value);
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	} else {
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(type_param) == IS_STRING)) {
		type = type_param;
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVSVSV(_1, "DELETE FROM ", table, " WHERE ", column, " = ", value);
	ZEPHIR_RETURN_CALL_METHOD(_0, "execute", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Delete rows from tables where identifiers is spicifed
 * return the nubmer of affected rows
 */
PHP_METHOD(Lynx_DBAL_Connection, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zend_bool first = 1;
	zval *identifiers = NULL, *types = NULL;
	zval *table_param = NULL, *identifiers_param = NULL, *types_param = NULL, *query = NULL, *key = NULL, *value = NULL, **_3, *_4;
	zval *table = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &identifiers_param, &types_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(table_param) == IS_STRING)) {
		table = table_param;
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (unlikely(Z_TYPE_P(identifiers_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'identifiers' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		identifiers = identifiers_param;

	if (!types_param) {
		ZEPHIR_INIT_VAR(types);
		array_init(types);
	} else {
	if (unlikely(Z_TYPE_P(types_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'types' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		types = types_param;

	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "DELETE FROM ", table, " WHERE ");
	ZEPHIR_CPY_WRT(query, _0);
	zephir_is_iterable(identifiers, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (!first) {
			zephir_concat_self_str(&query, SL(" AND") TSRMLS_CC);
		} else {
			first = 0;
		}
		ZEPHIR_INIT_NVAR(query);
		ZEPHIR_CONCAT_SVSV(query, " ", key, " = ", value);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_4, "execute", NULL, query);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepares a statement for execution and returns a statement
 */
PHP_METHOD(Lynx_DBAL_Connection, prepare) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement, *smt = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&smt, _0, "prepare", NULL, statement);
	zephir_check_call_status();
	RETURN_CCTOR(smt);

}

