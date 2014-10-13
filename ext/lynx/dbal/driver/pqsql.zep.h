
extern zend_class_entry *lynx_dbal_driver_pqsql_ce;

ZEPHIR_INIT_CLASS(Lynx_DBAL_Driver_Pqsql);

PHP_METHOD(Lynx_DBAL_Driver_Pqsql, setEventsManager);
PHP_METHOD(Lynx_DBAL_Driver_Pqsql, getEventsManager);
PHP_METHOD(Lynx_DBAL_Driver_Pqsql, __construct);
PHP_METHOD(Lynx_DBAL_Driver_Pqsql, isConnected);
PHP_METHOD(Lynx_DBAL_Driver_Pqsql, execute);
PHP_METHOD(Lynx_DBAL_Driver_Pqsql, connect);
PHP_METHOD(Lynx_DBAL_Driver_Pqsql, lastInsertId);
PHP_METHOD(Lynx_DBAL_Driver_Pqsql, prepare);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pqsql_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pqsql___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, driverOptions, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pqsql_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pqsql_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_dbal_driver_pqsql_method_entry) {
	PHP_ME(Lynx_DBAL_Driver_Pqsql, setEventsManager, arginfo_lynx_dbal_driver_pqsql_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pqsql, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pqsql, __construct, arginfo_lynx_dbal_driver_pqsql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_DBAL_Driver_Pqsql, isConnected, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pqsql, execute, arginfo_lynx_dbal_driver_pqsql_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pqsql, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pqsql, lastInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pqsql, prepare, arginfo_lynx_dbal_driver_pqsql_prepare, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
