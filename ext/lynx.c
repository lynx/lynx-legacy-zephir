
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "lynx.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"

zend_class_entry *lynx_dbal_driver_connection_ce;
zend_class_entry *lynx_cache_cachedriver_ce;
zend_class_entry *lynx_annotation_reflectionclassparser_ce;
zend_class_entry *lynx_annotation_regexdocparser_ce;
zend_class_entry *lynx_cache_memcache_ce;
zend_class_entry *lynx_cache_memcached_ce;
zend_class_entry *lynx_cache_nativearray_ce;
zend_class_entry *lynx_dbal_connection_ce;
zend_class_entry *lynx_dbal_driver_pdo_ce;
zend_class_entry *lynx_dbal_driver_pdo_statement_ce;
zend_class_entry *lynx_orm_configuration_ce;
zend_class_entry *lynx_orm_entitymanager_ce;
zend_class_entry *lynx_orm_entityrepository_ce;
zend_class_entry *lynx_orm_exception_ce;
zend_class_entry *lynx_orm_modelmetadata_ce;
zend_class_entry *lynx_orm_modelsmanager_ce;
zend_class_entry *lynx_orm_query_ce;
zend_class_entry *lynx_orm_querybuilder_ce;
zend_class_entry *lynx_orm_queryidentitymap_ce;
zend_class_entry *lynx_orm_sqlbuilder_ce;
zend_class_entry *lynx_orm_unitofwork_ce;
zend_class_entry *lynx_stdlib_eventmanager_ce;

ZEND_DECLARE_MODULE_GLOBALS(lynx)

#define ZEPHIR_NUM_PREALLOCATED_FRAMES 25

void zephir_initialize_memory(zend_zephir_globals_def *zephir_globals_ptr TSRMLS_DC)
{
	zephir_memory_entry *start;
	size_t i;

	start = (zephir_memory_entry *) pecalloc(ZEPHIR_NUM_PREALLOCATED_FRAMES, sizeof(zephir_memory_entry), 1);
/* pecalloc() will take care of these members for every frame
	start->pointer      = 0;
	start->hash_pointer = 0;
	start->prev = NULL;
	start->next = NULL;
*/
	for (i = 0; i < ZEPHIR_NUM_PREALLOCATED_FRAMES; ++i) {
		start[i].addresses       = pecalloc(24, sizeof(zval*), 1);
		start[i].capacity        = 24;
		start[i].hash_addresses  = pecalloc(8, sizeof(zval*), 1);
		start[i].hash_capacity   = 8;

#ifndef ZEPHIR_RELEASE
		start[i].permanent = 1;
#endif
	}

	start[0].next = &start[1];
	start[ZEPHIR_NUM_PREALLOCATED_FRAMES - 1].prev = &start[ZEPHIR_NUM_PREALLOCATED_FRAMES - 2];

	for (i = 1; i < ZEPHIR_NUM_PREALLOCATED_FRAMES - 1; ++i) {
		start[i].next = &start[i + 1];
		start[i].prev = &start[i - 1];
	}

	zephir_globals_ptr->start_memory = start;
	zephir_globals_ptr->end_memory   = start + ZEPHIR_NUM_PREALLOCATED_FRAMES;

	zephir_globals_ptr->fcache = pemalloc(sizeof(HashTable), 1);
	zend_hash_init(zephir_globals_ptr->fcache, 128, NULL, NULL, 1); // zephir_fcall_cache_dtor

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_null);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_null, 2);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_false);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_false, 2);
	ZVAL_FALSE(zephir_globals_ptr->global_false);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_true);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_true, 2);
	ZVAL_TRUE(zephir_globals_ptr->global_true);

	//zephir_globals_ptr->initialized = 1;
}

