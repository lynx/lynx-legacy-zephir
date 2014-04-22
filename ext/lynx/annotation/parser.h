
extern zend_class_entry *lynx_annotation_parser_ce;

ZEPHIR_INIT_CLASS(Lynx_Annotation_Parser);

PHP_METHOD(Lynx_Annotation_Parser, parseAnnotations);
PHP_METHOD(Lynx_Annotation_Parser, parseValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_annotation_parser_parseannotations, 0, 0, 1)
	ZEND_ARG_INFO(0, docComment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_annotation_parser_parsevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_annotation_parser_method_entry) {
	PHP_ME(Lynx_Annotation_Parser, parseAnnotations, arginfo_lynx_annotation_parser_parseannotations, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Lynx_Annotation_Parser, parseValue, arginfo_lynx_annotation_parser_parsevalue, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
  PHP_FE_END
};
