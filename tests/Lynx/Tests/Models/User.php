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
     * @Id
     * @column(type="integer", length=11, name="id")
     */
    public $id;

    /**
     * @column(name="date_created", type="date")
     */
    public $dateCreated;

    /**
     * @column(length=50, , name="name")
     */
    public $name;

    /**
     * @column(type="integer", length=11, name="group_id")
     */
    public $group_id;

    /**
     * @OneToOne(targetEntity="Model\Group")
     * @JoinColumn(name="group_id", referencedColumnName="id")
     */
    public $Group;
} 