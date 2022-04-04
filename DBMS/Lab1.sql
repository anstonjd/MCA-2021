-- teacher (t_no, f_name, l_name, salary, supervisor, joiningdate, birthdate, title) 
CREATE TABLE teacher(
    t_no INTEGER PRIMARY KEY,
    f_name VARCHAR2(20),
    l_name VARCHAR2(20),
    salary INTEGER,
    supervisor INTEGER,
    joiningdate DATE,
    birthdate DATE,
    title VARCHAR2(20)
);

-- class (class_no, t_no, room_no) 
CREATE TABLE class(
    class_no INTEGER PRIMARY KEY,
    t_no INTEGER,
    room_no INTEGER
);

-- payscale (Min_limit, Max_limit, grade) 
CREATE TABLE payscale(
    Min_limit INTEGER,
    Max_limit INTEGER,
    grade VARCHAR2(20),
    PRIMARY KEY(Min_limit, Max_limit)
);

-- DROP
DROP TABLE teacher;

DROP TABLE class;

DROP TABLE payscale;


-- SELECT
SELECT * from teacher;
SELECT * from class;
SELECT * from payscale;



-- INSERT Commands


Delete from teacher;

INSERT INTO teacher VALUES(101, 'Santhosh','Roa',30000,null, '16-Jun-1993','17-Apr-1973','Professor');
INSERT INTO teacher VALUES(102, 'Ramesh','Shetty',20000,null, '15-Jan-2019','01-Dec-1995','Assistant Professor');
INSERT INTO teacher VALUES(103, 'Hansel','Lobo',40000,null, '02-Mar-2005','09-May-1993','Professor');
INSERT INTO teacher VALUES(104, 'Gladson','Dcosta',90000,null, '04-Nov-2005','23-Jun-1992','Assistant Professor');
INSERT INTO teacher VALUES(105, 'Anston','Dcunha',80000,null, '06-Oct-2020','13-Jul-2000','Professor');
INSERT INTO teacher VALUES(106, 'Lailesh','Veigas',35000,null, '08-Sep-2008','28-Aug-1990','Assistant Professor');
INSERT INTO teacher VALUES(107, 'Amir','Khan',9000,null, '05-Feb-2005','21-Dec-1993','Professor');
INSERT INTO teacher VALUES(108, 'Jaideep','R',22000,100, '02-jan-2003','15-Oct-1989','Assistant Professor');
INSERT INTO teacher VALUES(109, 'Priston','Lobo',25000,102, '05-Feb-2002','19-Mar-1985','Professor');
INSERT INTO teacher VALUES(110, 'Santhosh','Sinha',30000,103, '01-Jun-1999','15-Nov-1978','Professor');


Delete from class;
INSERT INTO class VALUES(1,101,1001);
INSERT INTO class VALUES(2,102,1010);
INSERT INTO class VALUES(3,105,1020);
INSERT INTO class VALUES(4,106,1030);
INSERT INTO class VALUES(5,103,1040);
INSERT INTO class VALUES(6,104,1050);

Delete from payscale;
INSERT INTO payscale VALUES(10000,20000,'A');
INSERT INTO payscale VALUES(20000,30000,'B');
INSERT INTO payscale VALUES(30000,40000,'C');
INSERT INTO payscale VALUES(40000,50000,'D');
INSERT INTO payscale VALUES(50000,100000,'E');
 

-- simple query 
-- query 1: display all teachers name whose salary <10000; 

SELECT f_name,l_name FROM teacher where salary <=10000;

-- query 2: display all teachers whose birthdate <’1-jan-1995’ 

SELECT * from  teacher where birthdate<'1-Jan-1995';

-- query 3: display all teachers where f_name begins with ‘s’ 

SELECT * from  teacher where f_name LIKE 'S%'; 

-- query 4: display all teachers where length of f_name is <5 letters 

SELECT * from  teacher where length(f_name)<5; 

-- query 5: display all teachers whose birthdate is between ’1-jan-1995’ and ‘1-jan-2000’ 

SELECT * from  teacher where birthdate between '1-Jan-1995' and '01-Jan-2000';

-- query 6: display all teachers where f_name begins with ‘s’ and ends with ‘h’ 

SELECT * from teacher WHERE LOWER(f_name) like 's%h';

-- query 7: query 5: display all teachers whose joiningdate is between ’1-jan-2020’ and ‘1-jan-2021’ 

SELECT * from  teacher where joiningdate between '01-Jan-2020' and '1-Jan-2021';

-- query 8: display all teachers who don’t have supervisor 

SELECT * from teacher where supervisor is null;

-- query 9: display all teachers who have supervisor 

SELECT * from teacher where supervisor is not null;

-- query 10: display all payscale details 

SELECT * from payscale;

-- Subquery 
-- Query 1: Display the name of the teacher who is oldest among all teachers 

SELECT f_name,l_name from teacher
WHERE birthdate=(SELECT min(birthdate) from teacher);

-- Query 2: Display teacher numbers and names of those teachers who are earning less than ‘Santhosh’. 

SELECT t_no,f_name,l_name from teacher WHERE salary < (
    SELECT salary from teacher where f_name LIKE 'Santhosh');
