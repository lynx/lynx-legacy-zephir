
extern zend_class_entry *lynx_orm_modelsmanager_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_ModelsManager);

PHP_METHOD(Lynx_ORM_ModelsManager, __construct);
PHP_METHOD(Lynx_ORM_ModelsManager, get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_modelsmanager___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, em, Lynx\\ORM\\EntityManager, 0)
	ZEND_ARG_INFO(0, cacheLoadType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_modelsmanager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_modelsmanager_method_entry) {
	PHP_ME(Lynx_ORM_ModelsManager, __construct, arginfo_lynx_orm_modelsmanager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_ORM_ModelsManager, get, arginfo_lynx_orm_modelsmanager_get, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
