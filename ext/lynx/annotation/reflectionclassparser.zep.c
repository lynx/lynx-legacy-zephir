
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
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_Annotation_ReflectionClassParser) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Annotation, ReflectionClassParser, lynx, annotation_reflectionclassparser, lynx_annotation_reflectionclassparser_method_entry, 0);

	/**
	 * @var \ReflectionClass
	 */
	zend_declare_property_null(lynx_annotation_reflectionclassparser_ce, SL("reflectionClass"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_Annotation_ReflectionClassParser, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *parameter, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameter);



	_0 = Z_TYPE_P(parameter) == IS_STRING;
	if (!(_0)) {
		_0 = Z_TYPE_P(parameter) == IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, parameter);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("reflectionClass"), _1 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "$parameter must be class name (string) or object instance (object)", "lynx/Annotation/ReflectionClassParser.zep", 19);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_Annotation_ReflectionClassParser, getClassAnnotations) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *docComment = NULL, *result = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("reflectionClass"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&docComment, _0, "getdoccomment", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&result, lynx_annotation_regexdocparser_ce, "parseannotations", &_1, docComment);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

PHP_METHOD(Lynx_Annotation_ReflectionClassParser, getPropertiesAnnotations) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *properties = NULL, *property = NULL, *result, *_0, **_3, *_4 = NULL, *_6 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(result);
	array_init(result);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("reflectionClass"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&properties, _0, "getproperties", NULL);
	zephir_check_call_status();
	zephir_is_iterable(properties, &_2, &_1, 0, 0, "lynx/Annotation/ReflectionClassParser.zep", 41);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(property, _3);
		ZEPHIR_CALL_METHOD(&_6, property, "getdoccomment", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_4, lynx_annotation_regexdocparser_ce, "parseannotations", &_5, _6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7, property, "getname", NULL);
		zephir_check_call_status();
		zephir_array_update_zval(&result, _7, &_4, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(result);

}

