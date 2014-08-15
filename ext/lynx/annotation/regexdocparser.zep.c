
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


ZEPHIR_INIT_CLASS(Lynx_Annotation_RegexDocParser) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Annotation, RegexDocParser, lynx, annotation_regexdocparser, lynx_annotation_regexdocparser_method_entry, 0);

	return SUCCESS;

}

/**
 * @return array
 */
PHP_METHOD(Lynx_Annotation_RegexDocParser, parseAnnotations) {

	zval *_14 = NULL;
	HashTable *_3, *_8;
	HashPosition _2, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_11 = NULL;
	zval *docComment, *hasAnnotations = NULL, *matches, *anno = NULL, *annoName = NULL, *val = NULL, *hasParams = NULL, *params, *param = NULL, *rex, *_0 = NULL, *annotations, **_4, *_5, *regex1, *_6, **_9, *_10 = NULL, *_12, *_13 = NULL;

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
	zephir_is_iterable(matches, &_3, &_2, 0, 0, "lynx/Annotation/RegexDocParser.zep", 64);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(anno, _4);
		ZEPHIR_INIT_NVAR(annoName);
		zephir_array_fetch_long(&_5, anno, 1, PH_NOISY | PH_READONLY, "lynx/Annotation/RegexDocParser.zep", 30 TSRMLS_CC);
		zephir_fast_strtolower(annoName, _5);
		ZEPHIR_INIT_NVAR(val);
		ZVAL_BOOL(val, 1);
		if (zephir_array_isset_long(anno, 2)) {
			zephir_array_fetch_long(&_6, anno, 2, PH_NOISY | PH_READONLY, "lynx/Annotation/RegexDocParser.zep", 35 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, 2);
			Z_SET_ISREF_P(params);
			ZEPHIR_CALL_FUNCTION(&hasParams, "preg_match_all", &_1, regex1, _6, params, _0);
			Z_UNSET_ISREF_P(params);
			zephir_check_call_status();
			if (zephir_is_true(hasParams)) {
				ZEPHIR_INIT_NVAR(val);
				array_init(val);
				zephir_is_iterable(params, &_8, &_7, 0, 0, "lynx/Annotation/RegexDocParser.zep", 43);
				for (
				  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
				  ; zephir_hash_move_forward_ex(_8, &_7)
				) {
					ZEPHIR_GET_HVALUE(param, _9);
					zephir_array_fetch_long(&_12, param, 2, PH_NOISY | PH_READONLY, "lynx/Annotation/RegexDocParser.zep", 40 TSRMLS_CC);
					ZEPHIR_CALL_SELF(&_10, "parsevalue", &_11, _12);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(_13);
					zephir_array_fetch_long(&_13, param, 1, PH_NOISY, "lynx/Annotation/RegexDocParser.zep", 40 TSRMLS_CC);
					zephir_array_update_zval(&val, _13, &_10, PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_INIT_NVAR(val);
				zephir_array_fetch_long(&_12, anno, 2, PH_NOISY | PH_READONLY, "lynx/Annotation/RegexDocParser.zep", 44 TSRMLS_CC);
				zephir_fast_trim(val, _12, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
				if (ZEPHIR_IS_STRING(val, "")) {
					ZEPHIR_INIT_NVAR(val);
					ZVAL_BOOL(val, 1);
				} else {
					ZEPHIR_CALL_SELF(&_10, "parsevalue", &_11, val);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(val, _10);
				}
			}
		}
		if (zephir_array_isset(annotations, annoName)) {
			zephir_array_fetch(&_6, annotations, annoName, PH_NOISY | PH_READONLY, "lynx/Annotation/RegexDocParser.zep", 55 TSRMLS_CC);
			if (!Z_TYPE_P(_6) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_14);
				array_init_size(_14, 2);
				ZEPHIR_OBS_NVAR(_13);
				zephir_array_fetch(&_13, annotations, annoName, PH_NOISY, "lynx/Annotation/RegexDocParser.zep", 56 TSRMLS_CC);
				zephir_array_fast_append(_14, _13);
				zephir_array_update_zval(&annotations, annoName, &_14, PH_COPY | PH_SEPARATE);
			}
			zephir_array_update_multi(&annotations, &val TSRMLS_CC, SL("za"), 2, annoName);
		} else {
			zephir_array_update_zval(&annotations, annoName, &val, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(annotations);

}

/**
 * @return mixed
 */
PHP_METHOD(Lynx_Annotation_RegexDocParser, parseValue) {

	HashTable *_8;
	HashPosition _7;
	zend_bool _4, _13, _14;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_11 = NULL;
	zval *value, *val = NULL, *vals, *v = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2 = NULL, *_5 = NULL, *_6 = NULL, **_9, *_10 = NULL, _12 = zval_used_for_init, *_15 = NULL, *_16 = NULL, *_17, *_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_INIT_VAR(val);
	zephir_fast_trim(val, value, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_2, "substr", &_3, val, &_0, &_1);
	zephir_check_call_status();
	_4 = ZEPHIR_IS_STRING(_2, "[");
	if (_4) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, -1);
		ZEPHIR_CALL_FUNCTION(&_5, "substr", &_3, val, &_0);
		zephir_check_call_status();
		_4 = ZEPHIR_IS_STRING(_5, "]");
	}
	if (_4) {
		ZEPHIR_INIT_VAR(vals);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 1);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, -1);
		ZEPHIR_CALL_FUNCTION(&_6, "substr", &_3, val, &_0, &_1);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, ',');
		zephir_fast_explode(vals, &_0, _6, LONG_MAX TSRMLS_CC);
		ZEPHIR_INIT_BNVAR(val);
		array_init(val);
		zephir_is_iterable(vals, &_8, &_7, 0, 0, "lynx/Annotation/RegexDocParser.zep", 86);
		for (
		  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HVALUE(v, _9);
			ZEPHIR_CALL_SELF(&_10, "parsevalue", &_11, v);
			zephir_check_call_status();
			zephir_array_append(&val, _10, PH_SEPARATE, "lynx/Annotation/RegexDocParser.zep", 83);
		}
		RETURN_CCTOR(val);
	} else {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_VAR(_12);
		ZVAL_LONG(&_12, 1);
		ZEPHIR_CALL_FUNCTION(&_6, "substr", &_3, val, &_1, &_12);
		zephir_check_call_status();
		_13 = ZEPHIR_IS_STRING(_6, "{");
		if (_13) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, -1);
			ZEPHIR_CALL_FUNCTION(&_10, "substr", &_3, val, &_1);
			zephir_check_call_status();
			_13 = ZEPHIR_IS_STRING(_10, "}");
		}
		if (_13) {
			zephir_json_decode(return_value, &(return_value), val, 0  TSRMLS_CC);
			RETURN_MM();
		} else {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 0);
			ZEPHIR_SINIT_NVAR(_12);
			ZVAL_LONG(&_12, 1);
			ZEPHIR_CALL_FUNCTION(&_10, "substr", &_3, val, &_1, &_12);
			zephir_check_call_status();
			_14 = ZEPHIR_IS_STRING(_10, "\"");
			if (_14) {
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, -1);
				ZEPHIR_CALL_FUNCTION(&_15, "substr", &_3, val, &_1);
				zephir_check_call_status();
				_14 = ZEPHIR_IS_STRING(_15, "\"");
			}
			if (_14) {
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, 1);
				ZEPHIR_SINIT_NVAR(_12);
				ZVAL_LONG(&_12, -1);
				ZEPHIR_CALL_FUNCTION(&_16, "substr", &_3, val, &_1, &_12);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(val, _16);
				ZEPHIR_RETURN_CALL_SELF("parsevalue", &_11, val);
				zephir_check_call_status();
				RETURN_MM();
			} else {
				ZEPHIR_INIT_VAR(_17);
				zephir_fast_strtolower(_17, val);
				if (ZEPHIR_IS_STRING(_17, "true")) {
					RETURN_MM_BOOL(1);
				} else {
					ZEPHIR_INIT_VAR(_18);
					zephir_fast_strtolower(_18, val);
					if (ZEPHIR_IS_STRING(_18, "false")) {
						RETURN_MM_BOOL(0);
					} else {
						if (zephir_is_numeric(val)) {
							if (zephir_get_doubleval(val) == zephir_get_intval(val)) {
								RETURN_MM_LONG(zephir_get_intval(val));
							} else {
								RETURN_MM_DOUBLE(zephir_get_doubleval(val));
							}
						}
					}
				}
			}
		}
	}
	RETURN_CCTOR(val);

}

