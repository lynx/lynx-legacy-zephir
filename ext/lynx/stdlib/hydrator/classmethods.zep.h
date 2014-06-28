
extern zend_class_entry *lynx_stdlib_hydrator_classmethods_ce;

ZEPHIR_INIT_CLASS(Lynx_Stdlib_Hydrator_ClassMethods);

PHP_METHOD(Lynx_Stdlib_Hydrator_ClassMethods, hydrate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_hydrator_classmethods_hydrate, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, currentObject)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_stdlib_hydrator_classmethods_method_entry) {
	PHP_ME(Lynx_Stdlib_Hydrator_ClassMethods, hydrate, arginfo_lynx_stdlib_hydrator_classmethods_hydrate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
