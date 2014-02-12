
extern zend_class_entry *phalcon_orm_unitofwork_ce;

ZEPHIR_INIT_CLASS(Phalcon_ORM_UnitOfWork);

PHP_METHOD(Phalcon_ORM_UnitOfWork, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_orm_unitofwork___construct, 0, 0, 1)
  ZEND_ARG_INFO(0, em)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_orm_unitofwork_method_entry) {
	PHP_ME(Phalcon_ORM_UnitOfWork, __construct, arginfo_phalcon_orm_unitofwork___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
