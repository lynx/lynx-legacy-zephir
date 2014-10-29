Repository
==========

You can get Entity Repository from em by using:

.. code-block:: php

    $repository = $this->get('em')->getRepository('User');

Find by primary key
```````````````````

You can find first row by primary key:

.. code-block:: php

    $id = 12345;

    $repository = $this->get('em')->getRepository('User');
    $result = $repository->find($id);


Find all
````````

You can find all entities:

.. code-block:: php

    $repository = $this->get('em')->getRepository('User');

    /**
     * @var $result \Lynx\Stdlib\Collections\ArrayCollection|bool
     */
    $result = $repository->findAll();

Count
`````

You can count all rows:

.. code-block:: php

    $repository = $this->get('em')->getRepository('User');

    /**
     * @var $count integer
     */
    $count = $repository->count();