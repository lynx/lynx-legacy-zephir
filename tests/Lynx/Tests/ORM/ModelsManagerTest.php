<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\ORM;

use Lynx\ORM,
    Lynx\DBAL;

class ModalsManagerTest
	extends TestCase
{
	public function testCreateQueryBuilder()
	{
		$modalsManager = $this->_em->getModelsManager();
		$modalMetaData = $modalsManager->get('Model\User');
		var_dump($modalMetaData->getProperty('id'));
	}
}