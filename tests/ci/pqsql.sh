psql -U postgres -c 'create database lynx_test;'
psql -U postgres -d lynx_test -f tests/schemas/pqsql/lynx_test.sql
