
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Lynx_Annotation_ReflectionClassParser) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Annotation, ReflectionClassParser, lynx, annotation_reflectionclassparser, lynx_annotation_reflectionclassparser_method_entry, 0);

	zend_declare_property_null(lynx_annotation_reflectionclassparser_ce, SL("reflectionClass"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_Annotation_ReflectionClassParser, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *parameter, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameter);



	if (Z_TYPE_P(parameter) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_0, _1);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, parameter);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("reflectionClass"), _0 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_Annotation_ReflectionClassParser, getClassAnnotations) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *docComment = NULL, *result = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("reflectionClass"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&docComment, _0, "getdoccomment",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&result, lynx_annotation_parser_ce, "parseannotations", &_1, docComment);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

