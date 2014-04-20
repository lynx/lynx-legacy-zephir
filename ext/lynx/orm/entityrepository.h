
extern zend_class_entry *lynx_orm_entityrepository_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_EntityRepository);

PHP_METHOD(Lynx_ORM_EntityRepository, __construct);
PHP_METHOD(Lynx_ORM_EntityRepository, createQueryBuilder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_entityrepository___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, em)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_entityrepository_createquerybuilder, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_entityrepository_method_entry) {
	PHP_ME(Lynx_ORM_EntityRepository, __construct, arginfo_lynx_orm_entityrepository___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_ORM_EntityRepository, createQueryBuilder, arginfo_lynx_orm_entityrepository_createquerybuilder, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
