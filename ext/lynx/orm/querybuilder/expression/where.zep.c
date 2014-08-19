
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "concat.h"


ZEPHIR_INIT_CLASS(Lynx_ORM_QueryBuilder_Expression_Where) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM\\QueryBuilder\\Expression, Where, lynx, orm_querybuilder_expression_where, lynx_orm_querybuilder_expression_where_method_entry, 0);

	zend_declare_property_null(lynx_orm_querybuilder_expression_where_ce, SL("type"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_expression_where_ce, SL("leftExpr"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_expression_where_ce, SL("rightExpr"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_where_ce, SL("EQUAL"), "=" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_where_ce, SL("EQUAL_GREATER"), ">=" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_where_ce, SL("EQUAL_LESS"), "<=" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_where_ce, SL("NOT_EQUAL"), "<>" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_where_ce, SL("GREATER"), ">" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_where_ce, SL("LESS"), "<" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_where_ce, SL("IN"), "IN" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_where_ce, SL("NOT_IN"), "NOT IN" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_where_ce, SL("IS_NULL"), "IS NULL" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_where_ce, SL("IS_NOT_NULL"), "IS NOT NULL" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Where, __construct) {

	zval *type = NULL;
	zval *leftExpr, *rightExpr, *type_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &leftExpr, &rightExpr, &type_param);

	zephir_get_strval(type, type_param);


	zephir_update_property_this(this_ptr, SL("type"), type TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("leftExpr"), leftExpr TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("rightExpr"), rightExpr TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Where, __toString) {

	zval *_0, *_1, *_2;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("leftExpr"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("type"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("rightExpr"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VSVSV(return_value, _0, " ", _1, " ", _2);
	return;

}

