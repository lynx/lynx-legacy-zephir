
extern zend_class_entry *lynx_orm_queryidentitymap_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_QueryIdentityMap);

PHP_METHOD(Lynx_ORM_QueryIdentityMap, getRootAlias);
PHP_METHOD(Lynx_ORM_QueryIdentityMap, getAliases);

ZEPHIR_INIT_FUNCS(lynx_orm_queryidentitymap_method_entry) {
	PHP_ME(Lynx_ORM_QueryIdentityMap, getRootAlias, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_QueryIdentityMap, getAliases, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
