Lynx ORM|DBAL
=============
[![Latest Stable Version](https://poser.pugx.org/lynx/lynx/v/stable.svg)](https://packagist.org/packages/lynx/lynx)
[![Build Status](https://travis-ci.org/lynx/lynx.svg)](https://travis-ci.org/lynx/lynx)
[![License](https://poser.pugx.org/lynx/lynx/license.svg)](https://packagist.org/packages/lynx/lynx)

## [Documentation](./docs/readme.md) [[en](http://lynx.github.io/lynx/docs/latest/en/)|[ru](http://lynx.github.io/lynx/docs/latest/ru/)] ::  [Benchmark](https://github.com/lynx/benchmark)

<img align="right" height="180" src="http://dmtry.me/img/logos/lynx_bnw.svg">

> Yet another ORM\DBAL written in Zephir language.

I like Doctrine2 but I dislike Phalcon 2 ORM* and I've created this project to incubate a new ORM in Zephir Language to achieve the best performance.

### Idea

* Every day push >= 1 commit
* Write ORM|DBAL and sublibs with max functions support
* Performance tunning (will start doing it after beta release)

### Why it would be great?

* Small but support everything
* Speed (because it's built in C with Zephir)

### On What ideas it would be based

* Annotation
	* ReflectionClassParser
		* RegexDocParser
		* LineParser (will be soon)
	* PHPFileParser (will be soon)
		* RegexDocParser
		* LineParser (will be soon)
* ORM (Object relation mapper)
	* Hydration (Mapping)
    * EntityManager
    * UnitOfWork
    * QueryBuilder
* DBAL (Database abstraction layer)
* Cache (Cache drivers)
* StdLib
	* Collections
	* EventManager (ported from Phalcon)
	* Hydrators (will be soon)

### System Requirements

To build it you need the following requirements:

* g++ >= 4.4/clang++ >= 3.x/vc++ 9
* gnu make 3.81 or later
* autoconf 2.31 or later
* automake 1.14 or later
* PHP development headers and tools

If you're using Ubuntu, you can install the required packages this way:

```
sudo apt-get update
sudo apt-get install git gcc make re2c php5 php5-json php5-dev libpcre3-dev
```

### Installation

You can build extension and install it like:

```
git clone https://github.com/lynx/lynx.git
git submodule update --init
cd ext
./install
echo extension=lynx.so > /etc/php5/fpm/conf.d/lynx.ini
echo extension=lynx.so > /etc/php5/cli/conf.d/lynx.ini
```

Don't forget to restart your php-fpm:
```
sudo service php5-fpm restart
```

### Build Zephir code

To build the zep Source to C extension:
* [zephir](https://github.com/phalcon/zephir)

License
-------
This project is open-sourced software licensed under the MIT License. See the LICENSE file for more information.
