
extern zend_class_entry *lynx_orm_configuration_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_Configuration);

PHP_METHOD(Lynx_ORM_Configuration, getCacheDriver);
PHP_METHOD(Lynx_ORM_Configuration, setCacheDriver);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_configuration_setcachedriver, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cacheDriver, Cacher\\Driver, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_configuration_method_entry) {
	PHP_ME(Lynx_ORM_Configuration, getCacheDriver, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Configuration, setCacheDriver, arginfo_lynx_orm_configuration_setcachedriver, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
