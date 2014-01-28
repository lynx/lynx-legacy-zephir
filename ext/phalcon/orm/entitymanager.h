
extern zend_class_entry *phalcon_orm_entitymanager_ce;

ZEPHIR_INIT_CLASS(Phalcon_ORM_EntityManager);

PHP_METHOD(Phalcon_ORM_EntityManager, getConnection);
PHP_METHOD(Phalcon_ORM_EntityManager, __construct);
PHP_METHOD(Phalcon_ORM_EntityManager, flush);
PHP_METHOD(Phalcon_ORM_EntityManager, createQueryBuilder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_orm_entitymanager___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, connection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_orm_entitymanager_flush, 0, 0, 1)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_orm_entitymanager_method_entry) {
	PHP_ME(Phalcon_ORM_EntityManager, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_EntityManager, __construct, arginfo_phalcon_orm_entitymanager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ORM_EntityManager, flush, arginfo_phalcon_orm_entitymanager_flush, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_EntityManager, createQueryBuilder, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
