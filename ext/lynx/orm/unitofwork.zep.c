
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/array.h"

ZEPHIR_INIT_CLASS(Lynx_ORM_UnitOfWork) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, UnitOfWork, lynx, orm_unitofwork, lynx_orm_unitofwork_method_entry, 0);

	/**
	 * @var EntityManager
	 */
	zend_declare_property_null(lynx_orm_unitofwork_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_unitofwork_ce, SL("insertEntities"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_unitofwork_ce, SL("updateEntities"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_unitofwork_ce, SL("deleteEntities"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_unitofwork_ce, SL("STATE_MANAGED"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_unitofwork_ce, SL("STATE_NEW"), 2 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_UnitOfWork, __construct) {

	zval *em, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &em);



	if (!(zephir_instance_of_ev(em, lynx_orm_entitymanager_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'em' must be an instance of 'Lynx\\ORM\\EntityManager'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("insertEntities"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("updateEntities"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("deleteEntities"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_UnitOfWork, insert) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);

	if (unlikely(Z_TYPE_P(entity) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'entity' must be an object") TSRMLS_CC);
		RETURN_NULL();
	}



	zephir_update_property_array_append(this_ptr, SL("insertEntities"), entity TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_UnitOfWork, update) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);

	if (unlikely(Z_TYPE_P(entity) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'entity' must be an object") TSRMLS_CC);
		RETURN_NULL();
	}



	zephir_update_property_array_append(this_ptr, SL("updateEntities"), entity TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_UnitOfWork, delete) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);

	if (unlikely(Z_TYPE_P(entity) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'entity' must be an object") TSRMLS_CC);
		RETURN_NULL();
	}



	zephir_update_property_array_append(this_ptr, SL("deleteEntities"), entity TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_UnitOfWork, commit) {

	zephir_fcall_cache_entry *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_13, *_18;
	HashPosition _1, _12, _17;
	zval *entity = NULL, *model = NULL, *modelInfo = NULL, *_0, **_3, *_4, *_5 = NULL, *_6 = NULL, *_7, *_8 = NULL, *_9 = NULL, *_10 = NULL, **_14, *data = NULL, *identifiers = NULL, *_15 = NULL, *_16, **_19, *_20, *_21;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &entity);

	if (!entity) {
		entity = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("insertEntities"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(model, _3);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _4, "getmodelsmanager",  NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		zephir_get_class(_6, model, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&modelInfo, _5, "get", NULL, _6);
		zephir_check_call_status();
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_8, _7, "getconnection",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_9, modelInfo, "gettablename",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_10, lynx_stdlib_hydrator_classproperties_ce, "extract", &_11, model);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _8, "insert", NULL, _9, _10);
		zephir_check_call_status();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("updateEntities"), PH_NOISY_CC);
	zephir_is_iterable(_4, &_13, &_12, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
	  ; zephir_hash_move_forward_ex(_13, &_12)
	) {
		ZEPHIR_GET_HVALUE(model, _14);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _7, "getmodelsmanager",  NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		zephir_get_class(_6, model, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&modelInfo, _5, "get", NULL, _6);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&data, lynx_stdlib_hydrator_classproperties_ce, "extract", &_11, model);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(identifiers);
		array_init_size(identifiers, 2);
		ZEPHIR_OBS_NVAR(_15);
		zephir_array_fetch_string(&_15, data, SL("id"), PH_NOISY TSRMLS_CC);
		zephir_array_update_string(&identifiers, SL("id"), &_15, PH_COPY | PH_SEPARATE);
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_8, _16, "getconnection",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_9, modelInfo, "gettablename",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _8, "update", NULL, _9, data, identifiers);
		zephir_check_call_status();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("deleteEntities"), PH_NOISY_CC);
	zephir_is_iterable(_4, &_18, &_17, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS
	  ; zephir_hash_move_forward_ex(_18, &_17)
	) {
		ZEPHIR_GET_HVALUE(model, _19);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _7, "getmodelsmanager",  NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		zephir_get_class(_6, model, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&modelInfo, _5, "get", NULL, _6);
		zephir_check_call_status();
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_8, _16, "getconnection",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_9, modelInfo, "gettablename",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_10, lynx_stdlib_hydrator_classproperties_ce, "extract", &_11, model);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _8, "delete", NULL, _9, _10);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_6);
	array_init(_6);
	zephir_update_property_this(this_ptr, SL("insertEntities"), _6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_20);
	array_init(_20);
	zephir_update_property_this(this_ptr, SL("updateEntities"), _20 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_21);
	array_init(_21);
	zephir_update_property_this(this_ptr, SL("deleteEntities"), _21 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

