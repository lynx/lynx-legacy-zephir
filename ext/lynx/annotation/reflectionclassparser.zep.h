
extern zend_class_entry *lynx_annotation_reflectionclassparser_ce;

ZEPHIR_INIT_CLASS(Lynx_Annotation_ReflectionClassParser);

PHP_METHOD(Lynx_Annotation_ReflectionClassParser, __construct);
PHP_METHOD(Lynx_Annotation_ReflectionClassParser, getClassAnnotations);
PHP_METHOD(Lynx_Annotation_ReflectionClassParser, getPropertiesAnnotations);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_annotation_reflectionclassparser___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, parameter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_annotation_reflectionclassparser_method_entry) {
	PHP_ME(Lynx_Annotation_ReflectionClassParser, __construct, arginfo_lynx_annotation_reflectionclassparser___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_Annotation_ReflectionClassParser, getClassAnnotations, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Annotation_ReflectionClassParser, getPropertiesAnnotations, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
