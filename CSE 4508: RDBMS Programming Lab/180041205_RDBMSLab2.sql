-- 1a) From system, create User U1 and grant all privileges
create user U1 identified by test123;
grant all privileges to U1;

-- 1b) Connect to U1, and make a table T1 (ID – Number, Name – Varchar2)
connect U1
create table T1(
	ID numeric,
	Name varchar2(30)
);

-- 1c) Insert values and logout
insert into T1 values(180041205,'Syed Rifat Raiyan');
insert into T1 values(180041234,'Shah Md. Jawad Kabir');
insert into T1 values(180041218,'Ishrak Hossain');
disconnect U1

-- From system, create a public synonym for table T1, called S1
connect system
create synonym S1 for U1.T1;

-- Create another user U2 with all privileges, and access table T1 through the synonym S1
create user U2 identified by test123;
grant all privileges to U2;

connect U2

select * from S1;


/*
2a) Establish a one to one relationship
	i) Create a table Teachers (t_id Number, Name – Varchar2) & a table Assistants (a_id
	   Number, Name – Varchar2) with appropriate primary keys and foreign keys. Insert
	   values to show the 1-1 relationship. 
*/
create table Teachers(
	t_id numeric,
	Name varchar2(30),
	constraint Teachers_PK primary key (t_id)
);
create table Assistants(
	a_id numeric,
	Name varchar2(30),
	t_id numeric,
	constraint Assistants_PK primary key (a_id),
	constraint A_T_FK foreign key (t_id) references Teachers(t_id)
);
insert into Teachers values (1,'Md. Bakhtiar Hasan');
insert into Teachers values (2,'Md. Mohsinul Kabir');
insert into Teachers values (3,'Talha Ibn Aziz');
insert into Teachers values (4,'Njayou Youssouf');

insert into Assistants values(180041205,'Syed Rifat Raiyan',1);
insert into Assistants values(180041218,'Ishrak Hossain',2);
insert into Assistants values(180041238,'M. K. Bashar',3);
insert into Assistants values (180041222,'Md. Maksudul Haque',4);

set linesize 100;
select Assistants.a_id,Assistants.Name,Assistants.t_id,Teachers.Name from Assistants,Teachers where Assistants.t_id=Teachers.t_id;


/*
2b) Establish a one to many relationship
	i) Create a table Courses (c_id Number, Name – Varchar2) with appropriate primary
	   and foreign keys, and establish a 1-Many relationship with Teachers. (Teachers=1,
	   Courses=Many). Insert values to show this relationship.
*/
create table Courses(
	c_id numeric,
	Name varchar2(30),
	t_id numeric,
	constraint Courses_PK primary key (c_id),
	constraint C_T_FK foreign key (t_id) references Teachers(t_id)
);

insert into Courses values(4341,'Linear Algebra',2);
insert into Courses values(4508,'RDBMS Programming Lab',2);
insert into Courses values(4403,'Algorithms',1);
insert into Courses values(4107,'Structured Programming I',3);
insert into Courses values(4202,'Structured Programming II Lab',3);
insert into Courses values(4539,'Web Programming',4);

set linesize 100;
select Teachers.t_id, Teachers.Name, Courses.c_id, Courses.Name from Teachers, Courses where Teachers.t_id=Courses.t_id order by Teachers.t_id;


/*
2c) Establish a many to many relationship
	i) Create a table Students (s_id Number, Name – Varchar2) with appropriate primary
	   and foreign keys
*/
create table Students(
	s_id numeric,
	Name varchar2(30),
	constraint Students_PK primary key (s_id)
);

-- ii)  Create a junction table Student_Course (s_id, c_id) with appropriate foreign keys.
create table Student_Course(
	s_id numeric,
	c_id numeric,
	constraint Student_Course_CPK primary key (s_id,c_id),
	constraint SC_S_FK foreign key (s_id) references Students(s_id),
	constraint SC_C_FK foreign key (c_id) references Courses(c_id)
);

-- iii) Insert values to show the Many-Many relationship created between Students and Courses via Student_Course.
insert into Students values(180041205,'Syed Rifat Raiyan');
insert into Students values(180041218,'Ishrak Hossain');
insert into Students values(180041238,'M. K. Bashar');
insert into Students values (180041222,'Md. Maksudul Haque');

insert into Student_Course values(180041205,4341);
insert into Student_Course values(180041205,4508);
insert into Student_Course values(180041205,4403);
insert into Student_Course values(180041218,4341);
insert into Student_Course values(180041218,4107);
insert into Student_Course values(180041222,4539);
insert into Student_Course values(180041238,4403);
insert into Student_Course values(180041238,4202);

select Students.Name,Student_Course.s_id,Student_Course.c_id,Courses.Name from Students,Student_Course,Courses where Student_Course.s_id=Students.s_id and Student_Course.c_id=Courses.c_id;


-- 3) Display the list of all tables created, sorted with respect to time of creation.
SELECT object_name, timestamp FROM all_objects WHERE object_name in (SELECT table_name FROM all_tables where owner='U1' or owner='U2') and (owner='U1' or owner='U2') order by created;
