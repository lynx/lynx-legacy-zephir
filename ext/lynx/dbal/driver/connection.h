
extern zend_class_entry *lynx_dbal_driver_connection_ce;

ZEPHIR_INIT_CLASS(Lynx_DBAL_Driver_Connection);

ZEPHIR_INIT_FUNCS(lynx_dbal_driver_connection_method_entry) {
	PHP_ABSTRACT_ME(Lynx_DBAL_Driver_Connection, commit, NULL)
	PHP_ABSTRACT_ME(Lynx_DBAL_Driver_Connection, rollBack, NULL)
	PHP_ABSTRACT_ME(Lynx_DBAL_Driver_Connection, beginTransaction, NULL)
  PHP_FE_END
};
