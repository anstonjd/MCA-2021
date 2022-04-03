CREATE TABLE Employee(
    fname VARCHAR2(20),
    ssn INTEGER PRIMARY KEY,
    salary INTEGER,
    superssn INTEGER
);

CREATE TABLE Department(
    dname VARCHAR2(20),
    dnumber INTEGER PRIMARY KEY,
    mgrssn INTEGER REFERENCES Employee(ssn)
);

CREATE TABLE Project(
    pname VARCHAR2(20),
    pnumber INTEGER PRIMARY KEY,
    plocation varchar2(20),
    dnum INTEGER REFERENCES Department(dnumber)
);

CREATE TABLE worksOn(
    essn INTEGER REFERENCES Employee(ssn),
    pno INTEGER REFERENCES Project(pnumber),
    hours INTEGER
);

SELECT * from Employee;
SELECT * from Department;
SELECT * from Project;
SELECT * from worksOn;

DROP TABLE worksOn;
DROP TABLE Project;
DROP TABLE Department;
DROP TABLE Employee;



INSERT INTO Employee VALUES('Smith',1789,30000,3555);
INSERT INTO Employee VALUES('Franklin',3555,40000,8555);
INSERT INTO Employee VALUES('James',8555,44000,null);
INSERT INTO Employee VALUES('John',9321,20000,3555);

INSERT INTO Department VALUES('Research',5,3555);
INSERT INTO Department VALUES('Adminstration',4,3555);
INSERT INTO Department VALUES('Headquarter',1,8555);

INSERT INTO Project VALUES('Computerization',10,'Delhi',4);
INSERT INTO Project VALUES('Reorganization',12,'Bangalore',1);
INSERT INTO Project VALUES('Newbenefits',11,'Bombay',5);

INSERT INTO worksOn VALUES(8555,11,5);
INSERT INTO worksOn VALUES(3555,12,3);
INSERT INTO worksOn VALUES(1789,11,7);
INSERT INTO worksOn VALUES(3555,10,4);

-- (a) Display all employee names who are working on the project ‘Newbenefits’.
SELECT e.fname from Employee e,worksOn w where e.ssn = w.essn and w.pno = 
(SELECT pnumber from Project where pname = 'Newbenefits'); 

-- (b) Display the manager’s name of employee ‘John’.
SELECT fname from Employee where ssn = 
(SELECT superssn from Employee where Fname = 'John');

-- (c) Display the employee names who were not assigned any project.
SELECT fname from Employee where ssn not in (SELECT essn from worksOn);

-- (d) Display the manager’s name who is managing ‘Research’ Dept.
SELECT e.fname from Employee e,Department d where e.ssn = d.mgrssn and d.dname = 'Research';

-- (e) Display all the project names in which ‘Smith’ is working.
SELECT p.pname from Project p,Employee e,worksOn w WHERE e.ssn = w.essn 
and p.pnumber = w.pno and e.fname='Smith';

-- (f) Display the manager’s name of employee ‘Franklin’.
SELECT fname from Employee where ssn = 
(SELECT superssn from Employee where Fname = 'Franklin');

-- (g) Display the total salary of the employees working in ‘Research’ department
SELECT SUM(e.salary) as Total from Employee e,worksOn w,Project p,Department d where
 e.ssn = w.essn and w.pno = p.pnumber and p.dnum= d.dnumber and d.dname='Research';

-- (h) Display the total hours spent on project ‘Newbenefits’
SELECT sum(w.hours) as total from worksOn w, Project p where 
w.pno = p.pnumber and p.pname = 'Newbenefits';


-- (i) Show the resulting salaries of every employee working on the ‘Newbenefits’ project
-- is given 10% increment
SELECT e.fname,e.salary+e.salary*0.1 as salary from Employee e,worksOn w, Project p where
e.ssn = w.essn and w.pno = p.pnumber and p.pname = 'Newbenefits';

-- (j) Retrieve all employees whose name length is 5 characters.
SELECT fname from Employee where length(fname)=5;

-- (k) List all project numbers for projects that involve an employee whose last name is
-- ‘Smith’, either as a worker or as a manager of the department that controls the
-- project.
SELECT pnumber from project WHERE dnum = 
(SELECT dnumber from Department d ,employee e where  d.mgrssn = e.ssn and e.fname = 'Smith')
or pnumber = (SELECT pno from worksOn w,employee e where w.essn = e.ssn and e.fname = 'Smith');

-- (l) Retrieve the project name and the number of employees who work on that project.
SELECT p.pname,count(*) as count from Project p,worksOn w where w.pno = p.pnumber GROUP by p.pname ;

-- (m) Retrieve all employees whose first character is ‘J’.
SELECT fname from Employee where fname like 'J%';

-- (n) Find the sum of salaries of all employees of the project ‘Newbenefits’, the maximum
-- salary, the minimum salary and the average salary.
SELECT MAX(e.salary) as max,MIN(e.salary) as min,AVG(e.salary) as Average 
from Employee e,worksOn w where e.ssn = w.essn and w.pno = 
(SELECT pnumber from Project where pname = 'Newbenefits'); 

-- (o) Retrieve the names of employees who work on more than one project
SELECT e.fname from Employee e ,worksOn w where e.ssn = w.essn and w.pno in
(SELECT pno from worksOn GROUP by pno HAVING count(*)>1);