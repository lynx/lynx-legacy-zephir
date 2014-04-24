
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"

ZEPHIR_INIT_CLASS(Lynx_ORM_ModelsManager) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, ModelsManager, lynx, orm_modelsmanager, lynx_orm_modelsmanager_method_entry, 0);

	zend_declare_property_null(lynx_orm_modelsmanager_ce, SL("cachedModels"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_ModelsManager, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *classname_param = NULL, *_0, *_1, *_2, *_3;
	zval *classname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname_param);

	if (unlikely(Z_TYPE_P(classname_param) != IS_STRING && Z_TYPE_P(classname_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'classname' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(classname_param) == IS_STRING)) {
		classname = classname_param;
	} else {
		ZEPHIR_INIT_VAR(classname);
		ZVAL_EMPTY_STRING(classname);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cachedModels"), PH_NOISY_CC);
	if (zephir_array_isset(_0, classname)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("cachedModels"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, classname, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, lynx_orm_modelmetadata_ce);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, classname);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("cachedModels"), classname, _3 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("cachedModels"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, classname, PH_NOISY | PH_READONLY TSRMLS_CC);
	RETURN_CTOR(_2);

}

PHP_METHOD(Lynx_ORM_ModelsManager, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("cachedModels"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

