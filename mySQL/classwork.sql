--- Query for join with procedure ---
delimiter //

CREATE PROCEDURE myProc(one in integer, two in integer)
BEGIN
SELECT * FROM customers INNER JOIN orders using(customerID)
INNER JOIN orderLines using(orderID)
INNER JOIN products using(productID) WHERE customerID = one and productID = two;
END//
delimiter ;

call myProc(1, 2);


--- Trigger to update date when updating isDev column ---
delimiter //

CREATE TRIGGER myTrigger AFTER UPDATE ON orderLines
FOR EACH ROW
BEGIN
IF new.isDev = 1 THEN
update orders set orders.time = NOW() where orders.orderID = new.orderID;
END IF;
END //

delimiter ;