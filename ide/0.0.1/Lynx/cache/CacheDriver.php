<?php

namespace Lynx\Cache;

abstract class CacheDriver
{

	abstract public function save();

	abstract public function delete();

	abstract public function get();

	abstract public function exists();

}
