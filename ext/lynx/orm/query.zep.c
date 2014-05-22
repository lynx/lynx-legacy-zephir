
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
#include "kernel/concat.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_ORM_Query) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, Query, lynx, orm_query, lynx_orm_query_method_entry, 0);

	zend_declare_property_null(lynx_orm_query_ce, SL("query"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_query_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_query_ce, SL("statement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_Query, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query, *em, *_0, *_1 = NULL, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &query, &em);



	if (!(zephir_instance_of_ev(em, lynx_orm_entitymanager_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'em' must be an instance of 'Lynx\\ORM\\EntityManager'", "", 0);
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

