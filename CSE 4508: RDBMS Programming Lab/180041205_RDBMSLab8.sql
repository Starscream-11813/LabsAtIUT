/*
A. You have an employee (ID, Name, Salary and Designation) table where salary is an attribute.
Try to increase it by 50% for employees having salary < 5000 but with designation being either “officer”
or “assistant-officer” and show how many rows got affected using an implicit cursor.
*/

CREATE TABLE employee(
    ID NUMERIC,
    Name VARCHAR2(30),
    Salary NUMERIC,
    Designation VARCHAR2(20)
);

INSERT INTO employee VALUES(1,'Abu Raihan Mostofa Kamal',9000,'Managing Director');
INSERT INTO employee VALUES(2,'Mahbubul Alam',7000,'General Manager');
INSERT INTO employee VALUES(3,'Sabbir Ahmed',6000,'Officer');
INSERT INTO employee VALUES(4,'Bakhtiar Hassan',4500,'Assistant Officer');

DECLARE nRows NUMERIC;
BEGIN
UPDATE
    employee
SET
    Salary = Salary + (0.5 * Salary)
WHERE
    Salary < 5000
    AND (
        Designation = 'Officer'
        OR Designation = 'Assistant Officer'
    );
IF SQL%NOTFOUND THEN 
DBMS_OUTPUT.PUT_LINE('0 rows were affected');
ELSIF SQL%FOUND THEN 
nRows := SQL%ROWCOUNT;
DBMS_OUTPUT.PUT_LINE(nRows || ' rows were affected');
END IF;
END;
/

/*
B. Create a table transactions (User_ID, Amount, T_Date) which stores all bank transactions of all the
users in our hypothetical bank. Fill up the table with a few transactions of your choice. Create another
table loan_type (Scheme, Installment_Number, Charge, Min_Trans). Loan_type will have the loan
schemes as shown below. For simplicity, you can store the Scheme as a number, such as 1, 2, or 3 instead
of “S-A/S-B/S-C”. Insert only those 3 specific rows into the table. Now, create a function that takes as
input a User_ID, calculates his/her total transactions, and checks against the loan_type table (use a cursor
here) to determine the correct present loan scheme for this person. Return and display the loan_scheme
number.
*/

CREATE TABLE transactions(
    User_ID NUMERIC,
    Amount NUMERIC,
    T_Date DATE
);

INSERT INTO transactions VALUES (1, 1300000, TO_DATE('2021/06/04', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (2, 6030000, TO_DATE('2021/05/23', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (3, 1510050, TO_DATE('2021/01/12', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (4, 550000, TO_DATE('2021/08/15', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (5, 870000, TO_DATE('2021/02/04', 'YYYY/MM/DD'));

CREATE TABLE loan_type(
    Scheme NUMERIC,
    Installment_Number NUMERIC,
    Charge VARCHAR2(5),
    Min_Trans NUMERIC
);

INSERT INTO loan_type VALUES (1, 30, '5%', 2000000);
INSERT INTO loan_type VALUES (2, 20, '10%', 1000000);
INSERT INTO loan_type VALUES (3, 15, '15%', 500000);

DECLARE CURSOR exCur(nTrans NUMERIC) IS
SELECT
    Scheme
FROM
    loan_type
WHERE
    nTrans >= Min_Trans;
loan_scheme NUMERIC := 0;
U_ID NUMERIC := 5;
res NUMERIC;
FUNCTION presentLoanScheme(UID IN NUMERIC) RETURN NUMERIC IS 
loan_scheme NUMERIC;
totalTransaction NUMERIC;
BEGIN
SELECT
    Amount INTO totalTransaction
FROM
    transactions
WHERE
    UID = User_ID;
open exCur(totalTransaction);
FETCH exCur INTO loan_scheme;
IF exCur%NOTFOUND THEN 
    loan_scheme := -1;
END IF;
CLOSE exCur;
RETURN loan_scheme;
END;


BEGIN 
res := presentLoanScheme(U_ID);
IF res=1 THEN
    DBMS_OUTPUT.PUT_LINE('Present Loan Scheme for person ' || U_ID || ' is: S-A');
ELSIF res=2 THEN
    DBMS_OUTPUT.PUT_LINE('Present Loan Scheme for person ' || U_ID || ' is: S-B');
ELSIF res=3 THEN
    DBMS_OUTPUT.PUT_LINE('Present Loan Scheme for person ' || U_ID || ' is: S-C');
ELSE
    DBMS_OUTPUT.PUT_LINE('Present Loan Scheme for person ' || U_ID || ' is: N/A');
END IF;
END;
/
 