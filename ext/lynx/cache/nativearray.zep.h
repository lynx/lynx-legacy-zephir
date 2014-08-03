
extern zend_class_entry *lynx_cache_nativearray_ce;

ZEPHIR_INIT_CLASS(Lynx_Cache_NativeArray);

PHP_METHOD(Lynx_Cache_NativeArray, getInstance);
PHP_METHOD(Lynx_Cache_NativeArray, __construct);
PHP_METHOD(Lynx_Cache_NativeArray, setInstance);
PHP_METHOD(Lynx_Cache_NativeArray, save);
PHP_METHOD(Lynx_Cache_NativeArray, delete);
PHP_METHOD(Lynx_Cache_NativeArray, get);
PHP_METHOD(Lynx_Cache_NativeArray, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_nativearray___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_nativearray_setinstance, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, instance, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_nativearray_save, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifeTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_nativearray_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_nativearray_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_cache_nativearray_method_entry) {
	PHP_ME(Lynx_Cache_NativeArray, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_NativeArray, __construct, arginfo_lynx_cache_nativearray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_Cache_NativeArray, setInstance, arginfo_lynx_cache_nativearray_setinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_NativeArray, save, arginfo_lynx_cache_nativearray_save, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_NativeArray, delete, arginfo_lynx_cache_nativearray_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_NativeArray, get, arginfo_lynx_cache_nativearray_get, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_NativeArray, flush, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
