
extern zend_class_entry *lynx_stdlib_collections_arraycollection_ce;

ZEPHIR_INIT_CLASS(Lynx_Stdlib_Collections_ArrayCollection);

PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, getIterator);
PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, count);

ZEPHIR_INIT_FUNCS(lynx_stdlib_collections_arraycollection_method_entry) {
	PHP_ME(Lynx_Stdlib_Collections_ArrayCollection, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Collections_ArrayCollection, count, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
