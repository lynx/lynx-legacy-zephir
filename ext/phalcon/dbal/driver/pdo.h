
extern zend_class_entry *phalcon_dbal_driver_pdo_ce;

ZEPHIR_INIT_CLASS(Phalcon_DBAL_Driver_Pdo);

PHP_METHOD(Phalcon_DBAL_Driver_Pdo, __construct);
PHP_METHOD(Phalcon_DBAL_Driver_Pdo, connect);
PHP_METHOD(Phalcon_DBAL_Driver_Pdo, query);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dbal_driver_pdo___construct, 0, 0, 1)
  ZEND_ARG_INFO(0, dsn)
  ZEND_ARG_INFO(0, username)
  ZEND_ARG_INFO(0, password)
  ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dbal_driver_pdo_query, 0, 0, 1)
  ZEND_ARG_INFO(0, sqlStatement)
  ZEND_ARG_INFO(0, bindParams)
  ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_dbal_driver_pdo_method_entry) {
	PHP_ME(Phalcon_DBAL_Driver_Pdo, __construct, arginfo_phalcon_dbal_driver_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_DBAL_Driver_Pdo, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DBAL_Driver_Pdo, query, arginfo_phalcon_dbal_driver_pdo_query, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
