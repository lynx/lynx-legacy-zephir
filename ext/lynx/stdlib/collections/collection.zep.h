
extern zend_class_entry *lynx_stdlib_collections_collection_ce;

ZEPHIR_INIT_CLASS(Lynx_Stdlib_Collections_Collection);

PHP_METHOD(Lynx_Stdlib_Collections_Collection, count);
PHP_METHOD(Lynx_Stdlib_Collections_Collection, getIterator);
PHP_METHOD(Lynx_Stdlib_Collections_Collection, map);
PHP_METHOD(Lynx_Stdlib_Collections_Collection, filter);
PHP_METHOD(Lynx_Stdlib_Collections_Collection, first);
PHP_METHOD(Lynx_Stdlib_Collections_Collection, last);
PHP_METHOD(Lynx_Stdlib_Collections_Collection, add);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_collections_collection_map, 0, 0, 1)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_collections_collection_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_collections_collection_add, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_stdlib_collections_collection_method_entry) {
	PHP_ME(Lynx_Stdlib_Collections_Collection, count, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Collections_Collection, getIterator, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Collections_Collection, map, arginfo_lynx_stdlib_collections_collection_map, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Collections_Collection, filter, arginfo_lynx_stdlib_collections_collection_filter, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Collections_Collection, first, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Collections_Collection, last, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Collections_Collection, add, arginfo_lynx_stdlib_collections_collection_add, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
