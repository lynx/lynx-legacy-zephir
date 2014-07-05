
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Lynx_Stdlib_Hydrator_Hydrator) {

	ZEPHIR_REGISTER_INTERFACE(Lynx\\Stdlib\\Hydrator, Hydrator, lynx, stdlib_hydrator_hydrator, lynx_stdlib_hydrator_hydrator_method_entry);

	return SUCCESS;

}

/**
 * Hydrate values to object
 */
ZEPHIR_DOC_METHOD(Lynx_Stdlib_Hydrator_Hydrator, hydrate);

/**
 * Extract values from object
 */
ZEPHIR_DOC_METHOD(Lynx_Stdlib_Hydrator_Hydrator, extract);

