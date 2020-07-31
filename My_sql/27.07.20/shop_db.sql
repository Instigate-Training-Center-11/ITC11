-- MySQL dump 10.13  Distrib 8.0.21, for Linux (x86_64)
--
-- Host: localhost    Database: mydb
-- ------------------------------------------------------
-- Server version	8.0.21-0ubuntu0.20.04.3

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `customers`
--

DROP TABLE IF EXISTS `customers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customers` (
  `customer_ID` int unsigned NOT NULL AUTO_INCREMENT,
  `customer_name` varchar(45) DEFAULT NULL,
  `customer_surname` varchar(45) DEFAULT NULL,
  `customer_country` varchar(45) DEFAULT NULL,
  `customer_city` varchar(45) DEFAULT NULL,
  `customer_street` varchar(45) DEFAULT NULL,
  `customer_post_code` int unsigned DEFAULT NULL,
  `customer_phone_number` int DEFAULT NULL,
  PRIMARY KEY (`customer_ID`),
  UNIQUE KEY `customer_ID_UNIQUE` (`customer_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customers`
--

LOCK TABLES `customers` WRITE;
/*!40000 ALTER TABLE `customers` DISABLE KEYS */;
/*!40000 ALTER TABLE `customers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `order_lines`
--

DROP TABLE IF EXISTS `order_lines`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `order_lines` (
  `order_lines_ID` int unsigned NOT NULL AUTO_INCREMENT,
  `delivery_date` datetime DEFAULT NULL,
  `quantity` int unsigned DEFAULT NULL,
  `order_cost` int DEFAULT NULL,
  `products_product_ID` int unsigned NOT NULL,
  `orders_order_ID` int unsigned NOT NULL,
  PRIMARY KEY (`order_lines_ID`),
  UNIQUE KEY `order_lines_ID_UNIQUE` (`order_lines_ID`),
  KEY `fk_order_lines_products1_idx` (`products_product_ID`),
  KEY `fk_order_lines_orders1_idx` (`orders_order_ID`),
  CONSTRAINT `fk_order_lines_orders1` FOREIGN KEY (`orders_order_ID`) REFERENCES `orders` (`order_ID`),
  CONSTRAINT `fk_order_lines_products1` FOREIGN KEY (`products_product_ID`) REFERENCES `products` (`product_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `order_lines`
--

LOCK TABLES `order_lines` WRITE;
/*!40000 ALTER TABLE `order_lines` DISABLE KEYS */;
/*!40000 ALTER TABLE `order_lines` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `orders` (
  `order_ID` int unsigned NOT NULL AUTO_INCREMENT,
  `order_placed_date` date DEFAULT NULL,
  `order_placed_time` datetime DEFAULT NULL,
  `product_num` int DEFAULT NULL,
  `customers_customer_ID` int unsigned NOT NULL,
  PRIMARY KEY (`order_ID`),
  UNIQUE KEY `order_ID_UNIQUE` (`order_ID`),
  KEY `fk_orders_customers1_idx` (`customers_customer_ID`),
  CONSTRAINT `fk_orders_customers1` FOREIGN KEY (`customers_customer_ID`) REFERENCES `customers` (`customer_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `products`
--

DROP TABLE IF EXISTS `products`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `products` (
  `product_ID` int unsigned NOT NULL AUTO_INCREMENT,
  `product_name` varchar(20) DEFAULT NULL,
  `product_price` int DEFAULT NULL,
  `supplier_supplier_ID` int unsigned NOT NULL,
  PRIMARY KEY (`product_ID`),
  UNIQUE KEY `product_ID_UNIQUE` (`product_ID`),
  KEY `fk_products_supplier_idx` (`supplier_supplier_ID`),
  CONSTRAINT `fk_products_supplier` FOREIGN KEY (`supplier_supplier_ID`) REFERENCES `supplier` (`supplier_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `products`
--

LOCK TABLES `products` WRITE;
/*!40000 ALTER TABLE `products` DISABLE KEYS */;
/*!40000 ALTER TABLE `products` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `supplier`
--

DROP TABLE IF EXISTS `supplier`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `supplier` (
  `supplier_ID` int unsigned NOT NULL AUTO_INCREMENT,
  `supplier_name` varchar(45) DEFAULT NULL,
  `supplier_country` varchar(45) DEFAULT NULL,
  `supplier_city` varchar(45) DEFAULT NULL,
  `supplier_post_code` int unsigned DEFAULT NULL,
  PRIMARY KEY (`supplier_ID`),
  UNIQUE KEY `supplier_ID_UNIQUE` (`supplier_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `supplier`
--

LOCK TABLES `supplier` WRITE;
/*!40000 ALTER TABLE `supplier` DISABLE KEYS */;
/*!40000 ALTER TABLE `supplier` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `timestamps`
--

DROP TABLE IF EXISTS `timestamps`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `timestamps` (
  `create_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `update_time` timestamp NULL DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `timestamps`
--

LOCK TABLES `timestamps` WRITE;
/*!40000 ALTER TABLE `timestamps` DISABLE KEYS */;
/*!40000 ALTER TABLE `timestamps` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-07-31  4:24:12
