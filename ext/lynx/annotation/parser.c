
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
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Lynx_Annotation_Parser) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Annotation, Parser, lynx, annotation_parser, lynx_annotation_parser_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Lynx_Annotation_Parser, parseAnnotations) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *docComment, *hasAnnotations = NULL, *matches, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &docComment);

	ZEPHIR_INIT_VAR(matches);
	array_init(matches);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/@(\w+)(?:\s*(?:\(\s*)?(.*?)(?:\s*\))?)??\s*(?:\n|\*\/)/", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&hasAnnotations, "preg_match_all", &_2, _0, docComment, matches, _1);
	zephir_check_temp_parameter(_0);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	if (!zephir_is_true(hasAnnotations)) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

