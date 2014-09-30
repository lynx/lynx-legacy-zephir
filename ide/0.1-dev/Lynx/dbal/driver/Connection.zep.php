<?php

namespace Lynx\DBAL\Driver;

abstract interface Connection
{


	public function commit();


	public function rollBack();


	public function beginTransaction();

    /**
     * @param mixed $eventsManager 
     */
	public function setEventsManager($eventsManager);

}
