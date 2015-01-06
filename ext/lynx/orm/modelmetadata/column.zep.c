
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Lynx_ORM_ModelMetaData_Column) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM\\ModelMetaData, Column, lynx, orm_modelmetadata_column, NULL, 0);

	zend_declare_property_bool(lynx_orm_modelmetadata_column_ce, SL("id"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_bool(lynx_orm_modelmetadata_column_ce, SL("generatedValue"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelmetadata_column_ce, SL("name"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(lynx_orm_modelmetadata_column_ce, SL("type"), "string", ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

