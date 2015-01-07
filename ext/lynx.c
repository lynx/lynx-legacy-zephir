
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



zend_class_entry *lynx_stdlib_hydrator_hydrator_ce;
zend_class_entry *lynx_stdlib_events_eventsmanager_ce;
zend_class_entry *lynx_dbal_driver_connection_ce;
zend_class_entry *lynx_stdlib_collections_collection_ce;
zend_class_entry *lynx_annotation_reflectionclassparser_ce;
zend_class_entry *lynx_annotation_regexdocparser_ce;
zend_class_entry *lynx_dbal_connection_ce;
zend_class_entry *lynx_dbal_driver_mysql_ce;
zend_class_entry *lynx_dbal_driver_pdo_ce;
zend_class_entry *lynx_dbal_driver_pdo_statement_ce;
zend_class_entry *lynx_dbal_driver_pdoconnection_ce;
zend_class_entry *lynx_dbal_driver_pgsql_ce;
zend_class_entry *lynx_dbal_events_ce;
zend_class_entry *lynx_dbal_platform_mysql_ce;
zend_class_entry *lynx_dbal_platform_pgsql_ce;
zend_class_entry *lynx_orm_configuration_ce;
zend_class_entry *lynx_orm_entitymanager_ce;
zend_class_entry *lynx_orm_entityrepository_ce;
zend_class_entry *lynx_orm_exception_ce;
zend_class_entry *lynx_orm_modelmetadata_ce;
zend_class_entry *lynx_orm_modelmetadata_column_ce;
zend_class_entry *lynx_orm_modelmetadata_property_ce;
zend_class_entry *lynx_orm_modelsmanager_ce;
zend_class_entry *lynx_orm_query_ce;
zend_class_entry *lynx_orm_querybuilder_ce;
zend_class_entry *lynx_orm_querybuilder_expression_join_ce;
zend_class_entry *lynx_orm_querybuilder_expression_where_ce;
zend_class_entry *lynx_orm_queryidentitymap_ce;
zend_class_entry *lynx_orm_sqlbuilder_ce;
zend_class_entry *lynx_orm_unitofwork_ce;
zend_class_entry *lynx_stdlib_collections_arraycollection_ce;
zend_class_entry *lynx_stdlib_events_event_ce;
zend_class_entry *lynx_stdlib_events_manager_ce;
zend_class_entry *lynx_stdlib_hydrator_classmethods_ce;
zend_class_entry *lynx_stdlib_hydrator_classproperties_ce;
zend_class_entry *lynx_stdlib_hydrator_entity_ce;

ZEND_DECLARE_MODULE_GLOBALS(lynx)

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

	ZEPHIR_INIT(Lynx_Stdlib_Hydrator_Hydrator);
	ZEPHIR_INIT(Lynx_Stdlib_Events_EventsManager);
	ZEPHIR_INIT(Lynx_DBAL_Driver_Connection);
	ZEPHIR_INIT(Lynx_Stdlib_Collections_Collection);
	ZEPHIR_INIT(Lynx_Annotation_ReflectionClassParser);
	ZEPHIR_INIT(Lynx_Annotation_RegexDocParser);
	ZEPHIR_INIT(Lynx_DBAL_Connection);
	ZEPHIR_INIT(Lynx_DBAL_Driver_MySQL);
	ZEPHIR_INIT(Lynx_DBAL_Driver_PDOConnection);
	ZEPHIR_INIT(Lynx_DBAL_Driver_Pdo);
	ZEPHIR_INIT(Lynx_DBAL_Driver_Pdo_Statement);
	ZEPHIR_INIT(Lynx_DBAL_Driver_PgSQL);
	ZEPHIR_INIT(Lynx_DBAL_Events);
	ZEPHIR_INIT(Lynx_DBAL_Platform_MySQL);
	ZEPHIR_INIT(Lynx_DBAL_Platform_Pgsql);
	ZEPHIR_INIT(Lynx_ORM_Configuration);
	ZEPHIR_INIT(Lynx_ORM_EntityManager);
	ZEPHIR_INIT(Lynx_ORM_EntityRepository);
	ZEPHIR_INIT(Lynx_ORM_Exception);
	ZEPHIR_INIT(Lynx_ORM_ModelMetaData);
	ZEPHIR_INIT(Lynx_ORM_ModelMetaData_Column);
	ZEPHIR_INIT(Lynx_ORM_ModelMetaData_Property);
	ZEPHIR_INIT(Lynx_ORM_ModelsManager);
	ZEPHIR_INIT(Lynx_ORM_Query);
	ZEPHIR_INIT(Lynx_ORM_QueryBuilder);
	ZEPHIR_INIT(Lynx_ORM_QueryBuilder_Expression_Join);
	ZEPHIR_INIT(Lynx_ORM_QueryBuilder_Expression_Where);
	ZEPHIR_INIT(Lynx_ORM_QueryIdentityMap);
	ZEPHIR_INIT(Lynx_ORM_SqlBuilder);
	ZEPHIR_INIT(Lynx_ORM_UnitOfWork);
	ZEPHIR_INIT(Lynx_Stdlib_Collections_ArrayCollection);
	ZEPHIR_INIT(Lynx_Stdlib_Events_Event);
	ZEPHIR_INIT(Lynx_Stdlib_Events_Manager);
	ZEPHIR_INIT(Lynx_Stdlib_Hydrator_ClassMethods);
	ZEPHIR_INIT(Lynx_Stdlib_Hydrator_ClassProperties);
	ZEPHIR_INIT(Lynx_Stdlib_Hydrator_Entity);

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

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_lynx_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	zephir_globals->cache_enabled = 1;

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
