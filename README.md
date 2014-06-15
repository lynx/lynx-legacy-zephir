Lynx ORM|DBAL
=============
[![Build Status](https://travis-ci.org/lynx/lynx.svg)](https://travis-ci.org/lynx/lynx)
[![License](https://poser.pugx.org/lynx/lynx/license.svg)](https://packagist.org/packages/lynx/lynx)

### Current development status

In development (not work). 2 month to version 0.0.1 (ALPHA)

### Why it would be need?

I like Doctrine2 but i dislike Phalcon 2 ORM* and create this project for incubate new ORM on Zephir Language for best performance.

### Idea

* Every day push >= 1 commit
* Write ORM|DBAL and sublibs with max functions support
* Performance tune (will start do it after beta release)

### Why it would be great?

* Small but support all
* Speed (because build on c with zephir)

### On What ideas it would based

* Annotation
	* RefelecationClassParser
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
	* EventManager (ported from phalcon)
	* Hydrators (will be soon)

### SYSTEM REQUIREMENTS

To build the PHP extension:

* g++ >= 4.4/clang++ >= 3.x/vc++ 9
* gnu make 3.81 or later
* php development headers and tools

To build the zep Source to c extension:

* [zephir](https://github.com/phalcon/zephir)

License
-------
This project is open-sourced software licensed under the MIT License. See the LICENSE file for more information.