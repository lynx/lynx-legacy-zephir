
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


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_Annotation_RegexDocParser) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Annotation, RegexDocParser, lynx, annotation_regexdocparser, lynx_annotation_regexdocparser_method_entry, ZEND_ACC_FINAL_CLASS);

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
	ZVAL_STRING(rex, "/@(\\w+)(?:\\s*(?:\\(\\s*)?(.*?)(?:\\s*\\))?)??\\s*(?:\n|\\*\\/)/", 1);
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
	zephir_is_iterable(matches, &_3, &_2, 0, 0, "lynx/Annotation/RegexDocParser.zep", 67);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(anno, _4);
		ZEPHIR_INIT_NVAR(annoName);
		zephir_array_fetch_long(&_5, anno, 1, PH_NOISY | PH_READONLY, "lynx/Annotation/RegexDocParser.zep", 33 TSRMLS_CC);
		zephir_fast_strtolower(annoName, _5);
		ZEPHIR_INIT_NVAR(val);
		ZVAL_BOOL(val, 1);
		if (zephir_array_isset_long(anno, 2)) {
			zephir_array_fetch_long(&_6, anno, 2, PH_NOISY | PH_READONLY, "lynx/Annotation/RegexDocParser.zep", 38 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, 2);
			Z_SET_ISREF_P(params);
			ZEPHIR_CALL_FUNCTION(&hasParams, "preg_match_all", &_1, regex1, _6, params, _0);
			Z_UNSET_ISREF_P(params);
			zephir_check_call_status();
			if (zephir_is_true(hasParams)) {
				ZEPHIR_INIT_NVAR(val);
				array_init(val);
				zephir_is_iterable(params, &_8, &_7, 0, 0, "lynx/Annotation/RegexDocParser.zep", 46);
				for (
				  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
				  ; zephir_hash_move_forward_ex(_8, &_7)
				) {
					ZEPHIR_GET_HVALUE(param, _9);
					zephir_array_fetch_long(&_12, param, 2, PH_NOISY | PH_READONLY, "lynx/Annotation/RegexDocParser.zep", 43 TSRMLS_CC);
					ZEPHIR_CALL_SELF(&_10, "parsevalue", &_11, _12);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(_13);
					zephir_array_fetch_long(&_13, param, 1, PH_NOISY, "lynx/Annotation/RegexDocParser.zep", 43 TSRMLS_CC);
					zephir_array_update_zval(&val, _13, &_10, PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_INIT_NVAR(val);
				zephir_array_fetch_long(&_12, anno, 2, PH_NOISY | PH_READONLY, "lynx/Annotation/RegexDocParser.zep", 47 TSRMLS_CC);
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
			zephir_array_fetch(&_6, annotations, annoName, PH_NOISY | PH_READONLY, "lynx/Annotation/RegexDocParser.zep", 58 TSRMLS_CC);
			if (!(Z_TYPE_P(_6) == IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(_14);
				array_init_size(_14, 2);
				ZEPHIR_OBS_NVAR(_13);
				zephir_array_fetch(&_13, annotations, annoName, PH_NOISY, "lynx/Annotation/RegexDocParser.zep", 59 TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_14 = NULL;
	HashTable *_11;
	HashPosition _10;
	zend_bool _3, _15, _20;
	zval *value, *val = NULL, *vals, *v = NULL, _0, _1, *_2, _4, *_5, _6 = zval_used_for_init, _7 = zval_used_for_init, *_8 = NULL, _9 = zval_used_for_init, **_12, *_13 = NULL, *_16, _17, _18, *_19, _21, *_22, _23, _24, *_25 = NULL, *_26;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_INIT_VAR(val);
	zephir_fast_trim(val, value, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(_2);
	zephir_substr(_2, val, 0 , 1 , 0);
	_3 = ZEPHIR_IS_STRING(_2, "[");
	if (_3) {
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_LONG(&_4, -1);
		ZEPHIR_INIT_VAR(_5);
		zephir_substr(_5, val, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		_3 = ZEPHIR_IS_STRING(_5, "]");
	}
	if (_3) {
		ZEPHIR_INIT_VAR(vals);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, 1);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, -1);
		ZEPHIR_INIT_VAR(_8);
		zephir_substr(_8, val, 1 , -1 , 0);
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_LONG(&_9, ',');
		zephir_fast_explode(vals, &_9, _8, LONG_MAX TSRMLS_CC);
		ZEPHIR_INIT_NVAR(val);
		array_init(val);
		zephir_is_iterable(vals, &_11, &_10, 0, 0, "lynx/Annotation/RegexDocParser.zep", 89);
		for (
		  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HVALUE(v, _12);
			ZEPHIR_CALL_SELF(&_13, "parsevalue", &_14, v);
			zephir_check_call_status();
			zephir_array_append(&val, _13, PH_SEPARATE, "lynx/Annotation/RegexDocParser.zep", 86);
		}
		RETURN_CCTOR(val);
	} else {
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, 0);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, 1);
		ZEPHIR_INIT_NVAR(_8);
		zephir_substr(_8, val, 0 , 1 , 0);
		_15 = ZEPHIR_IS_STRING(_8, "{");
		if (_15) {
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_LONG(&_9, -1);
			ZEPHIR_INIT_VAR(_16);
			zephir_substr(_16, val, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			_15 = ZEPHIR_IS_STRING(_16, "}");
		}
		if (_15) {
			zephir_json_decode(return_value, &(return_value), val, 0  TSRMLS_CC);
			RETURN_MM();
		} else {
			ZEPHIR_SINIT_VAR(_17);
			ZVAL_LONG(&_17, 0);
			ZEPHIR_SINIT_VAR(_18);
			ZVAL_LONG(&_18, 1);
			ZEPHIR_INIT_VAR(_19);
			zephir_substr(_19, val, 0 , 1 , 0);
			_20 = ZEPHIR_IS_STRING(_19, "\"");
			if (_20) {
				ZEPHIR_SINIT_VAR(_21);
				ZVAL_LONG(&_21, -1);
				ZEPHIR_INIT_VAR(_22);
				zephir_substr(_22, val, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				_20 = ZEPHIR_IS_STRING(_22, "\"");
			}
			if (_20) {
				ZEPHIR_SINIT_VAR(_23);
				ZVAL_LONG(&_23, 1);
				ZEPHIR_SINIT_VAR(_24);
				ZVAL_LONG(&_24, -1);
				ZEPHIR_INIT_VAR(_25);
				zephir_substr(_25, val, 1 , -1 , 0);
				ZEPHIR_CPY_WRT(val, _25);
				ZEPHIR_RETURN_CALL_SELF("parsevalue", &_14, val);
				zephir_check_call_status();
				RETURN_MM();
			} else {
				ZEPHIR_INIT_NVAR(_25);
				zephir_fast_strtolower(_25, val);
				if (ZEPHIR_IS_STRING(_25, "true")) {
					RETURN_MM_BOOL(1);
				} else {
					ZEPHIR_INIT_VAR(_26);
					zephir_fast_strtolower(_26, val);
					if (ZEPHIR_IS_STRING(_26, "false")) {
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

