
extern zend_class_entry *lynx_dbal_rawvalue_ce;

ZEPHIR_INIT_CLASS(Lynx_DBAL_RawValue);

PHP_METHOD(Lynx_DBAL_RawValue, getValue);
PHP_METHOD(Lynx_DBAL_RawValue, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_dbal_rawvalue___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_dbal_rawvalue_method_entry) {
	PHP_ME(Lynx_DBAL_RawValue, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_DBAL_RawValue, __construct, arginfo_lynx_dbal_rawvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
