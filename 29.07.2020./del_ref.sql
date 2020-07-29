DELIMITER $$
CREATE TRIGGER usun ON test
FOR delete
as
BEGIN
    DELETE FROM table
    WHERE id_test in (select id_test from deleted.id_test);
END $$
DELIMITER;
