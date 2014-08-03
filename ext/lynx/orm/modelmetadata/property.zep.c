
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


ZEPHIR_INIT_CLASS(Lynx_ORM_ModelMetaData_Property) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM\\ModelMetaData, Property, lynx, orm_modelmetadata_property, NULL, 0);

	zend_declare_property_null(lynx_orm_modelmetadata_property_ce, SL("type"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelmetadata_property_ce, SL("targetEntity"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelmetadata_property_ce, SL("name"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(lynx_orm_modelmetadata_property_ce, SL("referencedColumnName"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

