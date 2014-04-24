
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


ZEPHIR_INIT_CLASS(Lynx_ORM_ModelMetaData) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, ModelMetaData, lynx, orm_modelmetadata, lynx_orm_modelmetadata_method_entry, 0);

	zend_declare_property_null(lynx_orm_modelmetadata_ce, SL("classname"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelmetadata_ce, SL("tablename"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *classname, *parser, *result = NULL, *_0, *_1;

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
	ZEPHIR_MM_RESTORE();

}

