
extern zend_class_entry *lynx_stdlib_hydrator_entity_ce;

ZEPHIR_INIT_CLASS(Lynx_Stdlib_Hydrator_Entity);

PHP_METHOD(Lynx_Stdlib_Hydrator_Entity, hydrate);
PHP_METHOD(Lynx_Stdlib_Hydrator_Entity, extract);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_hydrator_entity_hydrate, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, currentObject)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_hydrator_entity_extract, 0, 0, 1)
	ZEND_ARG_INFO(0, currentObject)
	ZEND_ARG_INFO(0, modelInfo)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_stdlib_hydrator_entity_method_entry) {
	PHP_ME(Lynx_Stdlib_Hydrator_Entity, hydrate, arginfo_lynx_stdlib_hydrator_entity_hydrate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Lynx_Stdlib_Hydrator_Entity, extract, arginfo_lynx_stdlib_hydrator_entity_extract, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
