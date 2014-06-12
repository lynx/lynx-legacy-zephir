
extern zend_class_entry *lynx_cache_phparray_ce;

ZEPHIR_INIT_CLASS(Lynx_Cache_PhpArray);

PHP_METHOD(Lynx_Cache_PhpArray, __construct);
PHP_METHOD(Lynx_Cache_PhpArray, setInstance);
PHP_METHOD(Lynx_Cache_PhpArray, getInstance);
PHP_METHOD(Lynx_Cache_PhpArray, save);
PHP_METHOD(Lynx_Cache_PhpArray, delete);
PHP_METHOD(Lynx_Cache_PhpArray, get);
PHP_METHOD(Lynx_Cache_PhpArray, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_phparray___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_phparray_setinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_phparray_save, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifeTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_phparray_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_phparray_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_cache_phparray_method_entry) {
	PHP_ME(Lynx_Cache_PhpArray, __construct, arginfo_lynx_cache_phparray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_Cache_PhpArray, setInstance, arginfo_lynx_cache_phparray_setinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_PhpArray, getInstance, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Lynx_Cache_PhpArray, save, arginfo_lynx_cache_phparray_save, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_PhpArray, delete, arginfo_lynx_cache_phparray_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_PhpArray, get, arginfo_lynx_cache_phparray_get, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_PhpArray, flush, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
