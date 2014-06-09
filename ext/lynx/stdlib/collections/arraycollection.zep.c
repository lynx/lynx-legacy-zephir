
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * @author: Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_Stdlib_Collections_ArrayCollection) {

	ZEPHIR_REGISTER_CLASS_EX(Lynx\\Stdlib\\Collections, ArrayCollection, lynx, stdlib_collections_arraycollection, lynx_stdlib_collections_collection_ce, lynx_stdlib_collections_arraycollection_method_entry, 0);

	zend_declare_property_null(lynx_stdlib_collections_arraycollection_ce, SL("elements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, getIterator) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zend_class_entry *_0;

	ZEPHIR_MM_GROW();

	_0 = zend_fetch_class(SL("ArrayIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Lynx_Stdlib_Collections_ArrayCollection, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("elements"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

