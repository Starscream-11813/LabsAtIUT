/*
Task A:
1. First implement the above system in SQL.
*/

CREATE TABLE Citizens(
    Citizen_ID NUMERIC,
    Citizen_Name VARCHAR2(40),
    Date_of_Birth DATE,
    CONSTRAINT Citizens_PK PRIMARY KEY (Citizen_ID)
);

CREATE TABLE Address(
    Citizen_ID NUMERIC,
    Division VARCHAR2(30),
    District varchar2(30),
    Zip_Code NUMERIC,
    CONSTRAINT Address_PK PRIMARY KEY (Citizen_ID),
    CONSTRAINT A_C_FK FOREIGN KEY (Citizen_ID) REFERENCES Citizens(Citizen_ID)
);

CREATE TABLE Occupation(
    Citizen_ID NUMERIC,
    General_Field VARCHAR2(40),
    Specific_Field varchar2(40),
    Salary NUMERIC,
    CONSTRAINT Occ_C_FK FOREIGN KEY (Citizen_ID) REFERENCES Citizens(Citizen_ID)
);

/*
2. Insert some data in all relevant tables created. (at least 10 entries)
*/

INSERT INTO Citizens VALUES(1,'Jordan B. Peterson',TO_DATE('1962/06/12', 'YYYY/MM/DD'));
INSERT INTO Citizens VALUES(2,'Sam Harris',TO_DATE('1967/04/09', 'YYYY/MM/DD'));
INSERT INTO Citizens VALUES(3,'Friedrich Nietzsche',TO_DATE('1844/10/15', 'YYYY/MM/DD'));
INSERT INTO Citizens VALUES(4,'Bret Weinstein',TO_DATE('1969/02/21', 'YYYY/MM/DD'));
INSERT INTO Citizens VALUES(5,'Douglas Murray',TO_DATE('1979/07/16', 'YYYY/MM/DD'));
INSERT INTO Citizens VALUES(6,'Joseph R. Biden',TO_DATE('1942/11/20', 'YYYY/MM/DD'));
INSERT INTO Citizen VALUES(7,'Donald J. Trump',TO_DATE('1946/06/14', 'YYYY/MM/DD'));
INSERT INTO Citizens VALUES(8,'Ahmed Deedat',TO_DATE('1918/07/01', 'YYYY/MM/DD'));
INSERT INTO Citizens VALUES(9,'Nouman Ali Khan',TO_DATE('1978/05/04', 'YYYY/MM/DD'));
INSERT INTO Citizens VALUES(10,'Fyodor Dostoevsky',TO_DATE('1821/11/11', 'YYYY/MM/DD'));

INSERT INTO Address VALUES(1,'Dhaka','Faridpur',7810);
INSERT INTO Address VALUES(2,'Chittagong','Comilla',3501);
INSERT INTO Address VALUES(3,'Dhaka','Gopalganj',8100);
INSERT INTO Address VALUES(4,'Khulna','Magura',7600);
INSERT INTO Address VALUES(5,'Barisal','Jhalokati',8400);
INSERT INTO Address VALUES(6,'Rajshahi','Pabna',6602);
INSERT INTO Address VALUES(7,'Sylhet','Habiganj',7903);
INSERT INTO Address VALUES(8,'Rangpur','Panchagarh',5000);
INSERT INTO Address VALUES(9,'Mymensingh','Sherpur',2100);
INSERT INTO Address VALUES(10,'Chittagong','Khagrachari',4400);

INSERT INTO Occupation VALUES(1,'Professor','University of Toronto','82345');
INSERT INTO Occupation VALUES(2,'Neuroscientist','University of California, Los Angeles','11372');
INSERT INTO Occupation VALUES(3,'Author','Philosophy','11174');
INSERT INTO Occupation VALUES(4,'Professor','Evergreen State College','18382');
INSERT INTO Occupation VALUES(5,'Commentator','Politics','27193');
INSERT INTO Occupation VALUES(6,'President','United States Government','38289');
INSERT INTO Occupation VALUES(7,'Businessman','The Trump Organization','83792');
INSERT INTO Occupation VALUES(8,'Public Speaker','Islamic Theology','72638');
INSERT INTO Occupation VALUES(9,'Arabic Instructor','Bayyinah Institute for Quranic Studies','35742');
INSERT INTO Occupation VALUES(10,'Novelist','Human Psychology','11575');

