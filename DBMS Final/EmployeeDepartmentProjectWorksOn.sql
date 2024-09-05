create table Department(dname varchar(50), dnumber varchar(50) primary key);

create table Employee(fname varchar(50), lname varchar(50), SSN varchar(50) primary key, dob date, address varchar(50), sex varchar(50), salary int, dno varchar(50), foreign key(dno) references Department(dnumber));

create table Project(pname varchar(50), pnumber varchar(50) primary key, plocation varchar(50), dno varchar(50), foreign key(dno) references Department(dnumber));

create table WorksOn(ESSN varchar(50), pno varchar(50), hours varchar(50), foreign key(ESSN) references Employee(SSN), foreign key(pno) references Project(pnumber));


insert into Department(dname, dnumber) values('IT', 1), ('Finance', 2), ('Electronics', 3), ('Hardware', 4), ('Software', 5), ('Technical', 6);
select * from Department;


insert into Employee(fname, lname, SSN, dob, address, sex, salary, dno) values('Ram', 'Das', 1, '1987-01-01', 'LC Sarani', 'Male', 25000, 1), ('Sapan', 'Ghosh', 2, '1988-02-01', 'AB Sarani', 'Male', 28000, 5), ('Rita', 'Sett', 3, '1989-03-01', 'Tushi Sarani', 'Female', 30000, 2), ('Sumita', 'Ghosh', 4, '1990-04-01', 'GN Banerjee Road', 'Female', 22000, 5), ('Faizam', 'Sheikh', 5, '1991-05-01', 'Feeder Road', 'Male', 33000, 5), ('Sunil', 'Sen', 6, 1992-06-01', 'Ghosh Para Road', 'Male', 40000, 3), ('Anurupa', 'Adhikary', 7, '1993-07-01', 'Ankur Math', 'Female', 44000, 4), ('Sudipta', 'Ghosh', 8, '1995-08-01', 'Panihati', 'Female', 50000, 6);
select * from Employee;

insert into Project(pname, pnumber, plocation, dno) values('A', 1, 'UP', 1), ('B', 2, 'MP', 2), ('C', 3, 'Goa', 5), ('D', 4, 'MP', 5), ('E', 5, 'Delhi', 3), ('F', 6, 'Kolkata', 4);
select * from Project;

insert into WorksOn(ESSN, pno, hours) values(1, 1, 2), (2, 3, 1), (2, 4, 3), (5, 4, 2), (5, 5, 1), (3, 3, 2), (4, 6, 5);
select * from WorksOn;


select fname, lname from Employee where not exists((select pnumber from Project where dno=5) except(select pno from WorksOn where Employee.SSN=WorksOn.ESSN));


select dnumber, count(*), avg(salary) from Employee, Department where Employee.dno=Department.dnumber group by(Department.dnumber);

