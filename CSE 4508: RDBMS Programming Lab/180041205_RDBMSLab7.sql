SET SERVEROUTPUT ON SIZE 1000000

/*
1. Write a block of PL/SQL code which checks whether the current year is a leap year and prints
“Yes” or “No”. After this, it should print the immediate previous leap year, and the immediate
next one. [Do NOT simply hardcode and print 2016 and 2020]
*/

DECLARE thisyear NUMERIC;
BEGIN thisyear := (EXTRACT(YEAR FROM SYSDATE)); --2021;
IF (
    (
        MOD(thisyear, 4) = 0
        AND MOD(thisyear, 100) != 0
    )
    OR MOD(thisyear, 400) = 0
) THEN DBMS_OUTPUT.PUT_LINE('Yes, ' || thisyear || ' is a Leap Year.');
ELSE DBMS_OUTPUT.PUT_LINE('No, ' || thisyear || ' is not a Leap Year.');
END IF;
WHILE NOT (
    (
        MOD(thisyear, 4) = 0
        AND MOD(thisyear, 100) != 0
    )
    OR MOD(thisyear, 400) = 0
) LOOP thisyear := thisyear - 1;
END LOOP;
DBMS_OUTPUT.PUT_LINE(thisyear || ' is the immediate previous Leap Year.');
--DBMS_OUTPUT.PUT_LINE('2016' || ' is the immediate previous Leap Year.');
thisYear:=(EXTRACT(YEAR FROM SYSDATE));
WHILE NOT (
    (
        MOD(thisyear, 4) = 0
        AND MOD(thisyear, 100) != 0
    )
    OR MOD(thisyear, 400) = 0
) LOOP thisyear := thisyear + 1;
END LOOP;
DBMS_OUTPUT.PUT_LINE(thisyear || ' is the immediate next Leap Year.');
--DBMS_OUTPUT.PUT_LINE('2020' || ' is the immediate previous Leap Year.');
END;
/

/*
2. Write a PL/SQL function called times_table which takes two inputs: n, which indicates how
many times tables you have to print, and iter which indicates how far along the times table
you have to go. Then write a block of code to call this function, taking inputs of n and iter from
the user.
*/

CREATE
OR REPLACE PROCEDURE times_table(n IN NUMERIC, iter IN NUMERIC) AS
BEGIN
    FOR j IN 1..n LOOP
    DBMS_OUTPUT.PUT_LINE(j || ' Table');
    DBMS_OUTPUT.PUT_LINE('----------');
    FOR i IN 1..iter LOOP DBMS_OUTPUT.PUT_LINE(j || '*' || i || '=' || j * i);
END LOOP;
END LOOP;
END;
/

DECLARE n NUMERIC;
iter NUMERIC;
BEGIN n := '&n';
iter := '&iter';
times_table(n, iter);
END;
/

/*
3. A hacker stumbles onto a database table containing only two columns: Username
(varchar2) and Password_Length (number). Password_Length only contains a number,
such as 7 or 8, denoting how long the password of that username is. Write a block of PL/SQL,
using a function if necessary, which will first find the highest Password_Length from the table.
It will then find out how many permutations the hacker needs to go through to crack that
password. (The password only contains letters of the alphabet. You therefore have 26x2= 52
possibilities for each symbol of the password. However, no character can be repeated. So, the
correct answer, for a password of length 4, is: 52x51x50x49 = 6497400)
*/

CREATE TABLE randomTable(
    Username VARCHAR2(20), 
    Password_Length NUMERIC
);

INSERT INTO randomTable VALUES ('Messi', 4);
INSERT INTO randomTable VALUES ('Ronaldo', 3);
INSERT INTO randomTable VALUES ('Drogba', 2);

DECLARE res NUMERIC;
maxPasswordLength NUMERIC;
FUNCTION nPr(n IN NUMERIC, r IN NUMERIC) RETURN NUMERIC IS res NUMERIC;
BEGIN res := n;
FOR i IN 1..(r - 1) LOOP res := res * (n - i);
END LOOP;
RETURN res;
END;

BEGIN
--declare maxPasswordLength numeric;
SELECT
    max(Password_Length) INTO maxPasswordLength
FROM
    randomTable; 
DBMS_OUTPUT.PUT_LINE(nPr(52, maxPasswordLength));
END;
/

/*
4. Write a PL/SQL procedure that takes as input a string. The program will achieve two things:
a. Make a new string with a space added between every character of the input string.
b. Check if the original input string was a palindrome. Print “Yes” or “No” accordingly. [Hint
for both: substr]
*/

CREATE OR REPLACE PROCEDURE spaces_isPalindrome(s IN VARCHAR2) AS 
BEGIN FOR i IN 1..length(s) LOOP
    DBMS_OUTPUT.PUT(SUBSTR(s, i, 1) || ' ');
END LOOP;
FOR i IN 1..length(s) LOOP IF (
    SUBSTR(s, i, 1) != SUBSTR(s, length(s) - i + 1, 1)
) THEN DBMS_OUTPUT.PUT_LINE('No');
RETURN;
END IF;
END LOOP;
DBMS_OUTPUT.PUT_LINE('Yes');
END;
/

DECLARE s VARCHAR2(20);
BEGIN s := '&s';
spaces_isPalindrome(s);
END;
/