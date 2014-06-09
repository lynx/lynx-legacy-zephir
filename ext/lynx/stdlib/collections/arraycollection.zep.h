
extern zend_class_entry *lynx_stdlib_collections_arraycollection_ce;

ZEPHIR_INIT_CLASS(Lynx_Stdlib_Collections_ArrayCollection);

PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, __construct);
PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, add);
PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, getIterator);
PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, count);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_collections_arraycollection___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, elements)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_collections_arraycollection_add, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_stdlib_collections_arraycollection_method_entry) {
	PHP_ME(Lynx_Stdlib_Collections_ArrayCollection, __construct, arginfo_lynx_stdlib_collections_arraycollection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_Stdlib_Collections_ArrayCollection, add, arginfo_lynx_stdlib_collections_arraycollection_add, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Collections_ArrayCollection, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Collections_ArrayCollection, count, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
