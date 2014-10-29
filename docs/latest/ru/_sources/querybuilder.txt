QueryBuilder
============

You can create new QueryBuilder:

.. code-block:: php

    $queryBuilder = $this->get('em')->createQueryBuilder();


Or create QueryBuilder from Repository object:

.. code-block:: php

    $repository = $this->get('em')->getRepository('User');
    $userQueryBuilder = $repository->createQueryBuilder();

Limit and Offset
~~~~~~~~~~~~~~~~

You can specify limit or offset to the query by using:

.. code-block:: php

    $queryBuilder->limit(100)
        ->offset(50);
