/*
1. Create one tablespace myspace and one user. And assign the tablespace to the new user.
Create a number of objects (4 tables: T1, T2, T3 and T4) and assign one table’s data (T4) to
a different tablespace myspace2.
*/

CREATE TABLESPACE myspace DATAFILE 'myspace_data1.dbf' SIZE 1m;

CREATE USER user1 identified BY test123;

ALTER USER user1 DEFAULT TABLESPACE myspace;
ALTER USER user1 QUOTA UNLIMITED ON myspace;

CREATE TABLE T1(
    s_id NUMERIC, 
    cgpa NUMERIC(3,2)
) 
TABLESPACE myspace;

CREATE TABLE T2(
    t_id NUMERIC, 
    dept_id NUMERIC
) 
TABLESPACE myspace;

CREATE TABLE T3(
    zip NUMERIC, 
    address VARCHAR2(30)
) 
TABLESPACE myspace;

CREATE TABLE T4(
    ign VARCHAR2(20), 
    mmr NUMERIC
) 
TABLESPACE myspace;

CREATE TABLESPACE myspace2 DATAFILE 'myspace_data2.dbf' SIZE 1m;

ALTER TABLE T4 MOVE TABLESPACE myspace2;

/*
2. Remember the following definitions:
a. A subquery in the WHERE clause of a SELECT statement is also called a nested
subquery.
b. A subquery in the FROM clause of a SELECT statement is also called an inline view.
Now create a number of related tables at your own choice and show the functionality of a
nested subquery and an inline view.
*/

CREATE TABLE candidates(
    candidate_id NUMERIC,
    name VARCHAR2(20),
    CONSTRAINT c_PK PRIMARY KEY (candidate_id)
);
CREATE TABLE voters(
    voter_id NUMERIC,
    candidate_id NUMERIC,
    CONSTRAINT v_CPK PRIMARY KEY (voter_id, candidate_id),
    CONSTRAINT vo_ca_FK FOREIGN KEY (candidate_id) REFERENCES candidates(candidate_id)
);

INSERT INTO candidates values(1,'Donald J. Trump');

INSERT INTO candidates values(2,'Joseph R. Biden');

INSERT INTO candidates values(3,'Jeb Bush');

INSERT INTO candidates values(4,'Bernie Sanders');

INSERT INTO candidates values(5,'Kanye West');

INSERT INTO voters values(1,1);

INSERT INTO voters values(2,4);

INSERT INTO voters values(3,3);

INSERT INTO voters values(4,1);

INSERT INTO voters values(5,2);

/*
A nested subquery to determine the VOTER_ID of voters who voted for a Republican candidate.
*/
SELECT
    voter_id
FROM
    voters
WHERE
    candidate_id IN (
        SELECT
            candidate_id
        FROM
            candidates
        WHERE
            Name = 'Donald J. Trump'
            OR Name = 'Jeb Bush'
    );

/*
An inline view subquery to determine the winner of the election.
*/

SELECT
    cc.Name
FROM
    (
        SELECT
            candidate_id,
            COUNT(*) AS c
        FROM
            voters
        GROUP BY
            candidate_id
        ORDER BY
            c DESC
    ) vv,
    candidates cc
WHERE
    rownum <= 1
    AND cc.candidate_id = vv.candidate_id;

/*
3. Using the following two tables, show the commands and outputs of Inner Join, Outer
Join, Left Join and Right Join. The outputs might be different based on your query.
Show the difference between Left and Right Outer joins.
Also demonstrate the difference between Inner Join and Natural Join.
*/

CREATE TABLE customers(
    customer_id NUMERIC,
    last_name VARCHAR2(10),
    first_name VARCHAR2(10),
    CONSTRAINT customers_PK PRIMARY KEY (customer_id)
);

CREATE TABLE orders(
    order_id NUMERIC,
    customer_id NUMERIC,
    order_date DATE,
    CONSTRAINT orders_PK PRIMARY KEY (order_id),
    CONSTRAINT o_c_FK FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);

INSERT INTO customers VALUES(4000, 'Jackson', 'Joe');
INSERT INTO customers VALUES(5000, 'Smith', 'Jane');
INSERT INTO customers VALUES(6000, 'Ferguson', 'Samantha');
INSERT INTO customers VALUES(7000, 'Reynolds', 'Allen');
INSERT INTO customers VALUES(8000, 'Anderson', 'Paige');
INSERT INTO customers VALUES(9000, 'Johnson', 'Derek');

INSERT INTO orders VALUES(1, 7000, TO_DATE('2016/04/18', 'YYYY/MM/DD'));
INSERT INTO orders VALUES(2, 5000, TO_DATE('2016/04/18', 'YYYY/MM/DD'));
INSERT INTO orders VALUES(3, 8000, TO_DATE('2016/04/19', 'YYYY/MM/DD'));
INSERT INTO orders VALUES(4, 4000, TO_DATE('2016/04/20', 'YYYY/MM/DD'));
INSERT INTO orders VALUES(5, NULL, TO_DATE('2016/05/01', 'YYYY/MM/DD'));

SELECT
    *
FROM
    customers
    INNER JOIN orders ON customers.customer_id = orders.customer_id;
/*
CUSTOMER_ID LAST_NAME  FIRST_NAME   ORDER_ID CUSTOMER_ID ORDER_DAT
----------- ---------- ---------- ---------- ----------- ---------
       7000 Reynolds   Allen               1        7000 18-APR-16
       5000 Smith      Jane                2        5000 18-APR-16
       8000 Anderson   Paige               3        8000 19-APR-16
       4000 Jackson    Joe                 4        4000 20-APR-16
*/

