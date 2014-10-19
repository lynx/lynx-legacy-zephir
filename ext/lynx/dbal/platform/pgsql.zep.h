
extern zend_class_entry *lynx_dbal_platform_pgsql_ce;

ZEPHIR_INIT_CLASS(Lynx_DBAL_Platform_Pgsql);

PHP_METHOD(Lynx_DBAL_Platform_Pgsql, wrap);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_platform_pgsql_wrap, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_dbal_platform_pgsql_method_entry) {
	PHP_ME(Lynx_DBAL_Platform_Pgsql, wrap, arginfo_lynx_dbal_platform_pgsql_wrap, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
