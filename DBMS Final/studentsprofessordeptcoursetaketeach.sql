#The position for PROFESSOR should be either HOD for Head of the Department or Assistent Professor. Create table through appropriate commands, define all integrity constraints and #enter sufficient data through user friendly form design.

create table STUDENTS(SID int primary key, NAME varchar(20), ADDRESS varchar(20));

create table DEPARTMENT(D_ID int primary key, D_NAME varchar(20));

create table PROFESSOR(PID int primary key, NAME varchar(20), D_ID int, POSITION varchar(20), foreign key(D_ID) references DEPARTMENT(D_ID), check(POSITION='HOD' or POSITION='Assistant Professor'));

create table COURSE(C_NO int primary key, C_NAME varchar(20));

create table TAKE(SID int, C_NO int, MARKS int, foreign key(SID) references STUDENTS(SID), foreign key(C_NO) references COURSE(C_NO));

create table TEACH(PID int, C_NO int, D_ID int, foreign key(PID) references PROFESSOR(PID), foreign key(C_NO) references COURSE(C_NO), foreign key(D_ID) references DEPARTMENT(D_ID));

alter table PROFESSOR add column AGE int;


insert into STUDENTS values(1, 'Rajat', 'Kolkata');
insert into STUDENTS values(2, 'Rai', 'Kolkata');
insert into STUDENTS values(3, 'Riya', 'Kolkata');
insert into STUDENTS values(4, 'Rita', 'Delhi');
insert into STUDENTS values(5, 'Sunil', 'Delhi');
insert into STUDENTS values(6, 'Faizam', 'Delhi');
insert into STUDENTS values(7, 'Rob', 'Mumbai');
insert into STUDENTS values(8, 'Raima', 'Mumbai');
insert into STUDENTS values(9, 'Trina', 'Mumbai');
insert into STUDENTS values(10, 'Tina', 'Kolkata');
insert into STUDENTS values(11, 'Tiyasha', 'Delhi');
insert into STUDENTS values(12, 'Sumita', 'Mumbai');
select * from STUDENTS;


insert into DEPARTMENT values(1, 'Computer Science');
insert into DEPARTMENT values(2, 'Mathematics');
insert into DEPARTMENT values(3, 'Zoology');
insert into DEPARTMENT values(4, 'Physiology');
insert into DEPARTMENT values(5, 'Electronics');
select * from DEPARTMENT;


insert into PROFESSOR values(1, 'Bijan Krishna Paul', 1, 'HOD', 40);
insert into PROFESSOR values(2, 'Pratima Biswas', 1, 'Assistant Professor', 39);
insert into PROFESSOR values(3, 'Shyamali Dewan', 2, 'HOD', 38);
insert into PROFESSOR values(4, 'Dishari Dutta', 2, 'Assistant Professor', 37);
insert into PROFESSOR values(5, 'Aindrila Jana', 3, 'HOD', 36);
insert into PROFESSOR values(6, 'Sangeeta Ghosh', 3, 'Assistant Professor', 35);
insert into PROFESSOR values(7, 'Annesha Saha', 4, 'HOD', 34);
insert into PROFESSOR values(8, 'Bidisha Biswas', 4, 'Assistant Professor', 33);
insert into PROFESSOR values(9, 'Pritom Manna', 5, 'HOD', 32);
insert into PROFESSOR values(10, 'Sourav Ghosh', 5, 'Assistant Professor', 31);
select * from PROFESSOR;


insert into COURSE values(1, 'CS3 Hons');
insert into COURSE values(2, 'MTMA3 Hons');
insert into COURSE values(3, 'ZOO3 Hons');
insert into COURSE values(4, 'PHY3 Hons');
insert into COURSE values(5, 'ELTA3 Hons');
select * from COURSE;


insert into TAKE values(1, 1, 90);
insert into TAKE values(2, 1, 91);
insert into TAKE values(3, 1, 92);
insert into TAKE values(4, 2, 94);
insert into TAKE values(5, 2, 95);
insert into TAKE values(6, 2, 96);
insert into TAKE values(7, 3, 97);
insert into TAKE values(8, 3, 98);
insert into TAKE values(9, 4, 99);
insert into TAKE values(10, 4, 100);
insert into TAKE values(11, 5, 93);
insert into TAKE values(12, 5, 89);
select * from TAKE;


insert into TEACH values(1, 1, 1);
insert into TEACH values(3, 2, 2);
insert into TEACH values(5, 3, 3);
insert into TEACH values(7, 4, 4);
insert into TEACH values(9, 5, 5);
select * from TEACH;


#Find out the names of all students who are taking 'CS3 Hons' course.
select NAME from STUDENTS where SID in (select SID from TAKE where C_NO = (select C_NO from COURSE where C_NAME='CS3 Hons'));

#Find the name of the Head of the Department who is teaching maximum number of courses.
select PROFESSOR.NAME from PROFESSOR, TEACH, COURSE where PROFESSOR.PID=TEACH.PID and COURSE.C_NO=TEACH.C_NO and PROFESSOR.POSITION='HOD' group by PROFESSOR.PID, PROFESSOR.NAME order by count(TEACH.C_NO) desc limit 1;



