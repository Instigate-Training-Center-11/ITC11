set @count = 1;
set @sum = 0;
delimiter

CREATE TRIGGER myTrigger BEFORE INSERT ON customers
FOR EACH ROW
BEGIN
IF @count >= 3 THEN
SET @count = 1,
@sum = @sum + new.customerID;
ELSE
SET @count = @count + 1;
END IF;
END;

delimiter ;
