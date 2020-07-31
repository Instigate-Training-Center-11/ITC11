-- MySQL dump 10.13  Distrib 5.7.30, for Linux (x86_64)
--
-- Host: localhost    Database: EP
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
-- Table structure for table `Departments`
--

DROP TABLE IF EXISTS `Departments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Departments` (
  `depID` int(11) NOT NULL AUTO_INCREMENT,
  `depName` varchar(30) DEFAULT NULL,
  `depDescription` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`depID`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Departments`
--

LOCK TABLES `Departments` WRITE;
/*!40000 ALTER TABLE `Departments` DISABLE KEYS */;
INSERT INTO `Departments` VALUES (1,'dep1',NULL),(2,'dep2',NULL),(3,'dep3',NULL),(4,'dep4',NULL),(5,'dep5',NULL);
/*!40000 ALTER TABLE `Departments` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Employee-Projects`
--

DROP TABLE IF EXISTS `Employee-Projects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Employee-Projects` (
  `pID` int(10) unsigned NOT NULL,
  `empID` int(10) unsigned NOT NULL,
  `WorkDate` date NOT NULL,
  `WorkTime` int(10) unsigned NOT NULL,
  KEY `empID` (`empID`),
  KEY `pID` (`pID`),
  CONSTRAINT `Employee-Projects_ibfk_1` FOREIGN KEY (`empID`) REFERENCES `Employees` (`empID`),
  CONSTRAINT `Employee-Projects_ibfk_2` FOREIGN KEY (`pID`) REFERENCES `Projects` (`pID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Employee-Projects`
--

LOCK TABLES `Employee-Projects` WRITE;
/*!40000 ALTER TABLE `Employee-Projects` DISABLE KEYS */;
INSERT INTO `Employee-Projects` VALUES (1,2,'2020-01-11',10),(1,1,'2020-01-11',10),(1,4,'2020-01-11',10),(2,1,'2020-06-01',20),(2,4,'2020-06-01',20),(2,3,'2020-06-01',18),(3,2,'2020-07-01',12),(3,1,'2020-07-01',10),(4,2,'2020-03-01',22),(4,4,'2020-03-01',22),(5,1,'2020-04-01',15),(5,4,'2020-06-10',15);
/*!40000 ALTER TABLE `Employee-Projects` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Employees`
--

DROP TABLE IF EXISTS `Employees`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Employees` (
  `empID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `empName` varchar(30) NOT NULL,
  `empSurname` varchar(30) NOT NULL,
  `empDateOfBirth` date NOT NULL,
  `empPhoneNumber` int(11) NOT NULL,
  `empHireDate` date NOT NULL,
  `empPosition` varchar(30) DEFAULT NULL,
  `depID` int(10) unsigned NOT NULL,
  PRIMARY KEY (`empID`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Employees`
--

LOCK TABLES `Employees` WRITE;
/*!40000 ALTER TABLE `Employees` DISABLE KEYS */;
INSERT INTO `Employees` VALUES (1,'name1','surname1','1995-12-09',98989898,'2020-02-01',NULL,1),(2,'name2','surname2','1995-10-01',91111111,'2020-02-01',NULL,2),(3,'name3','surname3','1996-11-11',91111112,'2020-03-01',NULL,3),(4,'name4','surname4','1994-01-10',91222222,'2020-03-01',NULL,4);
/*!40000 ALTER TABLE `Employees` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Projects`
--

DROP TABLE IF EXISTS `Projects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Projects` (
  `pID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Title` varchar(50) NOT NULL,
  `Description` varchar(100) DEFAULT NULL,
  `StartDate` date DEFAULT NULL,
  `isActive` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`pID`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Projects`
--

LOCK TABLES `Projects` WRITE;
/*!40000 ALTER TABLE `Projects` DISABLE KEYS */;
INSERT INTO `Projects` VALUES (1,'T1',NULL,'2020-01-10',0),(2,'T2',NULL,'2020-06-01',1),(3,'T3',NULL,'2020-07-01',1),(4,'T4',NULL,'2020-03-01',0),(5,'T5',NULL,'2020-04-01',0),(6,'T5',NULL,'2020-06-10',1);
/*!40000 ALTER TABLE `Projects` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-07-31 10:56:07
