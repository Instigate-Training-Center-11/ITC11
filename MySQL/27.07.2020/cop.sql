-- MySQL dump 10.13  Distrib 5.7.30, for Linux (x86_64)
--
-- Host: localhost    Database: cop
-- ------------------------------------------------------
-- Server version	5.7.30-0ubuntu0.16.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
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
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customers` (
  `c_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `c_name` varchar(30) NOT NULL,
  `c_surname` varchar(30) NOT NULL,
  `c_phone_number` varchar(30) NOT NULL,
  `c_street` varchar(30) NOT NULL,
  `c_city` varchar(30) NOT NULL,
  `c_country` varchar(30) NOT NULL,
  `c_address_post_code` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`c_id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customers`
--

LOCK TABLES `customers` WRITE;
/*!40000 ALTER TABLE `customers` DISABLE KEYS */;
INSERT INTO `customers` VALUES (1,'Anna','Hakobyan','098090987','Isahakyan 17','Vanadzor','RA','2004'),(2,'Mane','Grigoryan','099878789','Tumnayan 11','Gyumri','RA','3002'),(3,'Arpi','Matosyan','098123212','Nersisyan 14','Vanadzor','RA','2005'),(4,'Aram','Petrosyan','098098988','Myasnikyan 18','Vanadzor','RA',NULL),(5,'Nare','Hovhannisyan','077987678','Tigran Mets 64','Vanadzor','RA',NULL),(6,'Hayk','Asatryan','098100987','Kievyan 17','Yerevan','RA',NULL),(7,'Mary','Melikyan','099009900','Leningradyan 43','Yerevan','RA',NULL);
/*!40000 ALTER TABLE `customers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orderLines`
--

DROP TABLE IF EXISTS `orderLines`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orderLines` (
  `o_id` int(10) unsigned NOT NULL,
  `p_id` int(10) unsigned NOT NULL,
  `p_quantity` int(11) NOT NULL,
  KEY `o_id` (`o_id`),
  KEY `p_id` (`p_id`),
  CONSTRAINT `ordeLines_ibfk_2` FOREIGN KEY (`p_id`) REFERENCES `products` (`p_id`),
  CONSTRAINT `orderLines_ibfk_1` FOREIGN KEY (`o_id`) REFERENCES `orders` (`o_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orderLines`
--

LOCK TABLES `orderLines` WRITE;
/*!40000 ALTER TABLE `orderLines` DISABLE KEYS */;
INSERT INTO `orderLines` VALUES (1,2,1),(1,8,2),(2,2,2),(2,11,1),(1,11,1),(3,1,4),(3,10,2),(3,11,1),(4,4,4),(4,9,3),(5,2,1),(5,12,1),(6,12,1),(7,1,2),(7,6,3),(7,10,3),(7,11,1),(8,12,1),(8,4,1),(9,3,1),(9,8,2);
/*!40000 ALTER TABLE `orderLines` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orders` (
  `o_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `c_id` int(10) unsigned DEFAULT NULL,
  `o_placed_time` datetime NOT NULL,
  `o_completed` tinyint(1) DEFAULT '0',
  `o_delivery_time` datetime DEFAULT NULL,
  PRIMARY KEY (`o_id`),
  KEY `c_id` (`c_id`),
  CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`c_id`) REFERENCES `customers` (`c_id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES (1,1,'2020-07-22 13:10:00',1,'2020-07-22 17:10:00'),(2,3,'2020-07-28 15:15:00',1,'2020-07-28 18:00:00'),(3,2,'2020-07-30 17:10:00',0,NULL),(4,6,'2020-07-29 16:00:00',1,'2020-07-30 11:00:00'),(5,7,'2020-07-30 12:00:00',1,'2020-07-30 17:30:00'),(6,4,'2020-07-29 12:00:00',1,'2020-07-29 18:30:00'),(7,1,'2020-07-30 12:00:00',0,NULL),(8,3,'2020-07-30 19:00:00',0,NULL),(9,5,'2020-07-30 18:30:00',0,NULL);
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `products`
--

DROP TABLE IF EXISTS `products`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `products` (
  `p_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `p_name` varchar(30) NOT NULL,
  `p_brand` varchar(30) DEFAULT NULL,
  `s_id` int(10) unsigned DEFAULT NULL,
  `quantity_in_stock` int(10) unsigned DEFAULT NULL,
  `p_unit_purchace_price` decimal(10,5) NOT NULL,
  `p_unit_sale_price` decimal(10,5) NOT NULL,
  PRIMARY KEY (`p_id`),
  KEY `s_id` (`s_id`),
  CONSTRAINT `products_ibfk_1` FOREIGN KEY (`s_id`) REFERENCES `suppliers` (`s_id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `products`
--

LOCK TABLES `products` WRITE;
/*!40000 ALTER TABLE `products` DISABLE KEYS */;
INSERT INTO `products` VALUES (1,'Champagne','Ijevan-Haghartsin',1,15,2000.00000,2190.00000),(2,'Champagne','Moet & Chandon Nectar Impéria',2,10,30000.00000,34800.00000),(3,'Champagne','Moët & Chandon Ice Impérial',2,10,32000.00000,38900.00000),(4,'Champagne','Moët & Chandon Ice Impérial',2,22,31000.00000,34500.00000),(6,'Wine','Villa Antinori',3,30,4000.00000,4900.00000),(7,'Wine','Armenia',4,40,1500.00000,1870.00000),(8,'Wine','Takar',4,38,1800.00000,2200.00000),(9,'Wine','Tariri',4,23,2000.00000,2700.00000),(10,'Wine','Ijevan',1,20,2000.00000,2570.00000),(11,'Cognac','Hennessy VSOP',5,18,50000.00000,56700.00000),(12,'Cognac','Hennessy XO',5,18,90000.00000,99000.00000);
/*!40000 ALTER TABLE `products` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `suppliers`
--

DROP TABLE IF EXISTS `suppliers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `suppliers` (
  `s_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `s_name` varchar(30) NOT NULL,
  `s_phone_number` varchar(30) NOT NULL,
  `s_fax_number` varchar(30) NOT NULL,
  `s_email` varchar(30) NOT NULL,
  `s_credit_card` varchar(30) NOT NULL,
  `s_street` varchar(30) NOT NULL,
  `s_city` varchar(30) NOT NULL,
  `s_country` varchar(30) NOT NULL,
  `s_address_post_code` int(11) NOT NULL,
  PRIMARY KEY (`s_id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `suppliers`
--

LOCK TABLES `suppliers` WRITE;
/*!40000 ALTER TABLE `suppliers` DISABLE KEYS */;
INSERT INTO `suppliers` VALUES (1,'Ijevan Wine-Brandy Factory','+374 11 99 91 91','+374 11 99 91 91',' info@ijevangroup.com','231212456723','Yerevanyan 9','Ijevan','RA',4001),(2,'Champagne Moet & Chandon','+33 (0)3 26 51 20 20','+33 (0)3 26 51 20 20',' www.moet.com','231212456723','20, avenue de Champagne','Erenay','France',51333),(3,'Marchesi Antinori','+39 055 265 4585','+39 055 265 4585','www.antinori.it','12123498789065','Piazza degli Antinori','Firenze FI','Italy',50123),(4,'Armenia Wine','044 802222','044 802222','www.armeniawine.amt','12123498789065','3 Bild., 1Dead-end, 30 Street','Sasunik','Armenia',2020),(5,'Jas Hennessy & Cie Sa','33-5-45-35-72-72','33-5-45-35-72-72','www.hennessy.com','12123498788755','1 RUE DE LA RICHONNE COGNAC','CHATEAUBERNARD','France',9461477);
/*!40000 ALTER TABLE `suppliers` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-08-01  1:49:11
