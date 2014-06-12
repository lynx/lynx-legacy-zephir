
extern zend_class_entry *lynx_dbal_driver_connection_ce;

ZEPHIR_INIT_CLASS(Lynx_DBAL_Driver_Connection);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_driver_connection_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_dbal_driver_connection_method_entry) {
	PHP_ABSTRACT_ME(Lynx_DBAL_Driver_Connection, commit, NULL)
	PHP_ABSTRACT_ME(Lynx_DBAL_Driver_Connection, rollBack, NULL)
	PHP_ABSTRACT_ME(Lynx_DBAL_Driver_Connection, beginTransaction, NULL)
	PHP_ABSTRACT_ME(Lynx_DBAL_Driver_Connection, setEventsManager, arginfo_lynx_dbal_driver_connection_seteventsmanager)
  PHP_FE_END
};
