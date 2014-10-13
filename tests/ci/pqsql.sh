psql -c 'create database lynx_test;'
pg_dump -Fc lynx_test > ./tests/schemas/pqsql/lynx_test.sql