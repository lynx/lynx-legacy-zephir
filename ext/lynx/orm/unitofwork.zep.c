
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"

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
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("deleteEntities"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("updateEntities"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("insertEntities"), _2 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);
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

PHP_METHOD(Lynx_ORM_UnitOfWork, convertToScalar) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *columnType = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &columnType);

	if (!columnType) {
		columnType = ZEPHIR_GLOBAL(global_null);
	}


	do {
		if (ZEPHIR_IS_STRING(columnType, "date")) {
			if (zephir_instance_of_ev(value, lynx_dbal_rawvalue_ce TSRMLS_CC)) {
				ZEPHIR_RETURN_CALL_METHOD(value, "getvalue", NULL);
				zephir_check_call_status();
				RETURN_MM();
			}
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
			break;
		}
		if (ZEPHIR_IS_STRING(columnType, "datetime")) {
			if (zephir_instance_of_ev(value, zephir_get_internal_ce(SS("datetime") TSRMLS_CC) TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_0);
				ZVAL_STRING(_0, "Y-m-d H:i:s", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_RETURN_CALL_METHOD(value, "format", NULL, _0);
				zephir_check_temp_parameter(_0);
				zephir_check_call_status();
				RETURN_MM();
			}
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
			break;
		}
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
		break;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_UnitOfWork, commit) {

	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL, *_15 = NULL, *_27 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_9, *_25, *_29;
	HashPosition _1, _8, _24, _28;
	zval *entity = NULL, *model = NULL, *modelInfo = NULL, *result = NULL, *primaryField = NULL, *_0, **_3, *lastInsertId = NULL, *extractValues = NULL, *insertValues = NULL, *property = NULL, *value = NULL, *key = NULL, *types, *_4, *_5 = NULL, *_6 = NULL, **_10, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_16 = NULL, *_17, *_18 = NULL, *_19, *_20 = NULL, *_21 = NULL, *_22 = NULL, *_23 = NULL, **_26, *data = NULL, *identifiers = NULL, **_30, *_31, *_32;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &entity);

	if (!entity) {
		entity = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(types);
	array_init(types);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("insertEntities"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "lynx/ORM/UnitOfWork.zep", 113);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(model, _3);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _4, "getmodelsmanager", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		zephir_get_class(_6, model, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&modelInfo, _5, "get", NULL, _6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&primaryField, modelInfo, "getprimaryfieldname", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&extractValues, lynx_stdlib_hydrator_entity_ce, "extract", &_7, model, modelInfo);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(insertValues);
		array_init(insertValues);
		zephir_is_iterable(extractValues, &_9, &_8, 0, 0, "lynx/ORM/UnitOfWork.zep", 101);
		for (
		  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
		  ; zephir_hash_move_forward_ex(_9, &_8)
		) {
			ZEPHIR_GET_HMKEY(key, _9, _8);
			ZEPHIR_GET_HVALUE(value, _10);
			if (ZEPHIR_IS_EQUAL(key, primaryField)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&property, modelInfo, "getcolumn", &_11, key);
			zephir_check_call_status();
			if (!zephir_is_true(property)) {
				continue;
			}
			if (zephir_instance_of_ev(value, lynx_dbal_rawvalue_ce TSRMLS_CC)) {
				ZEPHIR_OBS_NVAR(_12);
				zephir_read_property(&_12, property, SL("name"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_LONG(_13, 10);
				zephir_array_update_zval(&types, _12, &_13, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_OBS_NVAR(_12);
			zephir_read_property(&_12, property, SL("type"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_14, this_ptr, "converttoscalar", &_15, value, _12);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(_16);
			zephir_read_property(&_16, property, SL("name"), PH_NOISY_CC);
			zephir_array_update_zval(&insertValues, _16, &_14, PH_COPY | PH_SEPARATE);
		}
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_14, _17, "getconnection", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_18, modelInfo, "gettablename", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&result, _14, "insert", NULL, _18, insertValues, types);
		zephir_check_call_status();
		if (zephir_is_true(result)) {
			_19 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_20, _19, "getconnection", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21, _20, "getdriver", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_22, modelInfo, "gettablename", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_23);
			ZEPHIR_CONCAT_VS(_23, _22, "_id_seq");
			ZEPHIR_CALL_METHOD(&lastInsertId, _21, "lastinsertid", NULL, _23);
			zephir_check_call_status();
			if (zephir_is_true(primaryField)) {
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_LONG(_13, zephir_get_intval(lastInsertId));
				zephir_update_property_zval(model, Z_STRVAL_P(primaryField), Z_STRLEN_P(primaryField), _13 TSRMLS_CC);
			}
		}
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("updateEntities"), PH_NOISY_CC);
	zephir_is_iterable(_4, &_25, &_24, 0, 0, "lynx/ORM/UnitOfWork.zep", 132);
	for (
	  ; zephir_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
	  ; zephir_hash_move_forward_ex(_25, &_24)
	) {
		ZEPHIR_GET_HVALUE(model, _26);
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _17, "getmodelsmanager", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		zephir_get_class(_6, model, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&modelInfo, _5, "get", NULL, _6);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&data, lynx_stdlib_hydrator_classproperties_ce, "extract", &_27, model);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&primaryField, modelInfo, "getprimaryfieldname", NULL);
		zephir_check_call_status();
		if (zephir_is_true(primaryField)) {
			ZEPHIR_INIT_NVAR(identifiers);
			array_init_size(identifiers, 2);
			ZEPHIR_OBS_NVAR(_12);
			zephir_array_fetch(&_12, data, primaryField, PH_NOISY, "lynx/ORM/UnitOfWork.zep", 124 TSRMLS_CC);
			zephir_array_update_zval(&identifiers, primaryField, &_12, PH_COPY);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Entity`s PrimaryField is not set.", "lynx/ORM/UnitOfWork.zep", 126);
			return;
		}
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_14, _19, "getconnection", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_18, modelInfo, "gettablename", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _14, "update", NULL, _18, data, identifiers);
		zephir_check_call_status();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("deleteEntities"), PH_NOISY_CC);
	zephir_is_iterable(_4, &_29, &_28, 0, 0, "lynx/ORM/UnitOfWork.zep", 144);
	for (
	  ; zephir_hash_get_current_data_ex(_29, (void**) &_30, &_28) == SUCCESS
	  ; zephir_hash_move_forward_ex(_29, &_28)
	) {
		ZEPHIR_GET_HVALUE(model, _30);
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _17, "getmodelsmanager", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		zephir_get_class(_6, model, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&modelInfo, _5, "get", NULL, _6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&primaryField, modelInfo, "getprimaryfieldname", NULL);
		zephir_check_call_status();
		if (zephir_is_true(primaryField)) {
			_31 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_18, _31, "getconnection", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_20, modelInfo, "gettablename", NULL);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(_12);
			zephir_read_property_zval(&_12, model, primaryField, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _18, "deletebycolumn", NULL, _20, primaryField, _12);
			zephir_check_call_status();
		} else {
			_19 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_14, _19, "getconnection", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_20, modelInfo, "gettablename", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_CE_STATIC(&_21, lynx_stdlib_hydrator_entity_ce, "extract", &_7, model);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _14, "delete", NULL, _20, _21);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(_6);
	array_init(_6);
	zephir_update_property_this(this_ptr, SL("insertEntities"), _6 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_13);
	array_init(_13);
	zephir_update_property_this(this_ptr, SL("updateEntities"), _13 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_32);
	array_init(_32);
	zephir_update_property_this(this_ptr, SL("deleteEntities"), _32 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

