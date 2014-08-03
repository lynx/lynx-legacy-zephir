
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Lynx_ORM_QueryBuilder_Expression_Join) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM\\QueryBuilder\\Expression, Join, lynx, orm_querybuilder_expression_join, lynx_orm_querybuilder_expression_join_method_entry, 0);

	zend_declare_property_null(lynx_orm_querybuilder_expression_join_ce, SL("type"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_class_constant_null(lynx_orm_querybuilder_expression_join_ce, SL("RIGHT_JOIN") TSRMLS_CC);

	zend_declare_class_constant_null(lynx_orm_querybuilder_expression_join_ce, SL("INNER_JOIN") TSRMLS_CC);

	zend_declare_class_constant_null(lynx_orm_querybuilder_expression_join_ce, SL("LEFT_JOIN") TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Join, getType) {


	RETURN_MEMBER(this_ptr, "type");

}

PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Join, __construct) {

	zval *type_param = NULL, *join, *alias, *conditionType, *condition = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &type_param, &join, &alias, &conditionType, &condition);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(type_param) == IS_STRING)) {
		type = type_param;
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	if (!condition) {
		condition = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("type"), type TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

