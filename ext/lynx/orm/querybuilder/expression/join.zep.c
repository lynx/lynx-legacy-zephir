
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Lynx_ORM_QueryBuilder_Expression_Join) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM\\QueryBuilder\\Expression, Join, lynx, orm_querybuilder_expression_join, lynx_orm_querybuilder_expression_join_method_entry, 0);

	zend_declare_property_null(lynx_orm_querybuilder_expression_join_ce, SL("type"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_expression_join_ce, SL("join"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_expression_join_ce, SL("alias"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(lynx_orm_querybuilder_expression_join_ce, SL("condition"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_join_ce, SL("RIGHT_JOIN"), "RIGHT" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_join_ce, SL("INNER_JOIN"), "INNER" TSRMLS_CC);

	zend_declare_class_constant_string(lynx_orm_querybuilder_expression_join_ce, SL("LEFT_JOIN"), "LEFT" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Join, __construct) {

	zval *type_param = NULL, *join, *alias, *condition = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &type_param, &join, &alias, &condition);

	zephir_get_strval(type, type_param);
	if (!condition) {
		condition = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("type"), type TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("join"), join TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("alias"), alias TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("condition"), condition TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_QueryBuilder_Expression_Join, __toString) {

	zval *_0, *_1, *_2, *_3, *_4, *_5 = NULL, *_6;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("type"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("join"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("alias"), PH_NOISY_CC);
	if (zephir_is_true(_3)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("alias"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(_2);
		ZEPHIR_CONCAT_SV(_2, " ", _4);
	} else {
		ZEPHIR_INIT_BNVAR(_2);
		ZVAL_STRING(_2, "", 1);
	}
	ZEPHIR_INIT_VAR(_5);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("condition"), PH_NOISY_CC);
	if (zephir_is_true(_6)) {
		ZEPHIR_OBS_NVAR(_5);
		zephir_read_property_this(&_5, this_ptr, SL("condition"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_BNVAR(_5);
		ZVAL_STRING(_5, "", 1);
	}
	ZEPHIR_CONCAT_VSVVSV(return_value, _0, " JOIN ", _1, _2, " ON ", _5);
	RETURN_MM();

}

