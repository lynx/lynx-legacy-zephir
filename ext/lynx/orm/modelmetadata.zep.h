
extern zend_class_entry *lynx_orm_modelmetadata_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_ModelMetaData);

PHP_METHOD(Lynx_ORM_ModelMetaData, getClassname);
PHP_METHOD(Lynx_ORM_ModelMetaData, getTablename);
PHP_METHOD(Lynx_ORM_ModelMetaData, __construct);
PHP_METHOD(Lynx_ORM_ModelMetaData, getObject);
PHP_METHOD(Lynx_ORM_ModelMetaData, getProperties);
PHP_METHOD(Lynx_ORM_ModelMetaData, getProperty);
PHP_METHOD(Lynx_ORM_ModelMetaData, getPrimaryKey);
PHP_METHOD(Lynx_ORM_ModelMetaData, getPrimaryFieldName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_modelmetadata___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_modelmetadata_getproperty, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_modelmetadata_method_entry) {
	PHP_ME(Lynx_ORM_ModelMetaData, getClassname, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_ModelMetaData, getTablename, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_ModelMetaData, __construct, arginfo_lynx_orm_modelmetadata___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_ORM_ModelMetaData, getObject, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_ModelMetaData, getProperties, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_ModelMetaData, getProperty, arginfo_lynx_orm_modelmetadata_getproperty, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_ModelMetaData, getPrimaryKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_ModelMetaData, getPrimaryFieldName, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
