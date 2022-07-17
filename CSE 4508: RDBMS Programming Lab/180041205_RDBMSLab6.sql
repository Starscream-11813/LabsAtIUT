SET SERVEROUTPUT ON SIZE 1000000

-- A block that does nothing.
BEGIN NULL;
END;
/

-- A block that prints 'Hello, World!'
BEGIN DBMS_OUTPUT.PUT_LINE('Hello, World!');
END;
/

-- scanf: Hello, string!
DECLARE string VARCHAR2(30);
BEGIN string := '&i'; 
DBMS_OUTPUT.PUT_LINE('Hello, '|| string || '!'); 
END;
/

-- " Delimiter
CREATE TABLE "CaseSensitiveTable"(
    "CaseSensitiveID" NUMERIC, 
    string VARCHAR2(10)
);

INSERT INTO "CaseSensitiveTable" VALUES(1,'Hello!');

select * from "CaseSensitiveTable";

-- Subtyping (?)
-- PACKAGE dummyPackage IS 
-- SUBTYPE myBoolean IS BOOLEAN;
-- END dummyPackage;

-- CREATE TABLE dummyTable(
--     boolVar dummyPackage.myBoolean
-- );

-- CHAR vs VARCHAR2
DECLARE c CHAR (32767) := 'Hello';
string VARCHAR2(32767) := 'Hello';
BEGIN DBMS_OUTPUT.PUT_LINE('c is [' || LENGTH(c) || ']');
DBMS_OUTPUT.PUT_LINE('string is [' || LENGTH(string) || ']');
string := string || ' ';
DBMS_OUTPUT.PUT_LINE('string is [' || LENGTH(string) || ']');
END;
/
/*
c is [32767]
string is [5]
string is [6]
*/

-- Composite Datatypes
DECLARE type demo_record_type IS RECORD(
        id number DEFAULT 1,
        string VARCHAR2(10) := 'One'
    );
demo demo_record_type;
BEGIN DBMS_OUTPUT.PUT_LINE('[' || demo.id || '][' || demo.string || ']');
END;
/
/*
[1][One]
*/

-- Conditional Statements
DECLARE x NUMERIC;
BEGIN x := 10;
    IF (x = 0)
    THEN DBMS_OUTPUT.PUT_LINE('The value of x is 0');
         ELSIF(x BETWEEN 1 AND 10)
    THEN DBMS_OUTPUT.PUT_LINE('The value of x is between 1 and 10');
    ELSE DBMS_OUTPUT.PUT_LINE('The value of x is greater than 10');
END IF;
END;
/
/*
The value of x is between 1 and 10
*/

CREATE TABLE Students(
    Name VARCHAR2(10), 
    cgpa NUMERIC(3,2)
);

INSERT INTO Students VALUES ('Bashar', 4.00);
INSERT INTO Students VALUES ('Sameen', 3.46);
INSERT INTO Students VALUES ('Nafis', 3.73);
INSERT INTO Students VALUES ('Adib', 3.50);

DECLARE cgpa NUMERIC;
x VARCHAR2(10) := 'Bashar';
BEGIN
    SELECT MAX(cgpa)
    INTO cgpa
    FROM Students
    WHERE Name = x;
          IF (cgpa > 3.78)
    THEN DBMS_OUTPUT.PUT_LINE('Brilliant');
         ELSIF (cgpa BETWEEN 3.5 AND 3.78)
    THEN DBMS_OUTPUT.PUT_LINE('Mid Level');
    ELSE DBMS_OUTPUT.PUT_LINE('Poor');
END IF;
END;
/

-- Simple CASE Statements
DECLARE selector number := 1;
BEGIN
    CASE selector
        WHEN 0
        THEN DBMS_OUTPUT.PUT_LINE('Case 0!');
        WHEN 1
        THEN DBMS_OUTPUT.PUT_LINE('Case 1!');
        ELSE DBMS_OUTPUT.PUT_LINE('No match!');
    END CASE;
END;
/
/*
Case 1!
*/

-- Searched CASE Statements
SELECT
    Name,
    (
        CASE
            WHEN cgpa < 3.5 THEN 'Low'
            WHEN cgpa BETWEEN 3.5 AND 3.7 THEN 'medium'
            WHEN cgpa > 3.7 THEN 'high'
            ELSE 'N/A'
        END
    ) cgpa
FROM
    Students
ORDER BY
    Name;
/*
NAME       CGPA
---------- ------
Adib       medium
Bashar     high
Nafis      high
Sameen     Low
*/

