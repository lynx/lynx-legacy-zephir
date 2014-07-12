PHP_ARG_ENABLE(lynx, whether to enable lynx, [ --enable-lynx   Enable Lynx])

if test "$PHP_LYNX" = "yes"; then
	AC_DEFINE(HAVE_LYNX, 1, [Whether you have Lynx])
	lynx_sources="lynx.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c lynx/annotation/reflectionclassparser.zep.c
	lynx/annotation/regexdocparser.zep.c
	lynx/cache/cachedriver.zep.c
	lynx/cache/driver.zep.c
	lynx/cache/memcache.zep.c
	lynx/cache/memcached.zep.c
	lynx/cache/nativearray.zep.c
	lynx/dbal/connection.zep.c
	lynx/dbal/driver/connection.zep.c
	lynx/dbal/driver/mysql.zep.c
	lynx/dbal/driver/pdo/statement.zep.c
	lynx/dbal/driver/pdo.zep.c
	lynx/dbal/events.zep.c
	lynx/orm/configuration.zep.c
	lynx/orm/entitymanager.zep.c
	lynx/orm/entityrepository.zep.c
	lynx/orm/exception.zep.c
	lynx/orm/modelmetadata.zep.c
	lynx/orm/modelsmanager.zep.c
	lynx/orm/query.zep.c
	lynx/orm/querybuilder.zep.c
	lynx/orm/queryidentitymap.zep.c
	lynx/orm/sqlbuilder.zep.c
	lynx/orm/unitofwork.zep.c
	lynx/stdlib/collections/arraycollection.zep.c
	lynx/stdlib/collections/collection.zep.c
	lynx/stdlib/events/event.zep.c
	lynx/stdlib/events/eventsmanager.zep.c
	lynx/stdlib/events/manager.zep.c
	lynx/stdlib/hydrator/classmethods.zep.c
	lynx/stdlib/hydrator/classproperties.zep.c
	lynx/stdlib/hydrator/entity.zep.c
	lynx/stdlib/hydrator/hydrator.zep.c "
	PHP_NEW_EXTENSION(lynx, $lynx_sources, $ext_shared)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([lynx], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([lynx], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS
fi
