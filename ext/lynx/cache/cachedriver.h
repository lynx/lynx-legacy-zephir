
extern zend_class_entry *lynx_cache_cachedriver_ce;

ZEPHIR_INIT_CLASS(Lynx_Cache_CacheDriver);

PHP_METHOD(Lynx_Cache_CacheDriver, save);
PHP_METHOD(Lynx_Cache_CacheDriver, delete);
PHP_METHOD(Lynx_Cache_CacheDriver, get);
PHP_METHOD(Lynx_Cache_CacheDriver, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_cachedriver_save, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifeTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_cachedriver_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_cachedriver_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_cachedriver_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_cache_cachedriver_method_entry) {
	PHP_ME(Lynx_Cache_CacheDriver, save, arginfo_lynx_cache_cachedriver_save, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_CacheDriver, delete, arginfo_lynx_cache_cachedriver_delete, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_CacheDriver, get, arginfo_lynx_cache_cachedriver_get, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_CacheDriver, exists, arginfo_lynx_cache_cachedriver_exists, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
