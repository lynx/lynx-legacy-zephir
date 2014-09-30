
extern zend_class_entry *lynx_dbal_driver_pdoconnection_ce;

ZEPHIR_INIT_CLASS(Lynx_DBAL_Driver_PDOConnection);

PHP_METHOD(Lynx_DBAL_Driver_PDOConnection, setEventsManager);
PHP_METHOD(Lynx_DBAL_Driver_PDOConnection, getEventsManager);
PHP_METHOD(Lynx_DBAL_Driver_PDOConnection, __construct);
PHP_METHOD(Lynx_DBAL_Driver_PDOConnection, isConnected);
PHP_METHOD(Lynx_DBAL_Driver_PDOConnection, execute);
PHP_METHOD(Lynx_DBAL_Driver_PDOConnection, connect);
PHP_METHOD(Lynx_DBAL_Driver_PDOConnection, lastInsertId);
PHP_METHOD(Lynx_DBAL_Driver_PDOConnection, prepare);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pdoconnection_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pdoconnection___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, driverOptions, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pdoconnection_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_pdoconnection_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_dbal_driver_pdoconnection_method_entry) {
	PHP_ME(Lynx_DBAL_Driver_PDOConnection, setEventsManager, arginfo_lynx_dbal_driver_pdoconnection_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_PDOConnection, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_PDOConnection, __construct, arginfo_lynx_dbal_driver_pdoconnection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_DBAL_Driver_PDOConnection, isConnected, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_PDOConnection, execute, arginfo_lynx_dbal_driver_pdoconnection_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_PDOConnection, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_PDOConnection, lastInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_PDOConnection, prepare, arginfo_lynx_dbal_driver_pdoconnection_prepare, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
