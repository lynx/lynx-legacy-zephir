
extern zend_class_entry *lynx_orm_querybuilder_expression_join_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_QueryBuilder_Expression_Join);

PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Join, getType);
PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Join, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_querybuilder_expression_join___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_querybuilder_expression_join_method_entry) {
	PHP_ME(Lynx_ORM_QueryBuilder_Expression_Join, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_QueryBuilder_Expression_Join, __construct, arginfo_lynx_orm_querybuilder_expression_join___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
