PHP_ARG_ENABLE(lynx, whether to enable lynx, [ --enable-lynx   Enable Lynx])

if test "$PHP_LYNX" = "yes"; then
	AC_DEFINE(HAVE_LYNX, 1, [Whether you have Lynx])
	lynx_sources="lynx.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c lynx/annotation/parser.c lynx/annotation/reflectionclassparser.c lynx/cache/cachedriver.c lynx/cache/memcache.c lynx/cache/memcached.c lynx/cache/nativearray.c lynx/dbal/connection.c lynx/dbal/driver/connection.c lynx/dbal/driver/pdo/statement.c lynx/dbal/driver/pdo.c lynx/orm/entitymanager.c lynx/orm/entityrepository.c lynx/orm/exception.c lynx/orm/query.c lynx/orm/querybuilder.c lynx/orm/sqlbuilder.c lynx/orm/unitofwork.c "
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
