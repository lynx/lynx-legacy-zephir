
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_ORM_Query) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, Query, lynx, orm_query, lynx_orm_query_method_entry, 0);

	/**
	 * Sql plain query
	 */
	zend_declare_property_null(lynx_orm_query_ce, SL("query"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_query_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_query_ce, SL("statement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * IdentityMap for SQL. need for hydrate data with many relations (joins)
	 */
	zend_declare_property_null(lynx_orm_query_ce, SL("identityMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_query_ce, SL("FETCH_INT"), 1 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sql plain query
 */
PHP_METHOD(Lynx_ORM_Query, getQuery) {


	RETURN_MEMBER(this_ptr, "query");

}

/**
 * IdentityMap for SQL. need for hydrate data with many relations (joins)
 */
PHP_METHOD(Lynx_ORM_Query, getIdentityMap) {


	RETURN_MEMBER(this_ptr, "identityMap");

}

/**
 * IdentityMap for SQL. need for hydrate data with many relations (joins)
 */
PHP_METHOD(Lynx_ORM_Query, setIdentityMap) {

	zval *identityMap;

	zephir_fetch_params(0, 1, 0, &identityMap);



	zephir_update_property_this(this_ptr, SL("identityMap"), identityMap TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_Query, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query, *em, *_0, *_1 = NULL, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &query, &em);



	if (!(zephir_instance_of_ev(em, lynx_orm_entitymanager_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'em' must be an instance of 'Lynx\\\\ORM\\\\EntityManager'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("query"), query TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "getconnection",  NULL);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("query"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "prepare", NULL, _3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("statement"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Binds a value to a parameter
 */
PHP_METHOD(Lynx_ORM_Query, bindValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameter, *value, *data_type = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &parameter, &value, &data_type);

	if (!data_type) {
		ZEPHIR_INIT_VAR(data_type);
		ZVAL_LONG(data_type, 2);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("statement"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, ":", parameter);
	ZEPHIR_CALL_METHOD(NULL, _0, "bindvalue", NULL, _1, value, data_type);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Binds a parameter to the specified variable name
 */
PHP_METHOD(Lynx_ORM_Query, bindParam) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameter, *value, *data_type = NULL, *lenght = NULL, *driver_options = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &parameter, &value, &data_type, &lenght, &driver_options);

	if (!data_type) {
		ZEPHIR_INIT_VAR(data_type);
		ZVAL_LONG(data_type, 2);
	}
	if (!lenght) {
		lenght = ZEPHIR_GLOBAL(global_null);
	}
	if (!driver_options) {
		driver_options = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("statement"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, ":", parameter);
	ZEPHIR_CALL_METHOD(NULL, _0, "bindparam", NULL, _1, value, data_type, lenght, driver_options);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * @return mixed
 */
PHP_METHOD(Lynx_ORM_Query, getResult) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("statement"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "execute", NULL);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("statement"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&result, _1, "fetchall",  NULL);
	zephir_check_call_status();
	if (zephir_fast_count_int(result TSRMLS_CC) == 0) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(Lynx_ORM_Query, fetchArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getresult", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return array|boolean
 */
PHP_METHOD(Lynx_ORM_Query, fetchAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getresult", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return object|boolean
 */
PHP_METHOD(Lynx_ORM_Query, fetchObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getresult", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Lynx_ORM_Query, fetchOne) {

	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL;
	HashTable *_5;
	HashPosition _4;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *result = NULL, *model = NULL, *property = NULL, *key = NULL, *value = NULL, *_1, *_2 = NULL, *insertValues, *_3, **_6, *_7, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(insertValues);
	array_init(insertValues);


	ZEPHIR_CALL_METHOD(&result, this_ptr, "getresult",  NULL);
	zephir_check_call_status();
	_0 = !zephir_is_true(result);
	if (!(_0)) {
		_0 = zephir_fast_count_int(result TSRMLS_CC) == 0;
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identityMap"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "getrootmodel",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&model, _2, "getobject",  NULL);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, result, 0, PH_NOISY | PH_READONLY, "lynx/ORM/Query.zep", 101 TSRMLS_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "lynx/ORM/Query.zep", 106);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(key, _5, _4);
		ZEPHIR_GET_HVALUE(value, _6);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("identityMap"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_8, _7, "getrootmodel",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&property, _8, "getfieldnamebycolumn", NULL, key);
		zephir_check_call_status();
		zephir_array_update_zval(&insertValues, property, &value, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_CE_STATIC(&_8, lynx_stdlib_hydrator_entity_ce, "hydrate", &_9, insertValues, model);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(model, _8);
	RETURN_CCTOR(model);

}

PHP_METHOD(Lynx_ORM_Query, execute) {

	zval *parameters, *hydrationMod = NULL;

	zephir_fetch_params(0, 1, 1, &parameters, &hydrationMod);

	if (!hydrationMod) {
		hydrationMod = ZEPHIR_GLOBAL(global_null);
	}



}

/**
 * Fetch statement and convert first column to type if it is specified
 */
PHP_METHOD(Lynx_ORM_Query, getScalarResult) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type = NULL, *result = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &type);

	if (!type) {
		type = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("statement"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "execute", NULL);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("statement"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&result, _1, "fetchcolumn",  NULL);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(type, 1)) {
			RETURN_MM_LONG(zephir_get_intval(result));
		}
		RETURN_CCTOR(result);
		break;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

