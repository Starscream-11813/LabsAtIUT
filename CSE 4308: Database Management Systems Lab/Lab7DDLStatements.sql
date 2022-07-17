create table Citizen
	(
		Citizen_ID numeric,
		Name varchar2(25),
		Date_of_Birth date,
		Address varchar2(25),
		Profession varchar2(10),
		Salary numeric,
		Blood_Group varchar2(3) NOT NULL
		constraint CI_PK primary key (Citizen_ID)
	);
create table Driving_License
	(
		License_Number numeric,
		Citizen_ID numeric,
		Name varchar2(25),
		Date_of_Birth date,
		Address varchar2(25),
		License_Issue_Date date,
		License_Expiry_Date date,
		constraint DL_PK primary key (License_Number),
		constraint DL_CI_FK foreign key (Citizen_ID) references Citizen(Citizen_ID)/*A person with a driving license must also have a unique Citizen_ID */
	);
create table Hospitals
	(
		Hospital_ID numeric,
		Name varchar2(25),
		Address varchar2(25),
		Estd_Year numeric,
		Total_Capacity numeric,
		constraint H_PK primary key (Hospital_ID) 
	);
create table Patient_Records
	(
		Citizen_ID numeric,
		Hospital_ID numeric,
		Date_of_Admission date,
		Reason_of_Admission varchar2(25),
		Diagnosis varchar2(25),
		constraint PR_CPK primary key (Citizen_ID,Hospital_ID),/* Composite PK assuming we can uniquely identify the patient admission in a certain hospital*/
		constraint PR_CI_FK foreign key (Citizen_ID) references Citizen(Citizen_ID),/*Points to Citizen_ID*/
		constraint PR_H_FK foreign key (Hospital_ID) references Hospitals(Hospital_ID)/*Points to Hospital_ID*/
	);
create table Library
	(
		Name varchar2(25),
		Address varchar2(25),
		Name_of_Owner varchar2(25),
		constraint L_CPK primary key (Name,Address)/*Because in the scenario it is mentioned that we can identify a library by its name and address*/
	);
create table Books
	(
		ISBN numeric,/*International Book Standard Number which is unique for every book ever published*/
		Title  varchar2(25),
		Author varchar2(25),
		Genre_Category varchar2(25),
		constraint B_PK primary key (ISBN)
	);
create table Book_Records
	(
		Library_Name varchar2(25),
		ISBN numeric,
		Copies_Available numeric,
		constraint BR_CPK primary key (Library_Name,ISBN),
		constraint BR_L_FK foreign key (Library_Name) references Library(Name),
		constraint BR_B_FK foreign key (ISBN) references Books(ISBN)
	);
create table Publishers
	(
		Name varchar2(25),/*Assuming Trade marked name*/
		Estd_Year numeric,
		Origin varchar2(25),
		Reputation numeric,
		constraint P_PK primary key (Name)
	);
create table Publish_Records
	(
		Publisher_Name varchar2(25),
		ISBN numeric,
		Date_of_Launch date,
		constraint PUR_CPK primary key (Publisher_Name,ISBN),
		constraint PUR_PU_FK foreign key (Publisher_Name) references Publishers(Name),
		constraint PUR_B_FK foreign key (ISBN) references Books(ISBN)
	);
create table Lending_Records
	(
		Library_Name varchar2(25),
		Library_Address varchar2(25),
		Citizen_ID numeric,
		ISBN numeric,
		Date_of_Borrowal date,
		Due_Date date,/*Assuming there is a fine if the return date surpasses the due date*/
		Date_of_Return date,
		Late_Fines numeric,
		constraint LR_CPK primary key (Library_Name,Library_Address,Citizen_ID,ISBN),/*Only possible way to uniquely know which citizen borowed which book from which library*/
		constraint LR_CI_FK foreign key (Citizen_ID) references Citizen(Citizen_ID),
		constraint LR_L_FK foreign key (Library_Name) references Library(Name),
		constraint LR_L_FK2 foreign key (Library_Address) references Library(Address)
	);