/*
3. Answer the following (should involve Join operations and subqueries):
• Display the name, citizen ID, and salary of the top 5 highest paid individuals in the database
*/

SELECT
    Citizen_ID,
    Citizen_Name,
    Salary
FROM
    (
        SELECT
            *
        FROM
            Citizens
            NATURAL JOIN Occupation
        ORDER BY
            Salary DESC
    )
WHERE
    rownum <= 5;

/*
• Display the name, date of birth, district and division of all individuals whose salary is greater than
the average salary of school teachers (Professors)
*/

SELECT
    Citizens.Citizen_Name,
    Citizens.Date_of_Birth,
    Address.District,
    Address.Division
FROM
    Citizens
    NATURAL JOIN Address
WHERE
    Citizen_ID IN (
        SELECT
            Citizen_ID
        FROM
            Occupation
        WHERE
            Salary > (
                SELECT
                    AVG(Salary) avg_salary
                FROM
                    Occupation
                WHERE
                    General_Field = 'Professor'
            )
    );

/*
• Count the number of such people (the ones described in the immediately previous query) who
are from Dhaka (Hint: another level of subquery)
*/

SELECT
    count(*)
FROM
    (
        SELECT
            Citizens.Citizen_Name,
            Citizens.Date_of_Birth,
            Address.District,
            Address.Division
        FROM
            Citizens
            NATURAL JOIN Address
        WHERE
            Citizen_ID IN (
                SELECT
                    Citizen_ID
                FROM
                    Occupation
                WHERE
                    Salary > (
                        SELECT
                            AVG(Salary) avg_salary
                        FROM
                            Occupation
                        WHERE
                            General_Field = 'Professor'
                    )
            )
    )
WHERE
    Division = 'Dhaka';

/*
Task B:
1. Show with appropriate example the use of the following built-in functions:
CONCANT:
*/

SELECT
    Citizen_ID,
    CONCAT(
        CONCAT(CONCAT(District, CONCAT('-', Zip_Code)), ', '),
        Division
    ) AS Permanent_Address
FROM
    Address;

/*
INITCAP:
*/

INSERT INTO Citizens VALUES(11,INITCAP('thomas sowell'),TO_DATE('1930/06/30', 'YYYY/MM/DD'));

/*
INSTR:
*/

SELECT
    Citizen_ID,
    INSTR(Specific_Field, 'University') AS isAcademic
FROM
    Occupation;

/*
LOWER:
*/

SELECT
    LOWER(Citizen_Name) AS Lowercase_Name
FROM
    Citizens;

/*
UPPER:
*/

SELECT
    UPPER(Division) AS Uppercase_Division
FROM
    Address;

/*
LENGTH:
*/

SELECT
    LENGTH(Salary) AS Salary_Figure
FROM
    Occupation;

/*
LPAD:
*/

SELECT
    LPAD(Citizen_Name, LENGTH(Citizen_Name) + 4, 'Mr. ') AS MISTER_NAME
FROM
    Citizens;

/*
RPAD:
*/

SELECT
    RPAD(Citizen_Name, LENGTH(Citizen_Name) + 6, ' (PhD)') AS Name_Doctorate
FROM
    Citizens
WHERE
    Citizen_ID IN (
        SELECT
            Citizen_ID
        FROM
            Occupation
        WHERE
            General_Field = 'Professor'
    );

/*
LTRIM:
*/

SELECT
    LTRIM(Citizen_Name, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ') FirstName_NoLeadingUppercases
FROM
    Citizens;

/*
RTRIM:
*/

SELECT
    RTRIM(Citizen_Name, 'bcdfghjklmnpqrstvwxyz') LastName_NoTrailingConsonants
FROM
    Citizens;

/*
SUBSTR:
*/

SELECT
    SUBSTR(Citizen_Name, 1, INSTR(Citizen_Name, ' ') -1) FirstName
FROM
    Citizens;

/*
COUNT:
*/

SELECT
    COUNT(*) AS Septuagenarians_And_Above
FROM
    Citizens
WHERE
    Date_of_Birth <= TO_DATE('1950/01/01', 'YYYY/MM/DD');