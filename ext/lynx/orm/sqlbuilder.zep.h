
extern zend_class_entry *lynx_orm_sqlbuilder_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_SqlBuilder);

PHP_METHOD(Lynx_ORM_SqlBuilder, getLimit);
PHP_METHOD(Lynx_ORM_SqlBuilder, __construct);
PHP_METHOD(Lynx_ORM_SqlBuilder, select);
PHP_METHOD(Lynx_ORM_SqlBuilder, delete);
PHP_METHOD(Lynx_ORM_SqlBuilder, update);
PHP_METHOD(Lynx_ORM_SqlBuilder, from);
PHP_METHOD(Lynx_ORM_SqlBuilder, leftJoin);
PHP_METHOD(Lynx_ORM_SqlBuilder, limit);
PHP_METHOD(Lynx_ORM_SqlBuilder, offset);
PHP_METHOD(Lynx_ORM_SqlBuilder, getSQL);
PHP_METHOD(Lynx_ORM_SqlBuilder, getQuery);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_sqlbuilder___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, em)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_sqlbuilder_limit, 0, 0, 0)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_sqlbuilder_offset, 0, 0, 0)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_sqlbuilder_method_entry) {
	PHP_ME(Lynx_ORM_SqlBuilder, getLimit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_SqlBuilder, __construct, arginfo_lynx_orm_sqlbuilder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_ORM_SqlBuilder, select, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_SqlBuilder, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_SqlBuilder, update, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_SqlBuilder, from, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_SqlBuilder, leftJoin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_SqlBuilder, limit, arginfo_lynx_orm_sqlbuilder_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_SqlBuilder, offset, arginfo_lynx_orm_sqlbuilder_offset, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_SqlBuilder, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_SqlBuilder, getQuery, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
