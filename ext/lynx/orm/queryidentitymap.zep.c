
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_ORM_QueryIdentityMap) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, QueryIdentityMap, lynx, orm_queryidentitymap, lynx_orm_queryidentitymap_method_entry, 0);

	zend_declare_property_null(lynx_orm_queryidentitymap_ce, SL("rootAlias"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_queryidentitymap_ce, SL("aliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_QueryIdentityMap, getRootAlias) {


	RETURN_MEMBER(this_ptr, "rootAlias");

}

PHP_METHOD(Lynx_ORM_QueryIdentityMap, setRootAlias) {

	zval *rootAlias;

	zephir_fetch_params(0, 1, 0, &rootAlias);



	zephir_update_property_this(this_ptr, SL("rootAlias"), rootAlias TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_QueryIdentityMap, getAliases) {


	RETURN_MEMBER(this_ptr, "aliases");

}

PHP_METHOD(Lynx_ORM_QueryIdentityMap, setAliases) {

	zval *aliases;

	zephir_fetch_params(0, 1, 0, &aliases);



	zephir_update_property_this(this_ptr, SL("aliases"), aliases TSRMLS_CC);

}

