
extern zend_class_entry *lynx_dbal_connection_ce;

ZEPHIR_INIT_CLASS(Lynx_DBAL_Connection);

PHP_METHOD(Lynx_DBAL_Connection, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_connection___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, driver)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_dbal_connection_method_entry) {
	PHP_ME(Lynx_DBAL_Connection, __construct, arginfo_lynx_dbal_connection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
