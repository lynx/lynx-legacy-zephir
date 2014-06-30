
extern zend_class_entry *lynx_stdlib_events_event_ce;

ZEPHIR_INIT_CLASS(Lynx_Stdlib_Events_Event);

PHP_METHOD(Lynx_Stdlib_Events_Event, setType);
PHP_METHOD(Lynx_Stdlib_Events_Event, getType);
PHP_METHOD(Lynx_Stdlib_Events_Event, getSource);
PHP_METHOD(Lynx_Stdlib_Events_Event, setData);
PHP_METHOD(Lynx_Stdlib_Events_Event, getData);
PHP_METHOD(Lynx_Stdlib_Events_Event, getCancelable);
PHP_METHOD(Lynx_Stdlib_Events_Event, __construct);
PHP_METHOD(Lynx_Stdlib_Events_Event, stop);
PHP_METHOD(Lynx_Stdlib_Events_Event, isStopped);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_events_event_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_events_event_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_events_event___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_stdlib_events_event_method_entry) {
	PHP_ME(Lynx_Stdlib_Events_Event, setType, arginfo_lynx_stdlib_events_event_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Events_Event, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Events_Event, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Events_Event, setData, arginfo_lynx_stdlib_events_event_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Events_Event, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Events_Event, getCancelable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Events_Event, __construct, arginfo_lynx_stdlib_events_event___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_Stdlib_Events_Event, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_Stdlib_Events_Event, isStopped, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
