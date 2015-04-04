
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"

ZEPHIR_INIT_CLASS(Lynx_ORM_ModelsManager) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, ModelsManager, lynx, orm_modelsmanager, lynx_orm_modelsmanager_method_entry, 0);

	/**
	 * @var EntityManager
	 */
	zend_declare_property_null(lynx_orm_modelsmanager_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelsmanager_ce, SL("cachedModels"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_bool(lynx_orm_modelsmanager_ce, SL("cacheLoaded"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelsmanager_ce, SL("cacheLoadType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_modelsmanager_ce, SL("CACHE_LOAD_PER_GET"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_modelsmanager_ce, SL("CACHE_LOAD_PER_GET_ALL"), 1 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_ModelsManager, __construct) {

	zval *em, *cacheLoadType = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &em, &cacheLoadType);

	if (!cacheLoadType) {
		ZEPHIR_INIT_VAR(cacheLoadType);
		ZVAL_LONG(cacheLoadType, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("cachedModels"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("cacheLoadType"), cacheLoadType TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_ModelsManager, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *classname_param = NULL, *_0, *cacheDriver = NULL, *_1, *_2 = NULL, *_3, *_4, *_5;
	zval *classname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname_param);

	if (unlikely(Z_TYPE_P(classname_param) != IS_STRING && Z_TYPE_P(classname_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'classname' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(classname_param) == IS_STRING)) {
		zephir_get_strval(classname, classname_param);
	} else {
		ZEPHIR_INIT_VAR(classname);
		ZVAL_EMPTY_STRING(classname);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cacheLoaded"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, _1, "getconfiguration", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&cacheDriver, _2, "getcachedriver", NULL);
		zephir_check_call_status();
		if (zephir_is_true(cacheDriver)) {
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("cachedModels"), PH_NOISY_CC);
	if (zephir_array_isset(_1, classname)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("cachedModels"), PH_NOISY_CC);
		zephir_array_fetch(&_4, _3, classname, PH_NOISY | PH_READONLY, "lynx/ORM/ModelsManager.zep", 42 TSRMLS_CC);
		RETURN_CTOR(_4);
	}
	ZEPHIR_INIT_VAR(_5);
	object_init_ex(_5, lynx_orm_modelmetadata_ce);
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, classname);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("cachedModels"), classname, _5 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("cachedModels"), PH_NOISY_CC);
	zephir_array_fetch(&_4, _1, classname, PH_NOISY | PH_READONLY, "lynx/ORM/ModelsManager.zep", 46 TSRMLS_CC);
	RETURN_CTOR(_4);

}

