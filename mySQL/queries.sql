--- 1 ---
-- Which Products have been Ordered by a Customer
-- 1 must be any number, witch exists customerID in table
select * from orders where customerID = 1;


--- 2 ---
-- What date/time was a particular Order dispatched
-- orderId must be number, witch exists in table
select time, orderID from orders where orderID = 25;


--- 3 ---
-- How many open Orders do we have in the system
---- Get all orders for all customers
select COUNT(*) as `orders count` from orders;
---- Get orders for every customer
select customerID, COUNT(*) from orders group by customerID;


--- 4 ---
-- How many of a certain Product do we have in stock
select count(*) from products where count <> 0;


--- 5 ---
-- Which Supplier supplies a particular Product
-- I haven't a column in products where written supplierID
-- So I must do this.
ALTER TABLE products ADD COLUMN (supplierID integer not default 1);
ALTER TABLE products ADD FOREIGN KEY(supplierID) References suppliers(supplierID);

-- Now I can do this task
select name, supplierID from products;


--- 6 ---
-- What is the Total Order cost for a certain Order
-- 1 must be any number witch exists in orders table orderID
SELECT sum(orderLines.count * products.price) AS cost FROM orderLines
JOIN products ON orderLines.productID = products.productID WHERE orderID = "1";