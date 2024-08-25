create table Employee(emp_name varchar(50), street varchar(50), city varchar(50));

create table Company(company_name varchar(50) primary key, city varchar(50), check(company_name in ('IOC','ABC','XYZ')));

create table Work(emp_name varchar(50), company_name varchar(50), foreign key(company_name) references Company(company_name), salary int default 10000);

create table Manages(emp_name varchar(50), manager varchar(50));


insert into Employee values('Rajat', 'HC Dutta Road', 'Kolkata');
insert into Employee values('Rai', 'GN Banerjee Road', 'Kolkata');
insert into Employee values('Riya', 'Trunk Street', 'Kolkata');
insert into Employee values('Rita', 'Gandhi Street', 'Delhi');
insert into Employee values('Sunil', 'Bose Lane', 'Delhi');
insert into Employee values('Faizam', 'Feeder Road', 'Delhi');
insert into Employee values('Rob', 'Raja Road', 'Mumbai');
insert into Employee values('Raima', 'Raja Road', 'Mumbai');
insert into Employee values('Trina', 'Mrinalini Street', 'Mumbai');
insert into Employee values('Tina', 'HC Dutta Road', 'Kolkata');
insert into Employee values('Tiyasha', 'Gandhi Street', 'Delhi');
insert into Employee values('Sumita', 'Raja Road', 'Mumbai');
select * from Employee;


insert into Company values('IOC', 'Kolkata');
insert into Company values('ABC', 'Delhi');
insert into Company values('XYZ', 'Mumbai');
select * from Company;


insert into Work(emp_name, company_name) values('Rajat', 'ABC');
insert into Work values('Rai', 'ABC', 20000);
insert into Work values('Riya', 'ABC', 30000);
insert into Work values('Rita', 'IOC', 40000);
insert into Work values('Sunil', 'IOC', 50000);
insert into Work values('Faizam', 'IOC', 60000);
insert into Work values('Rob', 'XYZ', 70000);
insert into Work values('Raima', 'XYZ', 80000);
insert into Work values('Trina', 'XYZ', 90000);
insert into Work values('Tina', 'ABC', 100000);
insert into Work values('Tiyasha', 'IOC', 150000);
insert into Work values('Sumita', 'XYZ', 200000);
select * from Work;


insert into Manages values('Rajat', 'Tina');
insert into Manages values('Rai', 'Tina');
insert into Manages values('Riya', 'Tina');
insert into Manages values('Rita', 'Tiyasha');
insert into Manages values('Sunil', 'Tiyasha');
insert into Manages values('Faizam', 'Tiyasha');
insert into Manages values('Rob', 'Sumita');
insert into Manages values('Raima', 'Sumita');
insert into Manages values('Trina', 'Sumita');
select * from Manages;


#Find the names, street address and cities of residence of all employees who work for ABC company and earn more than Rs. 10,000.
select * from Employee where emp_name in (select emp_name from Work where company_name='ABC' and salary>10000);

#Find all employees who do not work for IOC company.
select * from Employee where emp_name in (select emp_name from Work where company_name<>'IOC');

#Find the names of all employees who work for IOC company.
select emp_name from Employee where emp_name in (select emp_name from Work where company_name='IOC');

#Assume that the company may be located in several cities. Find all companies located in every city in which ABC company is located.
show create table Work;
+-------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Table | Create Table                                                                                                                                                                                                                                                                                                                                    |
+-------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Work  | CREATE TABLE `Work` (
  `emp_name` varchar(50) DEFAULT NULL,
  `company_name` varchar(50) DEFAULT NULL,
  `salary` int DEFAULT '10000',
  KEY `company_name` (`company_name`),
  CONSTRAINT `Work_ibfk_1` FOREIGN KEY (`company_name`) REFERENCES `Company` (`company_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci |
+-------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

alter table Work drop foreign key Work_ibfk_1;

alter table Company drop primary key;

insert into Company values('ABC', 'Mumbai');
insert into Company values('IOC', 'Mumbai');
insert into Company values('XYZ', 'Delhi');

#Query:
select distinct c1.company_name from Company c1 where not exists ((select c2.city from Company c2 where c2.company_name='ABC') except (select c3.city from Company c3 where c1.company_name=c3.company_name)) and company_name<>'ABC';

#Find the names and cities of residence of all employees who work for ABC company.
select emp_name, city from Employee where emp_name in (select emp_name from Work where company_name='ABC');

#Find all employees who earn more than every employee of IOC company.
select * from Employee where emp_name in (select emp_name from Work where salary > all (select salary from Work where company_name='IOC'));

