<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\Cache;

class NativeArrayTest
    extends TestCase
{
	protected function initCacheDriver()
	{
		$driver = new \Lynx\Cache\NativeArray();
		return $driver;
	}
} 