-- Delete from table where exists primary key
-- Automaticaly delete every row where exists customer ID
CREATE TRIGGER deleteConnections AFTER DELETE ON customers
FOR EACH ROW
DELETE FROM orders WHERE customerID = old.customerID;

-- For deleting row from order
-- To fix allow error: " a foreign key constraint fails"

-- Turn off foregn key checking and delete row
CREATE TRIGGER deleteBefore BEFORE DELETE ON customers
FOR EACH ROW
SET foreign_key_checks = 0;

-- Turn on foregn key checking after deleting rows
CREATE TRIGGER deleteAfter AFTER DELETE ON customers
FOR EACH ROW
SET foreign_key_checks = 1;