
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
	zend_bool _0;
	zval *value, *columnType = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &columnType);

	if (!columnType) {
		columnType = ZEPHIR_GLOBAL(global_null);
	}


	do {
		if (ZEPHIR_IS_STRING(columnType, "date")) {
			_0 = Z_TYPE_P(value) == IS_OBJECT;
			if (_0) {
				_0 = zephir_instance_of_ev(value, lynx_dbal_rawvalue_ce TSRMLS_CC);
			}
			if (_0) {
				ZEPHIR_RETURN_CALL_METHOD(value, "getvalue", NULL);
				zephir_check_call_status();
				RETURN_MM();
			}
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
			break;
		}
		if (ZEPHIR_IS_STRING(columnType, "datetime")) {
			_0 = Z_TYPE_P(value) == IS_OBJECT;
			if (_0) {
				_0 = zephir_instance_of_ev(value, zephir_get_internal_ce(SS("datetime") TSRMLS_CC) TSRMLS_CC);
			}
			if (_0) {
				ZEPHIR_INIT_VAR(_1);
				ZVAL_STRING(_1, "Y-m-d H:i:s", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_RETURN_CALL_METHOD(value, "format", NULL, _1);
				zephir_check_temp_parameter(_1);
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

	zend_bool _12;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL, *_16 = NULL, *_28 = NULL, *_32 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_9, *_26, *_30, *_34;
	HashPosition _1, _8, _25, _29, _33;
	zval *entity = NULL, *model = NULL, *modelInfo = NULL, *result = NULL, *primaryField = NULL, *extractValues = NULL, *_0, **_3, *lastInsertId = NULL, *insertValues = NULL, *property = NULL, *value = NULL, *key = NULL, *types, *_4, *_5 = NULL, *_6 = NULL, **_10, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_17 = NULL, *_18, *_19 = NULL, *_20, *_21 = NULL, *_22 = NULL, *_23 = NULL, *_24 = NULL, **_27, *identifiers = NULL, *updateValues, **_31, **_35, *_36, *_37;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &entity);

	if (!entity) {
		entity = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(types);
	array_init(types);
	ZEPHIR_INIT_VAR(updateValues);
	array_init(updateValues);


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
			_12 = Z_TYPE_P(value) == IS_OBJECT;
			if (_12) {
				_12 = zephir_instance_of_ev(value, lynx_dbal_rawvalue_ce TSRMLS_CC);
			}
			if (_12) {
				ZEPHIR_OBS_NVAR(_13);
				zephir_read_property(&_13, property, SL("name"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_14);
				ZVAL_LONG(_14, 10);
				zephir_array_update_zval(&types, _13, &_14, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_OBS_NVAR(_13);
			zephir_read_property(&_13, property, SL("type"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_15, this_ptr, "converttoscalar", &_16, value, _13);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(_17);
			zephir_read_property(&_17, property, SL("name"), PH_NOISY_CC);
			zephir_array_update_zval(&insertValues, _17, &_15, PH_COPY | PH_SEPARATE);
		}
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_15, _18, "getconnection", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_19, modelInfo, "gettablename", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&result, _15, "insert", NULL, _19, insertValues, types);
		zephir_check_call_status();
		if (zephir_is_true(result)) {
			_20 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_21, _20, "getconnection", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_22, _21, "getdriver", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_23, modelInfo, "gettablename", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_24);
			ZEPHIR_CONCAT_VS(_24, _23, "_id_seq");
			ZEPHIR_CALL_METHOD(&lastInsertId, _22, "lastinsertid", NULL, _24);
			zephir_check_call_status();
			if (zephir_is_true(primaryField)) {
				ZEPHIR_INIT_NVAR(_14);
				ZVAL_LONG(_14, zephir_get_intval(lastInsertId));
				zephir_update_property_zval(model, Z_STRVAL_P(primaryField), Z_STRLEN_P(primaryField), _14 TSRMLS_CC);
			}
		}
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("updateEntities"), PH_NOISY_CC);
	zephir_is_iterable(_4, &_26, &_25, 0, 0, "lynx/ORM/UnitOfWork.zep", 145);
	for (
	  ; zephir_hash_get_current_data_ex(_26, (void**) &_27, &_25) == SUCCESS
	  ; zephir_hash_move_forward_ex(_26, &_25)
	) {
		ZEPHIR_GET_HVALUE(model, _27);
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _18, "getmodelsmanager", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		zephir_get_class(_6, model, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&modelInfo, _5, "get", NULL, _6);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&extractValues, lynx_stdlib_hydrator_classproperties_ce, "extract", &_28, model);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&primaryField, modelInfo, "getprimaryfieldname", NULL);
		zephir_check_call_status();
		if (zephir_is_true(primaryField)) {
			ZEPHIR_INIT_NVAR(identifiers);
			array_init_size(identifiers, 2);
			ZEPHIR_OBS_NVAR(_13);
			zephir_array_fetch(&_13, extractValues, primaryField, PH_NOISY, "lynx/ORM/UnitOfWork.zep", 124 TSRMLS_CC);
			zephir_array_update_zval(&identifiers, primaryField, &_13, PH_COPY);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Entity`s PrimaryField is not set.", "lynx/ORM/UnitOfWork.zep", 126);
			return;
		}
		zephir_is_iterable(extractValues, &_30, &_29, 0, 0, "lynx/ORM/UnitOfWork.zep", 142);
		for (
		  ; zephir_hash_get_current_data_ex(_30, (void**) &_31, &_29) == SUCCESS
		  ; zephir_hash_move_forward_ex(_30, &_29)
		) {
			ZEPHIR_GET_HMKEY(key, _30, _29);
			ZEPHIR_GET_HVALUE(value, _31);
			if (ZEPHIR_IS_EQUAL(key, primaryField)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&property, modelInfo, "getcolumn", &_32, key);
			zephir_check_call_status();
			if (!zephir_is_true(property)) {
				continue;
			}
			ZEPHIR_OBS_NVAR(_13);
			zephir_read_property(&_13, property, SL("type"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_15, this_ptr, "converttoscalar", &_16, value, _13);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(_17);
			zephir_read_property(&_17, property, SL("name"), PH_NOISY_CC);
			zephir_array_update_zval(&updateValues, _17, &_15, PH_COPY | PH_SEPARATE);
		}
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_15, _20, "getconnection", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_19, modelInfo, "gettablename", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _15, "update", NULL, _19, updateValues, identifiers);
		zephir_check_call_status();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("deleteEntities"), PH_NOISY_CC);
	zephir_is_iterable(_4, &_34, &_33, 0, 0, "lynx/ORM/UnitOfWork.zep", 157);
	for (
	  ; zephir_hash_get_current_data_ex(_34, (void**) &_35, &_33) == SUCCESS
	  ; zephir_hash_move_forward_ex(_34, &_33)
	) {
		ZEPHIR_GET_HVALUE(model, _35);
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _18, "getmodelsmanager", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		zephir_get_class(_6, model, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&modelInfo, _5, "get", NULL, _6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&primaryField, modelInfo, "getprimaryfieldname", NULL);
		zephir_check_call_status();
		if (zephir_is_true(primaryField)) {
			_36 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_19, _36, "getconnection", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21, modelInfo, "gettablename", NULL);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(_17);
			zephir_read_property_zval(&_17, model, primaryField, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _19, "deletebycolumn", NULL, _21, primaryField, _17);
			zephir_check_call_status();
		} else {
			_20 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_15, _20, "getconnection", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21, modelInfo, "gettablename", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_CE_STATIC(&_22, lynx_stdlib_hydrator_entity_ce, "extract", &_7, model);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _15, "delete", NULL, _21, _22);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(_6);
	array_init(_6);
	zephir_update_property_this(this_ptr, SL("insertEntities"), _6 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_14);
	array_init(_14);
	zephir_update_property_this(this_ptr, SL("updateEntities"), _14 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_37);
	array_init(_37);
	zephir_update_property_this(this_ptr, SL("deleteEntities"), _37 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

