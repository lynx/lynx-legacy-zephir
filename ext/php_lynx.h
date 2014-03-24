
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_LYNX_H
#define PHP_LYNX_H 1

#include "kernel/globals.h"

#define PHP_LYNX_NAME    "Lynx"
#define PHP_LYNX_VERSION "0.0.1"
#define PHP_LYNX_EXTNAME "lynx"



ZEND_BEGIN_MODULE_GLOBALS(lynx)

	/* Memory */
	zephir_memory_entry *start_memory;
	zephir_memory_entry *active_memory;

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/* Function cache */
	HashTable *function_cache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(lynx)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(lynx)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(lynx_globals_id, zend_lynx_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (lynx_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_lynx_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(lynx_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(lynx_globals)
#endif

#define zephir_globals lynx_globals
#define zend_zephir_globals zend_lynx_globals

extern zend_module_entry lynx_module_entry;
#define phpext_lynx_ptr &lynx_module_entry

#endif
