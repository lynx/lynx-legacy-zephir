<?php
/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Tests\ORM;

class ModelMetaDataTest extends TestCase
{
    const MODEL_SCHEMA_COLUMN_CLASS = 'Lynx\ORM\ModelMetaData\Column';

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

        $result = $model->getPrimaryKey();
        $this->assertInstanceOf(self::MODEL_SCHEMA_COLUMN_CLASS, $result);
    }

    public function testGetPropertyByName()
    {
        $model = $this->getUserModel();

        $result = $model->getColumn('id');
        $this->assertInstanceOf(self::MODEL_SCHEMA_COLUMN_CLASS, $result);
    }
} 