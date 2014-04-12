<?php

/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Model;

/**
 * @entity
 * @table(name="products")
 */
class Product
{
    /**
     * @Id @Column(type="integer")
     */
    private $id;

    /**
     * @Column(length=50)
     */
    private $title;

    /**
     * @return mixed
     */
    public function getTitle()
    {
        return $this->title;
    }

    /**
     * @param mixed $title
     */
    public function setTitle($title)
    {
        $this->title = $title;
    }
} 