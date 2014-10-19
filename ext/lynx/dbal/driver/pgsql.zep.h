
extern zend_class_entry *lynx_dbal_driver_pgsql_ce;

ZEPHIR_INIT_CLASS(Lynx_DBAL_Driver_Pgsql);

PHP_METHOD(Lynx_DBAL_Driver_Pgsql, setEventsManager);
PHP_METHOD(Lynx_DBAL_Driver_Pgsql, getEventsManager);
PHP_METHOD(Lynx_DBAL_Driver_Pgsql, __construct);
PHP_METHOD(Lynx_DBAL_Driver_Pgsql, isConnected);
PHP_METHOD(Lynx_DBAL_Driver_Pgsql, execute);
PHP_METHOD(Lynx_DBAL_Driver_Pgsql, getNewPlatform);
PHP_METHOD(Lynx_DBAL_Driver_Pgsql, connect);
PHP_METHOD(Lynx_DBAL_Driver_Pgsql, lastInsertId);
PHP_METHOD(Lynx_DBAL_Driver_Pgsql, prepare);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pgsql_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pgsql___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, driverOptions, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pgsql_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pgsql_lastinsertid, 0, 0, 1)
	ZEND_ARG_INFO(0, seq_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pgsql_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_dbal_driver_pgsql_method_entry) {
	PHP_ME(Lynx_DBAL_Driver_Pgsql, setEventsManager, arginfo_lynx_dbal_driver_pgsql_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pgsql, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pgsql, __construct, arginfo_lynx_dbal_driver_pgsql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_DBAL_Driver_Pgsql, isConnected, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pgsql, execute, arginfo_lynx_dbal_driver_pgsql_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pgsql, getNewPlatform, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pgsql, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pgsql, lastInsertId, arginfo_lynx_dbal_driver_pgsql_lastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Pgsql, prepare, arginfo_lynx_dbal_driver_pgsql_prepare, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
