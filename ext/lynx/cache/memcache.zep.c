
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Lynx_Cache_Memcache) {

	ZEPHIR_REGISTER_CLASS_EX(Lynx\\Cache, Memcache, lynx, cache_memcache, lynx_cache_cachedriver_ce, lynx_cache_memcache_method_entry, 0);

	zend_declare_property_null(lynx_cache_memcache_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_cache_memcache_ce, SL("instance"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_Cache_Memcache, __construct) {

	zval *options_param = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_Cache_Memcache, setInstance) {

	zval *instance;

	zephir_fetch_params(0, 1, 0, &instance);



	if (!(zephir_is_instance_of(instance, SL("Memcache") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'instance' must be an instance of 'Memcache'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("instance"), instance TSRMLS_CC);

}

PHP_METHOD(Lynx_Cache_Memcache, getInstance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_2;
	zval *_0, *_1, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1);
		_2 = zend_fetch_class(SL("Memcache"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_1, _2);
		if (zephir_has_constructor(_1 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("instance"), _1 TSRMLS_CC);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "localhost", 0);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_LONG(_5, 11211);
		ZEPHIR_CALL_METHOD(NULL, _3, "connect", NULL, _4, _5);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		RETURN_MM_MEMBER(this_ptr, "instance");
	}
	RETURN_MM_MEMBER(this_ptr, "instance");

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Cache_Memcache, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *data, *lifeTime = NULL, *_0 = NULL, *_1;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &id_param, &data, &lifeTime);

	if (unlikely(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(id_param) == IS_STRING)) {
		id = id_param;
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}
	if (!lifeTime) {
		ZEPHIR_INIT_VAR(lifeTime);
		ZVAL_LONG(lifeTime, 3600);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinstance",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_RETURN_CALL_METHOD(_0, "set", NULL, id, data, _1, lifeTime);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Cache_Memcache, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *_0 = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (unlikely(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(id_param) == IS_STRING)) {
		id = id_param;
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinstance",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "delete", NULL, id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Cache_Memcache, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *_0 = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (unlikely(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(id_param) == IS_STRING)) {
		id = id_param;
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinstance",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Lynx_Cache_Memcache, flush) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinstance",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "flush", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

