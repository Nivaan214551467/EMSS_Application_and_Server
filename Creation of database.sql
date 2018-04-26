CREATE DATABASE `emss_database` /*!40100 DEFAULT CHARACTER SET utf8 */;

CREATE TABLE `admin` (
  `employee_id` int(10) unsigned NOT NULL,
  `pin` int(10) unsigned NOT NULL,
  `password` varchar(20) NOT NULL,
  `first_names` varchar(30) DEFAULT NULL,
  `surname` varchar(20) DEFAULT NULL,
  `date_of_birth` date DEFAULT NULL,
  `physical_address` varchar(50) DEFAULT NULL,
  `email_address` varchar(45) DEFAULT NULL,
  `phone_number` varchar(10) DEFAULT NULL,
  `position` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`employee_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `employee` (
  `employee_id` int(10) unsigned NOT NULL,
  `pin` int(10) unsigned NOT NULL,
  `first_names` varchar(30) DEFAULT NULL,
  `surname` varchar(20) DEFAULT NULL,
  `date_of_birth` date DEFAULT NULL,
  `physical_address` varchar(50) DEFAULT NULL,
  `email_address` varchar(45) DEFAULT NULL,
  `phone_number` varchar(10) DEFAULT NULL,
  `position` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`employee_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `equipment` (
  `equip_id` int(10) unsigned NOT NULL,
  `name` varchar(45) DEFAULT NULL,
  `description` longtext,
  `loaned_out_to` longtext,
  PRIMARY KEY (`equip_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `video_recording` (
  `filepath` varchar(300) NOT NULL,
  `date` datetime DEFAULT NULL,
  PRIMARY KEY (`filepath`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

equipmentCREATE TABLE `loan_tracking` (
  `loan_id` int(1000) NOT NULL AUTO_INCREMENT,
  `equip_id` int(10) NOT NULL,
  `employee_id` int(10) NOT NULL,
  `loan_date` datetime NOT NULL,
  `return_date` datetime DEFAULT NULL,
  PRIMARY KEY (`loan_id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
