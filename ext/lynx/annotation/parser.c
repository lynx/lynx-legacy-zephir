
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
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Lynx_Annotation_Parser) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Annotation, Parser, lynx, annotation_parser, lynx_annotation_parser_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Lynx_Annotation_Parser, parseAnnotations) {

	zval *_12 = NULL;
	HashTable *_3, *_8;
	HashPosition _2, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *docComment, *hasAnnotations = NULL, *matches, *anno = NULL, *annoName = NULL, *val = NULL, *hasParams = NULL, *params, *param = NULL, *rex, *_0 = NULL, *annotations, **_4, *_5, *regex1, *_6, **_9, *_10, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &docComment);

	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	ZEPHIR_INIT_VAR(rex);
	ZVAL_STRING(rex, "/@(\\w+)(?:\\s*(?:\\(\\s*)?(.*?)(?:\\s*\\))?)??\\s*(?:\\n|\\*\\/)/", 1);
	ZEPHIR_INIT_VAR(annotations);
	array_init(annotations);
	ZEPHIR_INIT_VAR(regex1);
	ZVAL_STRING(regex1, "/(\\w+)\\s*=\\s*(\\[[^\\]]*\\]|\"[^\"]*\"|[^,)]*)\\s*(?:,|$)/", 1);


	ZEPHIR_INIT_VAR(val);
	ZVAL_BOOL(val, 1);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&hasAnnotations, "preg_match_all", &_1, rex, docComment, matches, _0);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	if (!zephir_is_true(hasAnnotations)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_is_iterable(matches, &_3, &_2, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(anno, _4);
		ZEPHIR_INIT_NVAR(annoName);
		zephir_array_fetch_long(&_5, anno, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_fast_strtolower(annoName, _5);
		ZEPHIR_INIT_NVAR(val);
		ZVAL_BOOL(val, 1);
		if (zephir_array_isset_long(anno, 2)) {
			zephir_array_fetch_long(&_6, anno, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, 2);
			Z_SET_ISREF_P(params);
			ZEPHIR_CALL_FUNCTION(&hasParams, "preg_match_all", &_1, regex1, _6, params, _0);
			Z_UNSET_ISREF_P(params);
			zephir_check_call_status();
			if (zephir_is_true(hasParams)) {
				ZEPHIR_INIT_NVAR(val);
				array_init(val);
				zephir_is_iterable(params, &_8, &_7, 0, 0);
				for (
				  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
				  ; zephir_hash_move_forward_ex(_8, &_7)
				) {
					ZEPHIR_GET_HVALUE(param, _9);
					zephir_array_fetch_long(&_10, param, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_OBS_NVAR(_11);
					zephir_array_fetch_long(&_11, param, 1, PH_NOISY TSRMLS_CC);
					zephir_array_update_zval(&val, _11, &_10, PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_INIT_NVAR(val);
				zephir_array_fetch_long(&_10, anno, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_fast_trim(val, _10, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
				if (ZEPHIR_IS_STRING(val, "")) {
					ZEPHIR_INIT_NVAR(val);
					ZVAL_BOOL(val, 1);
				} else {
				}
			}
		}
		if (zephir_array_isset(annotations, annoName)) {
			zephir_array_fetch(&_6, annotations, annoName, PH_NOISY | PH_READONLY TSRMLS_CC);
			if (!Z_TYPE_P(_6) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_12);
				array_init_size(_12, 2);
				ZEPHIR_OBS_NVAR(_11);
				zephir_array_fetch(&_11, annotations, annoName, PH_NOISY TSRMLS_CC);
				zephir_array_fast_append(_12, _11);
				zephir_array_update_zval(&annotations, annoName, &_12, PH_COPY | PH_SEPARATE);
			}
			zephir_array_update_multi(&annotations, &val TSRMLS_CC, SL("za"), 2, annoName);
		} else {
			zephir_array_update_zval(&annotations, annoName, &val, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(annotations);

}

