
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


/**
 * @author: Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_Stdlib_Collections_Collection) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Stdlib\\Collections, Collection, lynx, stdlib_collections_collection, lynx_stdlib_collections_collection_method_entry, 0);

	zend_class_implements(lynx_stdlib_collections_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(lynx_stdlib_collections_collection_ce TSRMLS_CC, 1, zend_ce_aggregate);
	return SUCCESS;

}

/**
 * Get elements count from collection
 */
PHP_METHOD(Lynx_Stdlib_Collections_Collection, count) {

}

/**
 * Get iterator
 */
PHP_METHOD(Lynx_Stdlib_Collections_Collection, getIterator) {

}

/**
 * Execute fuction to each element in the collection
 */
PHP_METHOD(Lynx_Stdlib_Collections_Collection, map) {

}

/**
 * Execute fuction to each element in the collection and
 * remove element from collection if executed function return false
 */
PHP_METHOD(Lynx_Stdlib_Collections_Collection, filter) {

}

/**
 * Set current element to the first element and return it
 */
PHP_METHOD(Lynx_Stdlib_Collections_Collection, first) {

}

/**
 * Set current element to the last element and return it
 */
PHP_METHOD(Lynx_Stdlib_Collections_Collection, last) {

}

/**
 * Add element to collection
 */
PHP_METHOD(Lynx_Stdlib_Collections_Collection, add) {

}

