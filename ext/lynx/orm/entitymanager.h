
extern zend_class_entry *lynx_orm_entitymanager_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_EntityManager);

PHP_METHOD(Lynx_ORM_EntityManager, getConnection);
PHP_METHOD(Lynx_ORM_EntityManager, getModelsManager);
PHP_METHOD(Lynx_ORM_EntityManager, getEventManager);
PHP_METHOD(Lynx_ORM_EntityManager, getConfiguration);
PHP_METHOD(Lynx_ORM_EntityManager, __construct);
PHP_METHOD(Lynx_ORM_EntityManager, flush);
PHP_METHOD(Lynx_ORM_EntityManager, remove);
PHP_METHOD(Lynx_ORM_EntityManager, beginTransaction);
PHP_METHOD(Lynx_ORM_EntityManager, commit);
PHP_METHOD(Lynx_ORM_EntityManager, rollback);
PHP_METHOD(Lynx_ORM_EntityManager, getRepository);
PHP_METHOD(Lynx_ORM_EntityManager, createQueryBuilder);
PHP_METHOD(Lynx_ORM_EntityManager, createQuery);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_entitymanager___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, connection)
	ZEND_ARG_INFO(0, configuration)
	ZEND_ARG_INFO(0, eventManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_entitymanager_flush, 0, 0, 1)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_entitymanager_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_entitymanager_getrepository, 0, 0, 1)
	ZEND_ARG_INFO(0, entityName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_entitymanager_createquery, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_entitymanager_method_entry) {
	PHP_ME(Lynx_ORM_EntityManager, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_EntityManager, getModelsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_EntityManager, getEventManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_EntityManager, getConfiguration, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_EntityManager, __construct, arginfo_lynx_orm_entitymanager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_ORM_EntityManager, flush, arginfo_lynx_orm_entitymanager_flush, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_EntityManager, remove, arginfo_lynx_orm_entitymanager_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_EntityManager, beginTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_EntityManager, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_EntityManager, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_EntityManager, getRepository, arginfo_lynx_orm_entitymanager_getrepository, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_EntityManager, createQueryBuilder, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_EntityManager, createQuery, arginfo_lynx_orm_entitymanager_createquery, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
