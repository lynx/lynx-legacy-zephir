<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\ORM;

class ModelMetaDataTest extends TestCase
{
    protected function getUserModel()
    {
        $modelsManager = $this->_em->getModelsManager();
        return $modelsManager->get('Model\User');
    }

    public function testGetTablename()
    {
        $userModel = $this->getUserModel();
        $this->assertEquals("users", $userModel->getTablename());
    }

    public function testGetPrimaryKey()
    {
        $model = $this->getUserModel();

        $result = $model->getPrimaryKey('id');
        $this->assertInternalType('array', $result);
    }

    public function testGetPropertyByName()
    {
        $model = $this->getUserModel();

        $result = $model->getProperty('id');
        $this->assertInternalType('array', $result);
    }
} 