-- Multiple-Row Subquery 
-- Query 3: Display the list of all teachers who are earning equal to any teacher who have joined before ‘31-dec-94’ 
SELECT t_no,f_name,l_name,salary from teacher WHERE salary in (
    SELECT salary FROM teacher WHERE joiningdate <'31-dec-1994');

-- Query 4: Display the list of all those teachers whose salary is greater than any other teacher with job title ‘Prof’. 

SELECT t_no,f_name,l_name,salary from teacher WHERE salary > any(
SELECT salary from teacher where title like 'Professor');

-- Query 5: Display the list of all those teachers whose salary is greater than all the teachers with job title as ‘Prof’. 
SELECT t_no,f_name,l_name,salary from teacher WHERE salary > all(
SELECT salary from teacher where title like 'Professor');

-- Multiple-Column subquery 
-- Query 6: Display the list of all teachers whose job title and salary is same as that of the employee whose first name is ‘Santhosh’ 
-- Correlated Subqueries 
SELECT t_no,f_name,l_name,salary,title from teacher WHERE (salary, title)  in (
    SELECT salary,title from teacher where f_name like 'Santhosh');

-- Query 7: Display the records in the format given below for all class teachers: 
-- Santhosh is a class teacher 
SELECT f_name || ' is a class teacher' from teacher where 
    t_no in (SELECT t_no from class);

-- Joins 
-- 1) Equijoin – In this type of join, two or more tables are joined over common columns and common values. For example: 
-- Query 8: Display names of all the teachers who are class teachers. 
SELECT f_name,l_name from teacher where t_no 
    in(SELECT t_no from class);

-- 2) Non-Equijoin - In this type of join, two or more tables do not have common columns and common values but they are joined indirectly. 



-- 3) Outer join - In this type of join, two or more tables are joined over common column but the records may or may not have common values. 


-- Query 10: Display names and class numbers of all the teachers. In addition display the classes of those teachers who are class teachers. 

    SELECT class_no,f_name,l_name from teacher t ,class c where t.t_no = c.t_no;

-- 4) Self join - In this type of join, the table is joined to itself. 
-- Query 11: Display teacher number and names of all teachers along with the names of their supervisors and number. Please note that the supervisor of a teacher is also a teacher.
--  Therefore, the query requires a self-join. 

SELECT t.f_name,t.l_name,t.supervisor,s.f_name,s.l_name 
    from teacher t,teacher s WHERE t.supervisor = s.t_no;

-- 5) Cartesian join – In this type of join, each record of one table is joined to each record of the other table i.e., the join condition is not given 
-- Query 12: Show all possible teacher – class values. 

SELECT f_name,l_name,class_no from teacher,class;

-- Exercise 1 
-- (a) Display the name of the teacher(s) who is (are) the youngest among all the teachers. 
SELECT f_name,l_name from teacher
WHERE birthdate=(SELECT max(birthdate) from teacher);

-- (b) Display details of all the teachers who have the same job title as that of ‘Jaideep’ ' 

SELECT * from teacher where title like (SELECT title from teacher where f_name = 'Jaideep'); 

-- (c) Display the list of all the teachers who have joined after ‘10-Jul-95’ and whose salary is equal to that of any of the teachers who joined before ‘10-Jul-95’. 

SELECT * from teacher where joiningdate>'10-Jul-1995' and salary in(SELECT salary from teacher where joiningdate<'10-Jul-1995');

-- (d) Use a correlated query to determine the teachers who are not class teachers. 

SELECT f_name,l_name from teacher where t_no NOT IN(SELECT t_no from class);

-- (e) Identify all those teachers who are in grade ‘B’. 
SELECT f_name,l_name,salary,grade from teacher t,payscale p where t.salary between p.min_limit AND p.max_limit AND p.grade='B';

-- (f) Display the names and numbers of all teachers who are class teachers and are in grade ‘C’. 
SELECT f_name,l_name,salary,grade from teacher t,payscale p where t.t_no IN(SELECT t_no from class) AND t.salary between p.min_limit AND p.max_limit AND p.grade='C';

-- (g) Display the names of all teachers who are supervisors. 
SELECT t_no,f_name,l_name from teacher WHERE t_no in (SELECT supervisor from teacher);

-- (h) Display the teacher id and salaries of all those teachers who are in grade ‘A’ or ‘C’ and who have at least two L’s in their names. 
SELECT t_no,f_name,l_name,salary,grade from teacher t,payscale p where t.salary between p.min_limit AND p.max_limit AND p.grade in(SELECT grade from payscale) AND UPPER(t.f_name) like '%L%L%';

-- (i) Display details of all those teachers who are class teachers of classes 1 to 5. 
SELECT t.t_no,t.f_name,t.l_name from teacher t,class c where t.t_no=c.t_no AND
c.class_no in(SELECT class_no from class where class_no BETWEEN 1 AND 5);

-- (j) Display the names of all teachers along with their dates of birth whose birthday is in the current month.

SELECT t_no,f_name,l_name FROM teacher where to_char(birthdate,'Month') in (SELECT to_char(sysdate,'Month') from DUAL);