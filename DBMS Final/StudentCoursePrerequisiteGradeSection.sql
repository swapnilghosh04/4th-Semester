mysql> create table Student(name varchar(50), stud_no varchar(50) primary key, class varchar(50), major varchar(50));
Query OK, 0 rows affected (0.02 sec)

mysql> create table Course(c_name varchar(50), c_no varchar(50) primary key, credit_hours varchar(50), dept varchar(50));
Query OK, 0 rows affected (0.02 sec)

mysql> create table Prerequisite(course_no varchar(50), prerequisite_no varchar(50), foreign key(course_no) references Course(c_no));
Query OK, 0 rows affected (0.02 sec)

mysql> create table Section(section_id varchar(50), course_no varchar(50), semester varchar(50), year date, instructor varchar(50));
Query OK, 0 rows affected (0.02 sec)

mysql> create table Grade(stud_no varchar(50), section_id varchar(50), grade varchar(50), foreign key(stud_no) references Student(stud_no), foreign key(section_id) references Section(section_id));
ERROR 1822 (HY000): Failed to add the foreign key constraint. Missing index for constraint 'Grade_ibfk_2' in the referenced table 'Section'
mysql> alter table Section add primary key(section_id);
Query OK, 0 rows affected (0.03 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> create table Grade(stud_no varchar(50), section_id varchar(50), grade varchar(50), foreign key(stud_no) references Student(stud_no), foreign key(section_id) references Section(section_id));
Query OK, 0 rows affected (0.02 sec)

mysql> insert into Course(c_name, c_no, credit_hours, dept) values('DSA', 'C1', 1, 'Computer Science'), ('Real Analysis', 'C2', 2, 'Mathematics'), ('Microprocessor', 'C3', 3, 'Electronics'), ('Agriculture', 'C4', 4, 'Geography'), ('British India', 'C5', 5, 'History');
Query OK, 5 rows affected (0.01 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql> select * from Course;
+----------------+------+--------------+------------------+
| c_name         | c_no | credit_hours | dept             |
+----------------+------+--------------+------------------+
| DSA            | C1   | 1            | Computer Science |
| Real Analysis  | C2   | 2            | Mathematics      |
| Microprocessor | C3   | 3            | Electronics      |
| Agriculture    | C4   | 4            | Geography        |
| British India  | C5   | 5            | History          |
+----------------+------+--------------+------------------+
5 rows in set (0.00 sec)

mysql> insert into Student(name, stud_no, class, major) values('AAA', 'S1','Primary', 'Computer Science'), ('BBB', 'S2', 'Secondary', 'Computer Science'), ('CCC', 'S3', 'Primary', 'Mathematics'), ('DDD', 'S4', 'Secondary', 'Mathematics'), ('EEE', 'S5', 'Primary', 'Electronics'), ('FFF', 'S6', 'Secondary', 'Electronics'), ('GGG', 'S7', 'Primary', 'Geography'), ('HHH', 'S8', 'Secondary', 'Geography'), ('III', 'S9', 'Primary', 'History'), ('JJJ', 'S10', 'Secondary', 'History');
Query OK, 10 rows affected (0.01 sec)
Records: 10  Duplicates: 0  Warnings: 0

mysql> select * from Student;
+------+---------+-----------+------------------+
| name | stud_no | class     | major            |
+------+---------+-----------+------------------+
| AAA  | S1      | Primary   | Computer Science |
| JJJ  | S10     | Secondary | History          |
| BBB  | S2      | Secondary | Computer Science |
| CCC  | S3      | Primary   | Mathematics      |
| DDD  | S4      | Secondary | Mathematics      |
| EEE  | S5      | Primary   | Electronics      |
| FFF  | S6      | Secondary | Electronics      |
| GGG  | S7      | Primary   | Geography        |
| HHH  | S8      | Secondary | Geography        |
| III  | S9      | Primary   | History          |
+------+---------+-----------+------------------+
10 rows in set (0.00 sec)

mysql> insert into Prerequisite(course_no, prerequisite_no) values('C1', 90), ('C2', 80), ('C3', 70), ('C4', 60), ('C5', 50);
Query OK, 5 rows affected (0.00 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM Prerequisite;
+-----------+-----------------+
| course_no | prerequisite_no |
+-----------+-----------------+
| C1        | 90              |
| C2        | 80              |
| C3        | 70              |
| C4        | 60              |
| C5        | 50              |
+-----------+-----------------+
5 rows in set (0.00 sec)

mysql> insert into Section(section_id, course_no, semester, year, instructor) values('SS1', 'C1', 'III', '2024', 'Prof. X'), ('SS2', 'C1', 'IV', '2024',
'Prof. Y'), ('SS3', 'C2', 'III', '2024', 'Prof. Z'), ('SS4', 'C2', 'IV', '2024', 'Prof. X'), ('SS5', 'C3', 'III', '2024', 'Prof. Y'), ('SS6', 'C3', 'IV', '2024', 'Prof. Z'), ('SS7', 'C4', 'III', '2024', 'Prof. X'), ('SS8', 'C4', 'IV', '2024', 'Prof. Y'), ('SS9', 'C5', 'III', '2024', 'Prof. Z'), ('SS10', 'C5', 'IV', '2024', 'Prof. X');
ERROR 1292 (22007): Incorrect date value: '2024' for column 'year' at row 1
mysql> alter table Section modify column year varchar(50);
Query OK, 0 rows affected (0.04 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> insert into Section(section_id, course_no, semester, year, instructor) values('SS1', 'C1', 'III', '2024', 'Prof. X'), ('SS2', 'C1', 'IV', '2024',
'Prof. Y'), ('SS3', 'C2', 'III', '2024', 'Prof. Z'), ('SS4', 'C2', 'IV', '2024', 'Prof. X'), ('SS5', 'C3', 'III', '2024', 'Prof. Y'), ('SS6', 'C3', 'IV', '2024', 'Prof. Z'), ('SS7', 'C4', 'III', '2024', 'Prof. X'), ('SS8', 'C4', 'IV', '2024', 'Prof. Y'), ('SS9', 'C5', 'III', '2024', 'Prof. Z'), ('SS10', 'C5', 'IV', '2024', 'Prof. X');
Query OK, 10 rows affected (0.01 sec)
Records: 10  Duplicates: 0  Warnings: 0

mysql> select * from Section;
+------------+-----------+----------+------+------------+
| section_id | course_no | semester | year | instructor |
+------------+-----------+----------+------+------------+
| SS1        | C1        | III      | 2024 | Prof. X    |
| SS10       | C5        | IV       | 2024 | Prof. X    |
| SS2        | C1        | IV       | 2024 | Prof. Y    |
| SS3        | C2        | III      | 2024 | Prof. Z    |
| SS4        | C2        | IV       | 2024 | Prof. X    |
| SS5        | C3        | III      | 2024 | Prof. Y    |
| SS6        | C3        | IV       | 2024 | Prof. Z    |
| SS7        | C4        | III      | 2024 | Prof. X    |
| SS8        | C4        | IV       | 2024 | Prof. Y    |
| SS9        | C5        | III      | 2024 | Prof. Z    |
+------------+-----------+----------+------+------------+
10 rows in set (0.00 sec)

mysql> insert into Grade(stud_no, section_id, grade) values('S1', 'SS1', 'A'), ('S2', 'SS2', 'B'), ('S3', 'SS3', 'A'), ('S4', 'SS4', 'B'), ('S5', 'SS5', 'B'), ('S6', 'SS6', 'C'), ('S7', 'SS7', 'C'), ('S8', 'SS8', 'D'), ('S9', 'SS9', 'D'), ('S10', 'SS10', 'E');
Query OK, 10 rows affected (0.01 sec)
Records: 10  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM Grade;
+---------+------------+-------+
| stud_no | section_id | grade |
+---------+------------+-------+
| S1      | SS1        | A     |
| S2      | SS2        | B     |
| S3      | SS3        | A     |
| S4      | SS4        | B     |
| S5      | SS5        | B     |
| S6      | SS6        | C     |
| S7      | SS7        | C     |
| S8      | SS8        | D     |
| S9      | SS9        | D     |
| S10     | SS10       | E     |
+---------+------------+-------+
10 rows in set (0.00 sec)

mysql> select course_no, semester, year, count(*) from Student, Grade, Section where Student.stud_no=Grade.stud_no and Grade.section_id=Section.section_id where Section.instructor='Prof. X' group by(section_id);
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'where Section.instructor='Prof. X' group by(section_id)' at line 1
mysql> select course_no, semester, year, count(*) from Student, Grade, Section where Student.stud_no=Grade.stud_no and Grade.section_id=Section.section_id and Section.instructor='Prof. X' group by(section_id);
ERROR 1052 (23000): Column 'section_id' in group statement is ambiguous
mysql> select course_no, semester, year, count(*) from Student, Grade, Section where Student.stud_no=Grade.stud_no and Grade.section_id=Section.section_id and Section.instructor='Prof. X' group by(Section.section_id);
+-----------+----------+------+----------+
| course_no | semester | year | count(*) |
+-----------+----------+------+----------+
| C1        | III      | 2024 |        1 |
| C5        | IV       | 2024 |        1 |
| C2        | IV       | 2024 |        1 |
| C4        | III      | 2024 |        1 |
+-----------+----------+------+----------+
4 rows in set (0.00 sec)

mysql> select * from Section;
+------------+-----------+----------+------+------------+
| section_id | course_no | semester | year | instructor |
+------------+-----------+----------+------+------------+
| SS1        | C1        | III      | 2024 | Prof. X    |
| SS10       | C5        | IV       | 2024 | Prof. X    |
| SS2        | C1        | IV       | 2024 | Prof. Y    |
| SS3        | C2        | III      | 2024 | Prof. Z    |
| SS4        | C2        | IV       | 2024 | Prof. X    |
| SS5        | C3        | III      | 2024 | Prof. Y    |
| SS6        | C3        | IV       | 2024 | Prof. Z    |
| SS7        | C4        | III      | 2024 | Prof. X    |
| SS8        | C4        | IV       | 2024 | Prof. Y    |
| SS9        | C5        | III      | 2024 | Prof. Z    |
+------------+-----------+----------+------+------------+
10 rows in set (0.00 sec)

mysql> select name, dept from Student, Course, Section, Grade where Student.stud_no=Grade.stud_no and Course.c_no=Section.course_no and Grade.section_id=Section.section_id except (select name, dept from Student, Course, Section, Grade where Student.stud_no=Grade.stud_no and Course.c_no=Section.course_no and Grade.section_id=Section.section_id and grade<>'A');
+------+------------------+
| name | dept             |
+------+------------------+
| AAA  | Computer Science |
| CCC  | Mathematics      |
+------+------------------+
2 rows in set (0.00 sec)

mysql> select name, dept from Student, Course, Section, Grade where Student.stud_no=Grade.stud_no and Course.c_no=Section.course_no and Grade.section_id=Section.section_id except (select name, dept from Student, Course, Section, Grade where Student.stud_no=Grade.stud_no and Course.c_no=Section.course_no and Grade.section_id=Section.section_id and grade='A');
+------+------------------+
| name | dept             |
+------+------------------+
| JJJ  | History          |
| BBB  | Computer Science |
| DDD  | Mathematics      |
| EEE  | Electronics      |
| FFF  | Electronics      |
| GGG  | Geography        |
| HHH  | Geography        |
| III  | History          |
+------+------------------+