SELECT
    *
FROM
    customers
    FULL OUTER JOIN orders ON customers.customer_id = orders.customer_id;

/*
CUSTOMER_ID LAST_NAME  FIRST_NAME   ORDER_ID CUSTOMER_ID ORDER_DAT
----------- ---------- ---------- ---------- ----------- ---------
       4000 Jackson    Joe                 4        4000 20-APR-16
       5000 Smith      Jane                2        5000 18-APR-16
       6000 Ferguson   Samantha
       7000 Reynolds   Allen               1        7000 18-APR-16
       8000 Anderson   Paige               3        8000 19-APR-16
       9000 Johnson    Derek
                                           5             01-MAY-16
*/

SELECT
    *
FROM
    customers
    LEFT JOIN orders ON customers.customer_id = orders.customer_id;

/*
CUSTOMER_ID LAST_NAME  FIRST_NAME   ORDER_ID CUSTOMER_ID ORDER_DAT
----------- ---------- ---------- ---------- ----------- ---------
       4000 Jackson    Joe                 4        4000 20-APR-16
       5000 Smith      Jane                2        5000 18-APR-16
       6000 Ferguson   Samantha
       7000 Reynolds   Allen               1        7000 18-APR-16
       8000 Anderson   Paige               3        8000 19-APR-16
       9000 Johnson    Derek
*/

SELECT
    *
FROM
    customers
    RIGHT JOIN orders ON customers.customer_id = orders.customer_id;
    
/*
CUSTOMER_ID LAST_NAME  FIRST_NAME   ORDER_ID CUSTOMER_ID ORDER_DAT
----------- ---------- ---------- ---------- ----------- ---------
       7000 Reynolds   Allen               1        7000 18-APR-16
       5000 Smith      Jane                2        5000 18-APR-16
       8000 Anderson   Paige               3        8000 19-APR-16
       4000 Jackson    Joe                 4        4000 20-APR-16
                                           5             01-MAY-16
*/

SELECT
    *
FROM
    customers
    LEFT OUTER JOIN orders ON customers.customer_id = orders.customer_id;

/*
CUSTOMER_ID LAST_NAME  FIRST_NAME   ORDER_ID CUSTOMER_ID ORDER_DAT
----------- ---------- ---------- ---------- ----------- ---------
       4000 Jackson    Joe                 4        4000 20-APR-16
       5000 Smith      Jane                2        5000 18-APR-16
       6000 Ferguson   Samantha
       7000 Reynolds   Allen               1        7000 18-APR-16
       8000 Anderson   Paige               3        8000 19-APR-16
       9000 Johnson    Derek
*/

SELECT
    *
FROM
    customers
    RIGHT OUTER JOIN orders ON customers.customer_id = orders.customer_id;

/*
CUSTOMER_ID LAST_NAME  FIRST_NAME   ORDER_ID CUSTOMER_ID ORDER_DAT
----------- ---------- ---------- ---------- ----------- ---------
       7000 Reynolds   Allen               1        7000 18-APR-16
       5000 Smith      Jane                2        5000 18-APR-16
       8000 Anderson   Paige               3        8000 19-APR-16
       4000 Jackson    Joe                 4        4000 20-APR-16
                                           5             01-MAY-16
*/

/*
Left Outer Join vs Right Outer Join:
The main difference is the inclusion of non-matched rows. LEFT outer join includes
unmatched rows from the table written on the left of the join predicate. On the contrary,
RIGHT outer join includes all the matching rows and unmatched rows from the right side
of the table.
Essentially, result of a LEFT outer join is INNER JOIN + unmatched rows from the LEFT table 
and RIGHT OUTER join is INNER JOIN + unmatched rows from the right-hand side table.
*/


SELECT
    *
FROM
    customers
    INNER JOIN orders ON orders.customer_id = customers.customer_id;

/*
CUSTOMER_ID LAST_NAME  FIRST_NAME   ORDER_ID CUSTOMER_ID ORDER_DAT
----------- ---------- ---------- ---------- ----------- ---------
       7000 Reynolds   Allen               1        7000 18-APR-16
       5000 Smith      Jane                2        5000 18-APR-16
       8000 Anderson   Paige               3        8000 19-APR-16
       4000 Jackson    Joe                 4        4000 20-APR-16
*/

SELECT
    *
FROM
    customers
    NATURAL JOIN orders;

/*

CUSTOMER_ID LAST_NAME  FIRST_NAME   ORDER_ID ORDER_DAT
----------- ---------- ---------- ---------- ---------
       4000 Jackson    Joe                 4 20-APR-16
       5000 Smith      Jane                2 18-APR-16
       7000 Reynolds   Allen               1 18-APR-16
       8000 Anderson   Paige               3 19-APR-16
*/

/*
Inner Join vs Natural Join:
In NATURAL join there is a common column and joining is 
done for matching values of that column, whereas in INNER join there 
may be no common column so a column is explicitly specified along which 
the joining has to be performed. If we compare the outputs of INNER Join
and NATURAL join, we can see that the CUSTOMER_ID column is duplicated in
case of INNER Join, but not in case of NATURAL Join. The matching attribute, 
which is CUSTOMER_ID, is present as a single column.
*/