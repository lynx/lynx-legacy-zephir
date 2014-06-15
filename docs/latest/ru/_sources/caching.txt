Кеширование
===========

Lynx поддерживает перечень адаптерев для кеша лежаших в Lynx\Cache.

Как использовать
----------------

Перед тем как начать использовать кеширование вам нужно установить драйвер в класс ``Configuration`` и передать в ``EntityManager``.

Пример:

.. code-block:: php

	use Lynx\ORM\Configuration;
	use Lynx\Cache\NativeArray;

	$configuration = new Configuration();
	$configuration->setCacheDriver(new NativeArray());

NativeArray
-----------

.. code-block:: php

	use Lynx\Cache\NativeArray;
	$configuration->setCacheDriver(new NativeArray());

Memcache
--------

.. code-block:: php

	use Lynx\Cache\NativeArray;
	$configuration->setCacheDriver(new Memcache());

Memcached
---------

.. code-block:: php

	use Lynx\Cache\NativeArray;
	$configuration->setCacheDriver(new Memcached());





