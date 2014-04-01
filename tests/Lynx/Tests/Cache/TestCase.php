<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\Cache;

class TestCase
    extends \PHPUnit_Framework_TestCase
{
    /**
     * @var \Lynx\Cache\CacheDriver
     */
    protected $cacheDriver;

    public function setUp()
    {
        $this->cacheDriver = new \Lynx\Cache\Memcache();
    }

    public function testSuccessSetGet()
    {
        $this->cacheDriver->save('testkey', array());
        $this->assertEquals(array(), $this->cacheDriver->get('testkey'));
    }
} 