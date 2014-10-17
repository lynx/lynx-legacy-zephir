psql -c 'create database lynx_test;' -U postgres
pg_dump -Fc lynx_test > ./tests/schemas/pqsql/lynx_test.sql -U postgres