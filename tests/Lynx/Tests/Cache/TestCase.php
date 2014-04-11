<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\Cache;

abstract class TestCase
    extends \PHPUnit_Framework_TestCase
{
    /**
     * @var \Lynx\Cache\CacheDriver
     */
    protected $cacheDriver;

    abstract protected function initCacheDriver();

    public function setUp()
    {
        $this->cacheDriver = $this->initCacheDriver();
    }

    public function testSuccessAdapter()
    {
        $key = 'testkey';

        $this->cacheDriver->save($key, array());
        $this->assertEquals(array(), $this->cacheDriver->get($key));

        $this->assertTrue(  $this->cacheDriver->exists($key));
        $this->cacheDriver->delete('testkey');
        $this->assertFalse($this->cacheDriver->exists($key));
    }
} 