
extern zend_class_entry *lynx_orm_querybuilder_expression_where_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_QueryBuilder_Expression_Where);

PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Where, __construct);
PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Where, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_querybuilder_expression_where___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, leftExpr)
	ZEND_ARG_INFO(0, rightExpr)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_querybuilder_expression_where_method_entry) {
	PHP_ME(Lynx_ORM_QueryBuilder_Expression_Where, __construct, arginfo_lynx_orm_querybuilder_expression_where___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_ORM_QueryBuilder_Expression_Where, __toString, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
