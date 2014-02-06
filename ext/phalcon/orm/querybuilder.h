
extern zend_class_entry *phalcon_orm_querybuilder_ce;

ZEPHIR_INIT_CLASS(Phalcon_ORM_QueryBuilder);

PHP_METHOD(Phalcon_ORM_QueryBuilder, getLimit);
PHP_METHOD(Phalcon_ORM_QueryBuilder, __construct);
PHP_METHOD(Phalcon_ORM_QueryBuilder, select);
PHP_METHOD(Phalcon_ORM_QueryBuilder, delete);
PHP_METHOD(Phalcon_ORM_QueryBuilder, update);
PHP_METHOD(Phalcon_ORM_QueryBuilder, from);
PHP_METHOD(Phalcon_ORM_QueryBuilder, leftJoin);
PHP_METHOD(Phalcon_ORM_QueryBuilder, limit);
PHP_METHOD(Phalcon_ORM_QueryBuilder, offset);
PHP_METHOD(Phalcon_ORM_QueryBuilder, getSQL);
PHP_METHOD(Phalcon_ORM_QueryBuilder, getQuery);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_orm_querybuilder___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, em)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_orm_querybuilder_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_orm_querybuilder_offset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_orm_querybuilder_method_entry) {
	PHP_ME(Phalcon_ORM_QueryBuilder, getLimit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_QueryBuilder, __construct, arginfo_phalcon_orm_querybuilder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ORM_QueryBuilder, select, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_QueryBuilder, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_QueryBuilder, update, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_QueryBuilder, from, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_QueryBuilder, leftJoin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_QueryBuilder, limit, arginfo_phalcon_orm_querybuilder_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_QueryBuilder, offset, arginfo_phalcon_orm_querybuilder_offset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_QueryBuilder, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ORM_QueryBuilder, getQuery, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
