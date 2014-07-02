
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_ORM_UnitOfWork) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, UnitOfWork, lynx, orm_unitofwork, lynx_orm_unitofwork_method_entry, 0);

	/**
	 * @var EntityManager
	 */
	zend_declare_property_null(lynx_orm_unitofwork_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_unitofwork_ce, SL("insertEntities"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_unitofwork_ce, SL("updateEntities"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_unitofwork_ce, SL("deleteEntities"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_unitofwork_ce, SL("STATE_MANAGED"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(lynx_orm_unitofwork_ce, SL("STATE_NEW"), 2 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_UnitOfWork, __construct) {

	zval *em;

	zephir_fetch_params(0, 1, 0, &em);



	if (!(zephir_instance_of_ev(em, lynx_orm_entitymanager_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'em' must be an instance of 'Lynx\\ORM\\EntityManager'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_UnitOfWork, insert) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);

	if (unlikely(Z_TYPE_P(entity) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'entity' must be an object") TSRMLS_CC);
		RETURN_NULL();
	}



	zephir_update_property_array_append(this_ptr, SL("insertEntities"), entity TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_UnitOfWork, update) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);

	if (unlikely(Z_TYPE_P(entity) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'entity' must be an object") TSRMLS_CC);
		RETURN_NULL();
	}



	zephir_update_property_array_append(this_ptr, SL("updateEntities"), entity TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_UnitOfWork, delete) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);

	if (unlikely(Z_TYPE_P(entity) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'entity' must be an object") TSRMLS_CC);
		RETURN_NULL();
	}



	zephir_update_property_array_append(this_ptr, SL("deleteEntities"), entity TSRMLS_CC);

}

PHP_METHOD(Lynx_ORM_UnitOfWork, commit) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *entity = NULL, *model = NULL, *modelInfo = NULL, *_0, **_3, *_4, *_5 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &entity);

	if (!entity) {
		entity = ZEPHIR_GLOBAL(global_null);
	}



	/* try_start_1: */

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("insertEntities"), PH_NOISY_CC);
		zephir_is_iterable(_0, &_2, &_1, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(model, _3);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_5, _4, "getmodelsmanager",  NULL);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_INIT_NVAR(_6);
			zephir_get_class(_6, model, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&modelInfo, _5, "get", NULL, _6);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	zephir_update_property_this(this_ptr, SL("insertEntities"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("updateEntities"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("deleteEntities"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

