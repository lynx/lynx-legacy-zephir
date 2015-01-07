
extern zend_class_entry *lynx_dbal_platform_mysql_ce;

ZEPHIR_INIT_CLASS(Lynx_DBAL_Platform_MySQL);

PHP_METHOD(Lynx_DBAL_Platform_MySQL, wrap);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_platform_mysql_wrap, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_dbal_platform_mysql_method_entry) {
	PHP_ME(Lynx_DBAL_Platform_MySQL, wrap, arginfo_lynx_dbal_platform_mysql_wrap, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
