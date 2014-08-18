
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Lynx_ORM_ModelMetaData) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, ModelMetaData, lynx, orm_modelmetadata, lynx_orm_modelmetadata_method_entry, 0);

	zend_declare_property_null(lynx_orm_modelmetadata_ce, SL("classname"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelmetadata_ce, SL("tablename"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelmetadata_ce, SL("properties"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelmetadata_ce, SL("columns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getClassname) {


	RETURN_MEMBER(this_ptr, "classname");

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getTablename) {


	RETURN_MEMBER(this_ptr, "tablename");

}

PHP_METHOD(Lynx_ORM_ModelMetaData, __construct) {

	HashTable *_3, *_11;
	HashPosition _2, _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *classname, *parser, *result = NULL, *properties = NULL, *column = NULL, *key = NULL, *value = NULL, *_0, *_1, **_4, *_5, *_6, *_7, *_8, *_9, **_12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname);



	zephir_update_property_this(this_ptr, SL("classname"), classname TSRMLS_CC);
	ZEPHIR_INIT_VAR(parser);
	object_init_ex(parser, lynx_annotation_reflectionclassparser_ce);
	ZEPHIR_CALL_METHOD(NULL, parser, "__construct", NULL, classname);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, parser, "getclassannotations",  NULL);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, result, SL("table"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 27 TSRMLS_CC);
	zephir_array_fetch_string(&_1, _0, SL("name"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 27 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("tablename"), _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&properties, parser, "getpropertiesannotations",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(properties, &_3, &_2, 0, 0, "lynx/ORM/ModelMetaData.zep", 51);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		if (zephir_array_isset_string(value, SS("joincolumn"))) {
			ZEPHIR_INIT_NVAR(column);
			object_init_ex(column, lynx_orm_modelmetadata_property_ce);
			if (zephir_has_constructor(column TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, column, "__construct", NULL);
				zephir_check_call_status();
			}
			if (zephir_array_isset_string(value, SS("onetoone"))) {
				ZEPHIR_INIT_ZVAL_NREF(_5);
				ZVAL_LONG(_5, 1);
				zephir_update_property_zval(column, SL("type"), _5 TSRMLS_CC);
				zephir_array_fetch_string(&_6, value, SL("onetoone"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 41 TSRMLS_CC);
				zephir_array_fetch_string(&_7, _6, SL("targetEntity"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 41 TSRMLS_CC);
				zephir_update_property_zval(column, SL("targetEntity"), _7 TSRMLS_CC);
			}
			zephir_array_fetch_string(&_6, value, SL("joincolumn"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 44 TSRMLS_CC);
			zephir_array_fetch_string(&_7, _6, SL("name"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 44 TSRMLS_CC);
			zephir_update_property_zval(column, SL("name"), _7 TSRMLS_CC);
			zephir_array_fetch_string(&_8, value, SL("joincolumn"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 45 TSRMLS_CC);
			zephir_array_fetch_string(&_9, _8, SL("referencedColumnName"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 45 TSRMLS_CC);
			zephir_update_property_zval(column, SL("referencedColumnName"), _9 TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("properties"), key, column TSRMLS_CC);
		}
	}
	zephir_is_iterable(properties, &_11, &_10, 0, 0, "lynx/ORM/ModelMetaData.zep", 72);
	for (
	  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
	  ; zephir_hash_move_forward_ex(_11, &_10)
	) {
		ZEPHIR_GET_HMKEY(key, _11, _10);
		ZEPHIR_GET_HVALUE(value, _12);
		if (zephir_array_isset_string(value, SS("column"))) {
			ZEPHIR_INIT_NVAR(column);
			object_init_ex(column, lynx_orm_modelmetadata_column_ce);
			if (zephir_has_constructor(column TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, column, "__construct", NULL);
				zephir_check_call_status();
			}
			if (zephir_array_isset_string(value, SS("id"))) {
				zephir_update_property_zval(column, SL("id"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
			zephir_array_fetch_string(&_6, value, SL("column"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 59 TSRMLS_CC);
			if (zephir_array_isset_string(_6, SS("type"))) {
				zephir_array_fetch_string(&_7, value, SL("column"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 60 TSRMLS_CC);
				zephir_array_fetch_string(&_8, _7, SL("type"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 60 TSRMLS_CC);
				zephir_update_property_zval(column, SL("type"), _8 TSRMLS_CC);
			}
			zephir_array_fetch_string(&_6, value, SL("column"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 63 TSRMLS_CC);
			if (zephir_array_isset_string(_6, SS("name"))) {
				zephir_array_fetch_string(&_7, value, SL("column"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 64 TSRMLS_CC);
				zephir_array_fetch_string(&_9, _7, SL("name"), PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 64 TSRMLS_CC);
				zephir_update_property_zval(column, SL("name"), _9 TSRMLS_CC);
			} else {
				zephir_update_property_zval(column, SL("name"), key TSRMLS_CC);
			}
			zephir_update_property_array(this_ptr, SL("columns"), key, column TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *tmp, *classname = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("classname"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(classname, _0);
	ZEPHIR_INIT_VAR(tmp);
	_1 = zend_fetch_class(Z_STRVAL_P(classname), Z_STRLEN_P(classname), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(tmp, _1);
	if (zephir_has_constructor(tmp TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, tmp, "__construct", NULL);
		zephir_check_call_status();
	}
	RETURN_CCTOR(tmp);

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getColumns) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("columns"), PH_NOISY_CC);
	if (!Z_TYPE_P(_0) == IS_NULL) {
		RETURN_MEMBER(this_ptr, "columns");
	}
	array_init(return_value);
	return;

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getProperties) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("properties"), PH_NOISY_CC);
	if (!Z_TYPE_P(_0) == IS_NULL) {
		RETURN_MEMBER(this_ptr, "properties");
	}
	array_init(return_value);
	return;

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *columns = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(key_param) == IS_STRING)) {
		key = key_param;
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_CALL_METHOD(&columns, this_ptr, "getcolumns",  NULL);
	zephir_check_call_status();
	if (zephir_array_isset(columns, key)) {
		zephir_array_fetch(&_0, columns, key, PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 108 TSRMLS_CC);
		RETURN_CTOR(_0);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getProperty) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *properties = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(key_param) == IS_STRING)) {
		key = key_param;
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_CALL_METHOD(&properties, this_ptr, "getproperties",  NULL);
	zephir_check_call_status();
	if (zephir_array_isset(properties, key)) {
		zephir_array_fetch(&_0, properties, key, PH_NOISY | PH_READONLY, "lynx/ORM/ModelMetaData.zep", 120 TSRMLS_CC);
		RETURN_CTOR(_0);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getPrimaryKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprimaryfieldname",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcolumn", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getPrimaryFieldName) {


	RETURN_STRING("id", 1);

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getFieldNameByColumn) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field, *properties = NULL, *columnName = NULL, *info = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field);



	ZEPHIR_CALL_METHOD(&properties, this_ptr, "getproperties",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(properties, &_1, &_0, 0, 0, "lynx/ORM/ModelMetaData.zep", 148);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(columnName, _1, _0);
		ZEPHIR_GET_HVALUE(info, _2);
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_property(&_3, info, SL("name"), PH_NOISY_CC);
		if (ZEPHIR_IS_EQUAL(_3, field)) {
			RETURN_CCTOR(columnName);
		}
	}
	RETURN_MM_BOOL(0);

}