int zephir_cleanup_fcache(void *pDest TSRMLS_DC, int num_args, va_list args, zend_hash_key *hash_key)
{
	zephir_fcall_cache_entry **entry = (zephir_fcall_cache_entry**)pDest;
	zend_class_entry *scope;
	uint len = hash_key->nKeyLength;

	assert(hash_key->arKey != NULL);
	assert(hash_key->nKeyLength > 2 * sizeof(zend_class_entry**));

	memcpy(&scope, &hash_key->arKey[len - 2 * sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

/*
#ifndef ZEPHIR_RELEASE
	{
		zend_class_entry *cls;
		memcpy(&cls, &hash_key->arKey[len - sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

		fprintf(stderr, "func: %s, cls: %s, scope: %s [%u]\n", (*entry)->f->common.function_name, (cls ? cls->name : "N/A"), (scope ? scope->name : "N/A"), (uint)(*entry)->times);
	}
#endif
*/

#ifndef ZEPHIR_RELEASE
	if ((*entry)->f->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if ((*entry)->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

#if PHP_VERSION_ID >= 50400
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->info.internal.module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

	return ZEND_HASH_APPLY_KEEP;
}

void zephir_deinitialize_memory(TSRMLS_D)
{
	size_t i;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	//if (zephir_globals_ptr->initialized != 1) {
	//	zephir_globals_ptr->initialized = 0;
	//	return;
	//}

	if (zephir_globals_ptr->start_memory != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	//zephir_orm_destroy_cache(TSRMLS_C);

	zend_hash_apply_with_arguments(zephir_globals_ptr->fcache TSRMLS_CC, zephir_cleanup_fcache, 0);

#ifndef ZEPHIR_RELEASE
	assert(zephir_globals_ptr->start_memory != NULL);
#endif

	for (i = 0; i < ZEPHIR_NUM_PREALLOCATED_FRAMES; ++i) {
		pefree(zephir_globals_ptr->start_memory[i].hash_addresses, 1);
		pefree(zephir_globals_ptr->start_memory[i].addresses, 1);
	}

	pefree(zephir_globals_ptr->start_memory, 1);
	zephir_globals_ptr->start_memory = NULL;

	zend_hash_destroy(zephir_globals_ptr->fcache);
	pefree(zephir_globals_ptr->fcache, 1);
	zephir_globals_ptr->fcache = NULL;

	for (i = 0; i < 2; i++) {
		zval_ptr_dtor(&zephir_globals_ptr->global_null);
		zval_ptr_dtor(&zephir_globals_ptr->global_false);
		zval_ptr_dtor(&zephir_globals_ptr->global_true);
	}

	//zephir_globals_ptr->initialized = 0;
}

static PHP_MINIT_FUNCTION(lynx)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Lynx_DBAL_Driver_Connection);
	ZEPHIR_INIT(Lynx_Cache_CacheDriver);
	ZEPHIR_INIT(Lynx_Annotation_ReflectionClassParser);
	ZEPHIR_INIT(Lynx_Annotation_RegexDocParser);
	ZEPHIR_INIT(Lynx_Cache_Memcache);
	ZEPHIR_INIT(Lynx_Cache_Memcached);
	ZEPHIR_INIT(Lynx_Cache_NativeArray);
	ZEPHIR_INIT(Lynx_DBAL_Connection);
	ZEPHIR_INIT(Lynx_DBAL_Driver_PDO_Statement);
	ZEPHIR_INIT(Lynx_DBAL_Driver_Pdo);
	ZEPHIR_INIT(Lynx_ORM_Configuration);
	ZEPHIR_INIT(Lynx_ORM_EntityManager);
	ZEPHIR_INIT(Lynx_ORM_EntityRepository);
	ZEPHIR_INIT(Lynx_ORM_Exception);
	ZEPHIR_INIT(Lynx_ORM_ModelMetaData);
	ZEPHIR_INIT(Lynx_ORM_ModelsManager);
	ZEPHIR_INIT(Lynx_ORM_Query);
	ZEPHIR_INIT(Lynx_ORM_QueryBuilder);
	ZEPHIR_INIT(Lynx_ORM_QueryIdentityMap);
	ZEPHIR_INIT(Lynx_ORM_SqlBuilder);
	ZEPHIR_INIT(Lynx_ORM_UnitOfWork);
	ZEPHIR_INIT(Lynx_Stdlib_EventManager);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(lynx)
{

	zephir_deinitialize_memory(TSRMLS_C);

	//assert(ZEPHIR_GLOBAL(orm).parser_cache == NULL);
	//assert(ZEPHIR_GLOBAL(orm).ast_cache == NULL);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_lynx_globals *zephir_globals TSRMLS_DC)
{

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(lynx)
{

	zend_lynx_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(lynx)
{

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(lynx)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_LYNX_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_LYNX_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_LYNX_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_LYNX_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_LYNX_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(lynx)
{
	php_zephir_init_globals(lynx_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(lynx)
{

}

zend_module_entry lynx_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_LYNX_EXTNAME,
	NULL,
	PHP_MINIT(lynx),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(lynx),
#else
	NULL,
#endif
	PHP_RINIT(lynx),
	PHP_RSHUTDOWN(lynx),
	PHP_MINFO(lynx),
	PHP_LYNX_VERSION,
	ZEND_MODULE_GLOBALS(lynx),
	PHP_GINIT(lynx),
	PHP_GSHUTDOWN(lynx),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_LYNX
ZEND_GET_MODULE(lynx)
#endif
