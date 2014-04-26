
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
#include "kernel/array.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_ORM_EntityManager) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, EntityManager, lynx, orm_entitymanager, lynx_orm_entitymanager_method_entry, 0);

	/**
	 * @var UnitOfWork
	 */
	zend_declare_property_null(lynx_orm_entitymanager_ce, SL("unitOfWork"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_entitymanager_ce, SL("connection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_entitymanager_ce, SL("modelsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_entitymanager_ce, SL("eventManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_entitymanager_ce, SL("repositories"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_entitymanager_ce, SL("configuration"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_EntityManager, getConnection) {


	RETURN_MEMBER(this_ptr, "connection");

}

PHP_METHOD(Lynx_ORM_EntityManager, getModelsManager) {


	RETURN_MEMBER(this_ptr, "modelsManager");

}

PHP_METHOD(Lynx_ORM_EntityManager, getEventManager) {


	RETURN_MEMBER(this_ptr, "eventManager");

}

PHP_METHOD(Lynx_ORM_EntityManager, getConfiguration) {


	RETURN_MEMBER(this_ptr, "configuration");

}

PHP_METHOD(Lynx_ORM_EntityManager, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connection, *configuration, *eventManager, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &connection, &configuration, &eventManager);



	if (!(zephir_instance_of_ev(connection, lynx_dbal_connection_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'connection' must be an instance of 'Lynx\\DBAL\\Connection'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(configuration, lynx_orm_configuration_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'configuration' must be an instance of 'Lynx\\ORM\\Configuration'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(eventManager, lynx_stdlib_eventmanager_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'eventManager' must be an instance of 'Lynx\\Stdlib\\EventManager'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("eventManager"), eventManager TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("connection"), connection TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("configuration"), configuration TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, lynx_orm_unitofwork_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, this_ptr);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("unitOfWork"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, lynx_orm_modelsmanager_ce);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, this_ptr);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("modelsManager"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_EntityManager, flush) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);




}

PHP_METHOD(Lynx_ORM_EntityManager, remove) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);

	if (unlikely(Z_TYPE_P(entity) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'entity' must be an object") TSRMLS_CC);
		RETURN_NULL();
	}




}

PHP_METHOD(Lynx_ORM_EntityManager, beginTransaction) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "begintransaction", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_EntityManager, commit) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "commit", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_EntityManager, rollback) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "rollback", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_EntityManager, getRepository) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *entityName_param = NULL, *modelInfo = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *entityName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &entityName_param);

	if (unlikely(Z_TYPE_P(entityName_param) != IS_STRING && Z_TYPE_P(entityName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'entityName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(entityName_param) == IS_STRING)) {
		entityName = entityName_param;
	} else {
		ZEPHIR_INIT_VAR(entityName);
		ZVAL_EMPTY_STRING(entityName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("repositories"), PH_NOISY_CC);
	if (zephir_array_isset(_0, entityName)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("repositories"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, entityName, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&modelInfo, _1, "get", NULL, entityName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, lynx_orm_entityrepository_ce);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, this_ptr, modelInfo);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("repositories"), entityName, _3 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("repositories"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _4, entityName, PH_NOISY | PH_READONLY TSRMLS_CC);
	RETURN_CTOR(_2);

}

PHP_METHOD(Lynx_ORM_EntityManager, createQueryBuilder) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, lynx_orm_querybuilder_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Lynx_ORM_EntityManager, createQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sql;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sql);



	object_init_ex(return_value, lynx_orm_query_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, sql, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

