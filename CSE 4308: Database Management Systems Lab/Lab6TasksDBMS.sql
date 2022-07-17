/*Scenario-1*/
create table Station
	(
		Name varchar2(25),
		No_of_Platforms numeric,
		No_of_Ticket_Counters numeric,
		constraint Station_PK primary key (Name)
	);

create table Ticket
	(
		Ticket_ID numeric,
		Customer_ID numeric,
		Date_Of_Journey varchar2(15),
		Starting_Station varchar2(25),
		Destination_Station varchar2(25),
		Seat_Type varchar2(10),
		constraint Ticket_PK primary key (Ticket_ID),
		constraint T_S_FK1 foreign key (Starting_Station) references Station(Name),
		constraint T_S_FK2 foreign key (Destination_Station) references Station(Name)
	);
create table Customer
	(
		Customer_ID numeric,
		Name varchar2(20),
		Age numeric,
		NID numeric,
		constraint Customer_PK primary key (Customer_ID),
		constraint C_T_FK foreign key (Customer_ID) references Ticket(Customer_ID)
	);
create table Track
	(
		Track_ID numeric,
		Station1 varchar2(25),
		Station2 varchar2(25),
		constraint TR_FK primary key (Track_ID),
		constraint TR_S_FK1 foreign key (Station1) references Station(Name),
		constraint TR_S_FK2 foreign key (Station2) references Station(Name)
	);

/*Scenario-2*/
create table Employee
	(
		Employee_ID numeric,
		Name varchar2(25),
		Age numeric,
		Phone varchar2(13),
		constraint E_PK primary key (Employee_ID)
	);
create table Cart 
	(
		Customer_ID numeric,
		Product_ID numeric,
		Quantity numeric,
		constraint CA_CPK primary key (Customer_ID,Product_ID)
	);
create table Customer
	(
		Customer_ID numeric,
		Name varchar2(25),
		Age numeric,
		constraint C_PK primary key (Customer_ID),
		constraint C_CA_FK foreign key (Customer_ID) references Cart(Customer_ID)
	);
create table Product
	(
		Product_ID numeric,
		Name varchar2(25),
		Price numeric(9,2),
		constraint P_PK primary key (Product_ID),
		constraint P_CA_FK foreign key (Product_ID) references Cart(Product_ID)
	);

/*Scenario-3*/
create table Job
	(
		Citizen_ID numeric,
		Profession_ID numeric,
		Institution varchar2(25),
		constraint J_PK primary key (Citizen_ID,Profession_ID)
	);
create table Profession
	(
		Profession_ID numeric,
		Name varchar2(25),
		Minimum_Educational_Requirement varchar2(10),
		Approximate_Salary numeric(9,2),
		constraint PR_PK primary key (Profession_ID),
		constraint PR_J_FK foreign key (Profession_ID) references Job(Profession_ID)
	);
create table Division
	(
		Name varchar2(25),
		No_of_Districts numeric,
		constraint DIV_PK primary key (Name)
	);
create table District
	(
		Name varchar2(25),
		Division_Name varchar2(25),
		constraint DIS_PK primary key (Name),
		constraint DIS_DIV_FK foreign key (Division_Name) references Division(Name)
	);
create table Citizen
	(
		Citizen_ID numeric,
		Name varchar2(25),
		Date_of_Birth date,
		Address varchar2(25),
		District varchar2(25),
		Division varchar2(25),
		Profession_ID numeric,
		Blood_Group varchar2(3) NOT NULL
		constraint CI_PK primary key (Citizen_ID),
		constraint CI_DIV_FK foreign key (Division) references Division(Name),
		constraint CI_DIS_FK foreign key (District) references District(Name),
		constraint CI_J_FK foreign key (Citizen_ID) references Job(Citizen_ID)
	);

/*SQL Statements*/
select count(*), Blood_Group 
from Citizen 
group by Blood_Group;


select distinct Profession_ID,Profession.Name,Approximate_Salary,count(*) 
from Profession,Citizen 
group by Profession_ID,Profession.Name,Approximate_Salary;


select distinct Profession_ID,Profession.Name,count(*)
from Profession,Citizen
where rownum<=3
group by Profession_ID,Profession.Name
order by count(*);