
extern zend_class_entry *lynx_cache_memcache_ce;

ZEPHIR_INIT_CLASS(Lynx_Cache_Memcache);

PHP_METHOD(Lynx_Cache_Memcache, __construct);
PHP_METHOD(Lynx_Cache_Memcache, setInstance);
PHP_METHOD(Lynx_Cache_Memcache, getInstance);
PHP_METHOD(Lynx_Cache_Memcache, save);
PHP_METHOD(Lynx_Cache_Memcache, delete);
PHP_METHOD(Lynx_Cache_Memcache, get);
PHP_METHOD(Lynx_Cache_Memcache, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_memcache___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_memcache_setinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_memcache_save, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifeTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_memcache_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_memcache_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_memcache_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_cache_memcache_method_entry) {
	PHP_ME(Lynx_Cache_Memcache, __construct, arginfo_lynx_cache_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_Cache_Memcache, setInstance, arginfo_lynx_cache_memcache_setinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_Memcache, getInstance, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Lynx_Cache_Memcache, save, arginfo_lynx_cache_memcache_save, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_Memcache, delete, arginfo_lynx_cache_memcache_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_Memcache, get, arginfo_lynx_cache_memcache_get, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_Memcache, exists, arginfo_lynx_cache_memcache_exists, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
