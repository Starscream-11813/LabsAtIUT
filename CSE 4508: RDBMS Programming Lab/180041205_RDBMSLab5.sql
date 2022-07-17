/*
A. Create a table called Occupation, with a field called ID. It should have another field called
“general” with options such as “Teacher” and a “Specific” field with values such as “School” or
“University” for the general profession of Teacher. Similarly, if the general profession is “Engineer”,
specific values could be “CSE” or “Mechanical”. Store the salary in a field as well. Insert values.
*/

CREATE TABLE Occupations(
    Citizen_ID NUMERIC,
    General_Field VARCHAR2(40),
    Specific_Field VARCHAR2(40),
    Salary NUMERIC,
    CONSTRAINT Occupation_PK PRIMARY KEY (Citizen_ID)
);

INSERT INTO Occupations VALUES(1,'Professor','Psychology',82345);
INSERT INTO Occupations VALUES(2,'Scientist','Neuroscience',11372);
INSERT INTO Occupations VALUES(3,'Author','Philosophy',11174);
INSERT INTO Occupations VALUES(4,'Professor','Biology',18382);
INSERT INTO Occupations VALUES(5,'Public Speaker','Politics',27193);
INSERT INTO Occupations VALUES(6,'Politician','Democratic',38289);
INSERT INTO Occupations VALUES(7,'Politician','Republican',83792);
INSERT INTO Occupations VALUES(8,'Public Speaker','Islamic Theology',72638);
INSERT INTO Occupations VALUES(9,'Public Speaker','Quranic Studies',35742);
INSERT INTO Occupations VALUES(10,'Author','Psychology',11575);

/*
1) Group using “general” and then “specific”. Here you should display the count of the number
of people in each general-specific subgroup, and order the displayed list according to this
count.
*/

/*SELECT
    General_Field,
    Specific_Field,
    COUNT(*) AS c
FROM
    Occupations
GROUP BY
    ROLLUP(General_Field, Specific_Field)
ORDER BY
    c;*/

SELECT
    General_Field,
    Specific_Field,
    COUNT(*) AS c
FROM
    Occupations
GROUP BY
    General_Field, Specific_Field
ORDER BY
    c;

/*
2) For each general group display the minimum, maximum and average salary.
*/

SELECT
    General_Field,
    MIN(Salary),
    MAX(Salary),
    AVG(Salary)
FROM
    Occupations
GROUP BY
    General_Field;

/*
3) Group according to general, and only display the general groups whose average salary is
greater or equal to the overall average salary of the entire table.
*/

SELECT
    General_Field
FROM
    Occupations
GROUP BY
    General_Field
HAVING
    AVG(Salary) >= (
        SELECT
            AVG(Salary)
        FROM
            Occupations
    );


CREATE VIEW exampleView AS
SELECT
    General_Field,
    AVG(Salary) AS Avg_Salary
FROM
    Occupations
GROUP BY
    General_Field;

/*
4) Group by general along with the average salary of each group, and save this grouped form
in a view. Using this view, select the name and average salary of the group with the highest
average salary.
*/

SELECT
    General_Field,
    Avg_Salary
FROM
    exampleView
WHERE
    Avg_Salary = (
        SELECT
            MAX(Avg_Salary)
        FROM
            exampleView
    );

/*
B. Create a table called Grades with fields ID, Department (CSE, EEE, etc), Programme (BSc, HD),
Course Code (CSE 4508, CSE 4551, etc) and Grade(A, A+, A-, etc)
*/

CREATE TABLE Grades(
    ID NUMERIC,
    Department VARCHAR2(10),
    Programme VARCHAR2(20),
    Course_Code VARCHAR2(10),
    Grade VARCHAR2(3),
    CONSTRAINT Grades_PK PRIMARY KEY (ID)
);

INSERT INTO Grades VALUES(1, 'CSE', 'BSc', 'CSE 4508', 'A+');
INSERT INTO Grades VALUES(2, 'EEE', 'MSc', 'EEE 4904', 'A');
INSERT INTO Grades VALUES(3, 'MCE', 'BSc', 'CSE 4505', 'A-');
INSERT INTO Grades VALUES(4, 'CEE', 'MSc', 'CEE 4912', 'A+');
INSERT INTO Grades VALUES(5, 'CSE', 'MSc', 'CSE 4834', 'A');
INSERT INTO Grades VALUES(6, 'EEE', 'PhD', 'EEE 4904', 'B');
INSERT INTO Grades VALUES(7, 'TVE', 'BTech', 'TVE 4746', 'B+');
INSERT INTO Grades VALUES(8, 'IPE', 'MTech', 'MCE 4385', 'C');
INSERT INTO Grades VALUES(9, 'BTM', 'BBA', 'CSE 4508', 'D');
INSERT INTO Grades VALUES(10, 'SWE', 'BSc', 'CSE 4834', 'F');

/*
1) Show the hierarchical count of the number of individuals, based on Department, then
Programme, then Course Code and then Grades. Order them alphabetically, based on
Department first, then Programme, and so on. (Rollup)
*/

SELECT
    Department,
    Programme,
    Course_Code,
    COUNT(*)
FROM
    Grades
GROUP BY
    ROLLUP(Department, Programme, Course_Code);

/*
2) Show the count across all possible combinations of these four dimensions (Cube)
*/

SELECT
    Department,
    Programme,
    Course_Code,
    Grade,
    COUNT(*)
FROM
    Grades
GROUP BY
    CUBE(Department, Programme, Course_Code, Grade);
