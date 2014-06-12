
extern zend_class_entry *lynx_stdlib_events_eventsmanager_ce;

ZEPHIR_INIT_CLASS(Lynx_Stdlib_Events_EventsManager);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_events_eventsmanager_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_events_eventsmanager_dettachall, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_events_eventsmanager_fire, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_stdlib_events_eventsmanager_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_stdlib_events_eventsmanager_method_entry) {
	PHP_ABSTRACT_ME(Lynx_Stdlib_Events_EventsManager, attach, arginfo_lynx_stdlib_events_eventsmanager_attach)
	PHP_ABSTRACT_ME(Lynx_Stdlib_Events_EventsManager, dettachAll, arginfo_lynx_stdlib_events_eventsmanager_dettachall)
	PHP_ABSTRACT_ME(Lynx_Stdlib_Events_EventsManager, fire, arginfo_lynx_stdlib_events_eventsmanager_fire)
	PHP_ABSTRACT_ME(Lynx_Stdlib_Events_EventsManager, getListeners, arginfo_lynx_stdlib_events_eventsmanager_getlisteners)
  PHP_FE_END
};
