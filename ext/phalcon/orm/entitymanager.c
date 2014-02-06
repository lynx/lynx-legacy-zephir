
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
#include "kernel/fcall.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Phalcon_ORM_EntityManager) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\ORM, EntityManager, phalcon, orm_entitymanager, phalcon_orm_entitymanager_method_entry, 0);

	zend_declare_property_null(phalcon_orm_entitymanager_ce, SL("unitOfWork"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_orm_entitymanager_ce, SL("connection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_ORM_EntityManager, getConnection) {


	RETURN_MEMBER(this_ptr, "connection");

}

PHP_METHOD(Phalcon_ORM_EntityManager, __construct) {

	zval *connection, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	zephir_update_property_this(this_ptr, SL("connection"), connection TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_orm_unitofwork_ce);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		zephir_call_method_p1_noret(_0, "__construct", this_ptr);
	}
	zephir_update_property_this(this_ptr, SL("unitOfWork"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_ORM_EntityManager, flush) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);




}

PHP_METHOD(Phalcon_ORM_EntityManager, createQueryBuilder) {

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_orm_querybuilder_ce);
	zephir_call_method_p1_noret(return_value, "__construct", this_ptr);
	RETURN_MM();

}

PHP_METHOD(Phalcon_ORM_EntityManager, createQuery) {

	zend_class_entry *_0;
	zval *sql;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sql);



	_0 = zend_fetch_class(SL("Phalcon\\ORM\\Query"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		zephir_call_method_p1_noret(return_value, "__construct", sql);
	}
	RETURN_MM();

}

