
extern zend_class_entry *lynx_orm_queryidentitymap_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_QueryIdentityMap);

PHP_METHOD(Lynx_ORM_QueryIdentityMap, getRootModel);
PHP_METHOD(Lynx_ORM_QueryIdentityMap, setRootModel);
PHP_METHOD(Lynx_ORM_QueryIdentityMap, getRootAlias);
PHP_METHOD(Lynx_ORM_QueryIdentityMap, setRootAlias);
PHP_METHOD(Lynx_ORM_QueryIdentityMap, getAliases);
PHP_METHOD(Lynx_ORM_QueryIdentityMap, setAliases);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_queryidentitymap_setrootmodel, 0, 0, 0)
	ZEND_ARG_INFO(0, rootModel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_queryidentitymap_setrootalias, 0, 0, 0)
	ZEND_ARG_INFO(0, rootAlias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_queryidentitymap_setaliases, 0, 0, 0)
	ZEND_ARG_INFO(0, aliases)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_queryidentitymap_method_entry) {
	PHP_ME(Lynx_ORM_QueryIdentityMap, getRootModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_QueryIdentityMap, setRootModel, arginfo_lynx_orm_queryidentitymap_setrootmodel, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_QueryIdentityMap, getRootAlias, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_QueryIdentityMap, setRootAlias, arginfo_lynx_orm_queryidentitymap_setrootalias, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_QueryIdentityMap, getAliases, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_QueryIdentityMap, setAliases, arginfo_lynx_orm_queryidentitymap_setaliases, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
