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
	public function testGetModel()
	{
		$modelsManager = $this->_em->getModelsManager();
		$result = $modelsManager->get('Model\User');

        $this->assertInstanceOf('Lynx\\ORM\\ModelMetaData', $result);
	}
}