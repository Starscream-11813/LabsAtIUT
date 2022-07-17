/*
1. Connect to the database via System
*/
connect system

/*
2. Create a new user and a new role
*/
create user Rifat identified by test123;
create role exampleRole;

/*
3. Grant the CONNECT privilege to the role, and grant this role to the new user
*/
grant connect to exampleRole;
grant exampleRole to Rifat;

/*
4. Grant ALL privileges to new user, and connect to this user
*/
grant all privileges to Rifat;
connect Rifat

/*
5. Create a new table, “Students”: (ID – number, Name – varchar2, Address – varchar2)
*/
create table Students(
ID numeric,
Name varchar2(30),
Address varchar2(60)
);

/*
6. Insert a new column (Using ALTER) into the table: (Class Rank – number)
*/
alter table Students add ClassRank numeric;

/*
7. Insert at least 3 rows of information into the table
*/
insert into Students values(180041205,'Syed Rifat Raiyan','37 Shah Makhdum Avenue, Sector-12, Uttara, Dhaka',69);
insert into Students values(180041234,'Shah Md. Jawad Kabir','Kishoreganj',1);
insert into Students values(180041218,'Ishrak Hossain','Sector-13, Uttara, Dhaka',2);

/*
8. Drop a column (Using ALTER) and a row (Using DELETE)
*/
alter table Students drop column Address;
delete from Students where Name='Syed Rifat Raiyan';

/*
9. Implement a SELECT statement with the WHERE clause
*/
select Name from Students where ID='180041218';

/*
10. Drop the table
*/
drop table Students;