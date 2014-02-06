
extern zend_class_entry *phalcon_orm_query_ce;

ZEPHIR_INIT_CLASS(Phalcon_ORM_Query);

PHP_METHOD(Phalcon_ORM_Query, __construct);
PHP_METHOD(Phalcon_ORM_Query, fetchArray);
PHP_METHOD(Phalcon_ORM_Query, fetchAll);
PHP_METHOD(Phalcon_ORM_Query, fetchObject);
PHP_METHOD(Phalcon_ORM_Query, fetchOne);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_orm_query___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, em)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_orm_query_fetcharray, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_orm_query_fetchall, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_orm_query_fetchobject, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_orm_query_fetchone, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_orm_query_method_entry) {
	PHP_ME(Phalcon_ORM_Query, __construct, arginfo_phalcon_orm_query___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ORM_Query, fetchArray, arginfo_phalcon_orm_query_fetcharray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_Query, fetchAll, arginfo_phalcon_orm_query_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_Query, fetchObject, arginfo_phalcon_orm_query_fetchobject, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_Query, fetchOne, arginfo_phalcon_orm_query_fetchone, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
