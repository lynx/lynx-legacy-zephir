
extern zend_class_entry *lynx_orm_querybuilder_expression_join_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_QueryBuilder_Expression_Join);

PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Join, __construct);
PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Join, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_querybuilder_expression_join___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, join)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, condition)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_querybuilder_expression_join_method_entry) {
	PHP_ME(Lynx_ORM_QueryBuilder_Expression_Join, __construct, arginfo_lynx_orm_querybuilder_expression_join___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_ORM_QueryBuilder_Expression_Join, __toString, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
