
extern zend_class_entry *lynx_orm_unitofwork_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_UnitOfWork);

PHP_METHOD(Lynx_ORM_UnitOfWork, __construct);
PHP_METHOD(Lynx_ORM_UnitOfWork, insert);
PHP_METHOD(Lynx_ORM_UnitOfWork, update);
PHP_METHOD(Lynx_ORM_UnitOfWork, delete);
PHP_METHOD(Lynx_ORM_UnitOfWork, convertToScalar);
PHP_METHOD(Lynx_ORM_UnitOfWork, commit);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_unitofwork___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, em, Lynx\\ORM\\EntityManager, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_unitofwork_insert, 0, 0, 1)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_unitofwork_update, 0, 0, 1)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_unitofwork_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_unitofwork_converttoscalar, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, columnType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_unitofwork_commit, 0, 0, 0)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_unitofwork_method_entry) {
	PHP_ME(Lynx_ORM_UnitOfWork, __construct, arginfo_lynx_orm_unitofwork___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_ORM_UnitOfWork, insert, arginfo_lynx_orm_unitofwork_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_UnitOfWork, update, arginfo_lynx_orm_unitofwork_update, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_UnitOfWork, delete, arginfo_lynx_orm_unitofwork_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_UnitOfWork, convertToScalar, arginfo_lynx_orm_unitofwork_converttoscalar, ZEND_ACC_PROTECTED)
	PHP_ME(Lynx_ORM_UnitOfWork, commit, arginfo_lynx_orm_unitofwork_commit, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
