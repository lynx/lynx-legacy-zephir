
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Lynx_DBAL_Driver_Connection) {

	ZEPHIR_REGISTER_INTERFACE(Lynx\\DBAL\\Driver, Connection, lynx, dbal_driver_connection, lynx_dbal_driver_connection_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Lynx_DBAL_Driver_Connection, commit);

ZEPHIR_DOC_METHOD(Lynx_DBAL_Driver_Connection, rollBack);

ZEPHIR_DOC_METHOD(Lynx_DBAL_Driver_Connection, beginTransaction);

ZEPHIR_DOC_METHOD(Lynx_DBAL_Driver_Connection, setEventsManager);

