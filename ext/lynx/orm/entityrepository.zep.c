
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_ORM_EntityRepository) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, EntityRepository, lynx, orm_entityrepository, lynx_orm_entityrepository_method_entry, 0);

	/**
	 * @var EntityManager
	 */
	zend_declare_property_null(lynx_orm_entityrepository_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var ModelMetaData
	 */
	zend_declare_property_null(lynx_orm_entityrepository_ce, SL("modelWrapper"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @var EntityManager
 */
PHP_METHOD(Lynx_ORM_EntityRepository, getEm) {


	RETURN_MEMBER(this_ptr, "em");

}

PHP_METHOD(Lynx_ORM_EntityRepository, __construct) {

	zval *em, *modelWrapper;

	zephir_fetch_params(0, 2, 0, &em, &modelWrapper);



	if (!(zephir_instance_of_ev(em, lynx_orm_entitymanager_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'em' must be an instance of 'Lynx\\ORM\\EntityManager'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(modelWrapper, lynx_orm_modelmetadata_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'modelWrapper' must be an instance of 'Lynx\\ORM\\ModelMetaData'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("modelWrapper"), modelWrapper TSRMLS_CC);

}

/**
 * @param string alias
 * @return QueryBuilder
 */
PHP_METHOD(Lynx_ORM_EntityRepository, createQueryBuilder) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *_0, *_1 = NULL, *_2, *_3;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias_param);

	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(alias_param) == IS_STRING)) {
		alias = alias_param;
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "createquerybuilder",  NULL);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("modelWrapper"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, _2, SL("classname"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "from", NULL, _3, alias);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Find entity by primary key
 * @param $id
 * @return object|boolean
 */
PHP_METHOD(Lynx_ORM_EntityRepository, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "find_", 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createquerybuilder", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "find_.id = :id", 0);
	ZEPHIR_CALL_METHOD(&_2, _0, "where", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&_3, _2, "limit", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _3, "getquery",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "id", 0);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 1);
	ZEPHIR_CALL_METHOD(&_5, _4, "bindvalue", NULL, _1, id, _6);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_5, "fetchone", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Find all entities from repository
 */
PHP_METHOD(Lynx_ORM_EntityRepository, findAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "findall_", 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createquerybuilder", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _0, "getquery",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_2, "fetchall", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Find all entities from repository by column = :value
 * @param string $column
 * @param $value
 * @return object|boolean
 */
PHP_METHOD(Lynx_ORM_EntityRepository, findBy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *column_param = NULL, *value, *_0 = NULL, *_1, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_6;
	zval *column = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &column_param, &value);

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


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "find_", 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createquerybuilder", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "find_.", column, " = :column");
	ZEPHIR_CALL_METHOD(&_2, _0, "where", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _2, "getquery",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "column", 0);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 1);
	ZEPHIR_CALL_METHOD(&_5, _4, "bindvalue", NULL, _1, value, _6);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_5, "fetchall", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Find one entity from repository by column = :value
 * @param string $column
 * @param $value
 * @return object|boolean
 */
PHP_METHOD(Lynx_ORM_EntityRepository, findOneBy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *column_param = NULL, *value, *_0 = NULL, *_1, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7;
	zval *column = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &column_param, &value);

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


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "find_", 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createquerybuilder", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "find_.", column, " = :column");
	ZEPHIR_CALL_METHOD(&_2, _0, "where", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&_4, _2, "limit", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, _4, "getquery",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "column", 0);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 1);
	ZEPHIR_CALL_METHOD(&_6, _5, "bindvalue", NULL, _1, value, _7);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_6, "fetchone", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

