<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Model;

/**
 * @entity
 * @table(name="users")
 */
class User
{
    /**
     * @Id @Column(type="integer")
     */
    private $id;

    /**
     * @Column(length=50)
     */
    private $name;

    /**
     * @return mixed
     */
    public function getName()
    {
        return $this->name;
    }

    /**
     * @param mixed $name
     */
    public function setName($name)
    {
        $this->name = $name;
    }
} 