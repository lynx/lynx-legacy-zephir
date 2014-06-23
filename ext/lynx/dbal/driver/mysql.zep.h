
extern zend_class_entry *lynx_dbal_driver_mysql_ce;

ZEPHIR_INIT_CLASS(Lynx_DBAL_Driver_Mysql);

PHP_METHOD(Lynx_DBAL_Driver_Mysql, setEventsManager);
PHP_METHOD(Lynx_DBAL_Driver_Mysql, getEventsManager);
PHP_METHOD(Lynx_DBAL_Driver_Mysql, __construct);
PHP_METHOD(Lynx_DBAL_Driver_Mysql, isConnected);
PHP_METHOD(Lynx_DBAL_Driver_Mysql, execute);
PHP_METHOD(Lynx_DBAL_Driver_Mysql, connect);
PHP_METHOD(Lynx_DBAL_Driver_Mysql, prepare);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_mysql_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_mysql___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, driverOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_mysql_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_mysql_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_dbal_driver_mysql_method_entry) {
	PHP_ME(Lynx_DBAL_Driver_Mysql, setEventsManager, arginfo_lynx_dbal_driver_mysql_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Mysql, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Mysql, __construct, arginfo_lynx_dbal_driver_mysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_DBAL_Driver_Mysql, isConnected, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Mysql, execute, arginfo_lynx_dbal_driver_mysql_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Mysql, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_Driver_Mysql, prepare, arginfo_lynx_dbal_driver_mysql_prepare, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