-- LOOP EXIT
DECLARE x NUMERIC := 10;
BEGIN LOOP DBMS_OUTPUT.PUT_LINE(x);
x := x + 10;
IF x > 50 THEN EXIT;
END IF;
END LOOP;
DBMS_OUTPUT.PUT_LINE('After Exit x is: ' || x);
END;
/
/*
10
20
30
40
50
After Exit x is: 60
*/

-- LOOP EXIT WHEN
DECLARE x NUMERIC := 10;
BEGIN LOOP DBMS_OUTPUT.PUT_LINE(x);
x := x + 10;
EXIT
WHEN x > 50;
END LOOP;
DBMS_OUTPUT.PUT_LINE('After Exit x is: ' || x);
END;
/
/*
10
20
30
40
50
After Exit x is: 60
*/

-- FOR LOOP
DECLARE a NUMERIC;
BEGIN FOR a IN 10..20 LOOP DBMS_OUTPUT.PUT_LINE('Value of a: ' || a);
END LOOP;
END;
/
/*
Value of a: 10
Value of a: 11
Value of a: 12
Value of a: 13
Value of a: 14
Value of a: 15
Value of a: 16
Value of a: 17
Value of a: 18
Value of a: 19
Value of a: 20
*/

-- REVERSE FOR LOOP
DECLARE a NUMERIC;
BEGIN FOR a IN REVERSE 10..20 LOOP DBMS_OUTPUT.PUT_LINE('Value OF a: ' || a);
END LOOP;
END;
/
/*
Value OF a: 20
Value OF a: 19
Value OF a: 18
Value OF a: 17
Value OF a: 16
Value OF a: 15
Value OF a: 14
Value OF a: 13
Value OF a: 12
Value OF a: 11
Value OF a: 10
*/

-- WHILE LOOP
DECLARE a NUMERIC := 10;
BEGIN WHILE a < 20 LOOP DBMS_OUTPUT.PUT_LINE('value OF a: ' || a);
a := a + 1;
END LOOP;
END;
/
/*
value OF a: 10
value OF a: 11
value OF a: 12
value OF a: 13
value OF a: 14
value OF a: 15
value OF a: 16
value OF a: 17
value OF a: 18
value OF a: 19
*/

-- Datatype Indicator
DECLARE
sturec Students%ROWTYPE;
Name Students.Name%TYPE;
BEGIN
--sturec.Name := NULL; -- this works, null constraint is not inherited
sturec.Name := 'John Doe';
sturec.cgpa := 3.87; -- this works, check constraint is not inherited
-- the default value is not inherited in the following
DBMS_OUTPUT.PUT_LINE('sturec.Name: ' || sturec.Name);
END;
/
/*
sturec.Name: John Doe
*/

-- Procedure with IN and OUT parameter
CREATE
OR REPLACE PROCEDURE FUNC1(Name IN VARCHAR2, cgpa OUT NUMERIC) 
AS 
BEGIN
SELECT
    MAX(cgpa) INTO cgpa
FROM
    Students
WHERE
    Name = Name;
END;
/ 
---now call it from annonymous block--
DECLARE cgpa NUMERIC(3,2);
BEGIN FUNC1('Bashar', cgpa);
DBMS_OUTPUT.PUT_LINE(cgpa);
END;
/
/*
4
*/

-- Parameter Positions
-- Positional Notation
DECLARE
res NUMERIC:=0;
FUNCTION ADD_THREE_NUMBERS(a IN NUMERIC, b IN NUMERIC, c IN NUMERIC) RETURN NUMERIC IS res NUMERIC;
BEGIN res := a + b + c;
RETURN res;
END;

BEGIN
DBMS_OUTPUT.PUT_LINE(ADD_THREE_NUMBERS(3,4,5));
END;
/
/*
12
*/

-- Named Notation
DECLARE
res NUMERIC:=0;
FUNCTION ADD_THREE_NUMBERS(a IN NUMERIC, b IN NUMERIC, c IN NUMERIC) RETURN NUMERIC IS res NUMERIC;
BEGIN res := a + b + c;
RETURN res;
END;

BEGIN
DBMS_OUTPUT.PUT_LINE(ADD_THREE_NUMBERS(a=>3,b=>4,c=>5));
END;
/
/*
12
*/

-- Mixed Notation
DECLARE
res NUMERIC:=0;
FUNCTION ADD_THREE_NUMBERS(a IN NUMERIC, b IN NUMERIC, c IN NUMERIC) RETURN NUMERIC IS res NUMERIC;
BEGIN res := a + b + c;
RETURN res;
END;

BEGIN
DBMS_OUTPUT.PUT_LINE(ADD_THREE_NUMBERS(3,b=>4,c=>5));
END;
/
/*
12
*/
