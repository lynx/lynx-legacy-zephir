
extern zend_class_entry *lynx_cache_memcached_ce;

ZEPHIR_INIT_CLASS(Lynx_Cache_Memcached);

PHP_METHOD(Lynx_Cache_Memcached, __construct);
PHP_METHOD(Lynx_Cache_Memcached, setInstance);
PHP_METHOD(Lynx_Cache_Memcached, getInstance);
PHP_METHOD(Lynx_Cache_Memcached, save);
PHP_METHOD(Lynx_Cache_Memcached, delete);
PHP_METHOD(Lynx_Cache_Memcached, get);
PHP_METHOD(Lynx_Cache_Memcached, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_memcached___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_memcached_setinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_memcached_save, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifeTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_memcached_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_cache_memcached_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_cache_memcached_method_entry) {
	PHP_ME(Lynx_Cache_Memcached, __construct, arginfo_lynx_cache_memcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_Cache_Memcached, setInstance, arginfo_lynx_cache_memcached_setinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_Memcached, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_Memcached, save, arginfo_lynx_cache_memcached_save, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_Memcached, delete, arginfo_lynx_cache_memcached_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_Memcached, get, arginfo_lynx_cache_memcached_get, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Cache_Memcached, flush, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
