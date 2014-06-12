
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Lynx_ORM_ModelMetaData) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, ModelMetaData, lynx, orm_modelmetadata, lynx_orm_modelmetadata_method_entry, 0);

	zend_declare_property_null(lynx_orm_modelmetadata_ce, SL("classname"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelmetadata_ce, SL("tablename"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelmetadata_ce, SL("properties"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getClassname) {


	RETURN_MEMBER(this_ptr, "classname");

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getTablename) {


	RETURN_MEMBER(this_ptr, "tablename");

}

PHP_METHOD(Lynx_ORM_ModelMetaData, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *classname, *parser, *result = NULL, *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname);



	zephir_update_property_this(this_ptr, SL("classname"), classname TSRMLS_CC);
	ZEPHIR_INIT_VAR(parser);
	object_init_ex(parser, lynx_annotation_reflectionclassparser_ce);
	ZEPHIR_CALL_METHOD(NULL, parser, "__construct", NULL, classname);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, parser, "getclassannotations",  NULL);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, result, SL("table"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_1, _0, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("tablename"), _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, parser, "getpropertiesannotations",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("properties"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

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
	zephir_array_fetch(&_0, properties, key, PH_NOISY | PH_READONLY TSRMLS_CC);
	RETURN_CTOR(_0);

}

PHP_METHOD(Lynx_ORM_ModelMetaData, getPrimaryKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "id", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getproperty", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

