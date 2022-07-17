create table Citizen
	(
		NID numeric,
		Name varchar2(25) not null,
		Dob date not null,
		Bld_grp varchar2(3) not null,
		Address varchar2(30),
		Profession varchar2(25),
		Salary DECIMAL(10,2),
		constraint C_PK primary key (NID),
	);
create table Hospital
	(
		Name varchar2(25),
		Location varchar2(25),
		Estd_year numeric,
		Tot_capacity numeric,
		constraint H_PK primary key (Name)
	);
create table Citizen_Admit_Hospital
	(
		NID numeric,
		Hospital_Name varchar2(25),
		Date_of_Admission date,
		Reason varchar2(25),
		constraint CAH_CPK primary key (NID,Hospital_Name,Date_of_Admission),
		constraint CAH_C_FK foreign key (NID) references Citizen(NID),
		constraint CAH_H_FK foreign key (Hospital_Name) references Hospital(Name),
	);
/*
Reasoning for not writing cascading delete clause:
Suppose, we want to check a patient's past medical records in order to determine pre-existing conditions
of that patient. So, we should be able to preserve the medical records, be it for statistical or research purposes. If, by any mistake, the patient's NID
gets deleted or the Hospital discontinues it's service or gets demolished, the patients records will subsequently 
be deleted which is not our aim.
*/
create table License
	(
		L_No numeric,
		NID numeric,
		Name_of_Cit varchar2(25) not null,
		Address varchar2(25),
		Dob date not null,
		Lic_Iss_Date date not null,
		Lic_Exp_Date date not null,
		constraint L_PK primary key (L_No),
		constraint L_C_FK foreign key (NID) references Citizen(NID) on delete cascade
	);
/*
Reasoning:
If any citizen is deleted from the Citizen table (assuming death), his/her driving license records are of no use
anymore. So, upon deleting the citizen's entry in Citizen table, we can subsequently delete his/her driving license info.
*/

create table Publisher
	(
		Name varchar2(25),
		Country varchar2(25),
		Estd_year numeric,
		Reputation varchar2(25),
		constraint P_CPK primary key (Name,Country)
	);
create table Book
	(
		Title varchar2(25),
		Author varchar2(25),
		Price DECIMAL(5,2),
		Study_Area varchar2(25),
		Publisher_Name varchar2(25),
		Publisher_Country varchar2(25),
		constraint B_CPK primary key (Title,Author),
		constraint B_P_FK foreign key (Publisher_Name) references Publisher(Name) on delete cascade,
		constraint B_P_FK2 foreign key (Publisher_Country) references Publisher(Country) on delete cascade,
	);
/*
Reasoning:
If a publsiher's entry is deleted, we want the corresponding Publisher's published to be deleted as well.
This purely based on the assumption that, if any publisher goes out of business we have no use for their books.
*/
create table Citizen_Borrow_Book
	(
		NID numeric,
		Name_of_Citizen varchar2(25),
		Title varchar2(25),
		Author varchar2(25),
		Date_of_Borrowal date,
		Date_of_Return date,
		constraint CBB_CPK primary key (NID,Title,Author,Date_of_Borrowal),
		constraint CBB_C_FK foreign key (NID) references Citizen(NID) on delete cascade,
		constraint CBB_C_FK2 foreign key (Name_of_Citizen) references Citizen(Name) on delete cascade,
		constraint CBB_B_FK foreign key (Title) references Book(Title),
		constraint CBB_B_FK2 foreign key (Author) references Book(Author)
	);
/*
Reasoning:
If any citizen is deleted from the Citizen table, we have no use of his/her book borrowal records, so we can delete them.
But, if any book title is deleted, or the author name is deleted, assuming the author discontinued writing, it is not a valid
reason to delete the whole book borrowal entry.
*/
/*Task 3*/
create or replace view Borrow_Record as
	select * from Citizen_Borrow_Book
	natural join Book;

create or replace view Citizen_Borrowal_Count
	select NID,count(*) as Books_Borrowed
	from Borrow_Record group by NID;
/*Task 4*/
create or replace view License_Holder_Info as
	select L_No,Lic_Iss_Date,Lic_Exp_Date,Name,Profession from 
	(select * from License natural join Citizen);

/*Task 5*/
disc

create user Library_Admin identified by LA1;
create user Hospital_Clerk identified by HC1;
create user Regular_Citizen identified by RC1;

grant create session Library_Admin;
grant create session Hospital_Clerk;
grant create session Regular_Citizen;

create role RCReadOnly;
grant select on Citizen to RCReadOnly;
grant select on License to RCReadOnly;

create role HCReadOnly;
grant select on Citizen_Admit_Hospital to HCReadOnly;

create role LAReadModify;
grant select on Book to LAReadModify;
grant select on Publisher to LAReadModify;
grant insert on Book to LAReadModify;
grant insert on Publisher to LAReadModify; 
grant update on Book to LAReadModify;
grant update on Publisher to LAReadModify;
grant delete on Book to LAReadModify;
grant delete on Publisher to LAReadModify;

grant RCReadOnly to RC1;
grant HCReadOnly to HC1;
grant LAReadModify to LA1;