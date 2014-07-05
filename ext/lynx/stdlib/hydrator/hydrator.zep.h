
extern zend_class_entry *lynx_stdlib_hydrator_hydrator_ce;

ZEPHIR_INIT_CLASS(Lynx_Stdlib_Hydrator_Hydrator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_hydrator_hydrator_hydrate, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, currentObject)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_hydrator_hydrator_extract, 0, 0, 1)
	ZEND_ARG_INFO(0, currentObject)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_stdlib_hydrator_hydrator_method_entry) {
	ZEND_FENTRY(hydrate, NULL, arginfo_lynx_stdlib_hydrator_hydrator_hydrate, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(extract, NULL, arginfo_lynx_stdlib_hydrator_hydrator_extract, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
