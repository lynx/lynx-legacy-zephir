
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
#include "kernel/fcall.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_ORM_EntityRepository) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, EntityRepository, lynx, orm_entityrepository, lynx_orm_entityrepository_method_entry, 0);

	/**
	 * @var EntityManager
	 */
	zend_declare_property_null(lynx_orm_entityrepository_ce, SL("em"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_EntityRepository, __construct) {

	zval *em;

	zephir_fetch_params(0, 1, 0, &em);



	if (!(zephir_instance_of_ev(em, lynx_orm_entitymanager_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'em' must be an instance of 'Lynx\\ORM\\EntityManager'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("em"), em TSRMLS_CC);

}

/**
 * @todo set alias to QueryBuilder
 * @return QueryBuilder
 */
PHP_METHOD(Lynx_ORM_EntityRepository, createQueryBuilder) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("em"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "createquerybuilder", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Lynx_ORM_EntityRepository, find) {

	zval *id;

	zephir_fetch_params(0, 1, 0, &id);




}

PHP_METHOD(Lynx_ORM_EntityRepository, findAll) {



}

PHP_METHOD(Lynx_ORM_EntityRepository, findBy) {



}

PHP_METHOD(Lynx_ORM_EntityRepository, findOneBy) {



}

