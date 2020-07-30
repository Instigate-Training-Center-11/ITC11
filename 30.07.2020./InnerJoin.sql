DELIMITER $$

CREATE procedure jng(int i, int j) 
	BEGIN SELECT * from 
		customers inner join orders using(customer_id) 
		inner join order_lines using(ord_ID) 
		inner join products using(product_ID) WHERE customer_id = i, and product_ID = j; 
	END $$

DELIMITER;

call jng(2,3);

