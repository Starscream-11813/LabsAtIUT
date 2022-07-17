/*1*/
select count(CUST_NAME)
from CUSTOMER
where CUST_NAME like 'S%';

/*2*/
select AGENT_NAME
from AGENTS
where AGENT_CODE=(select AGENT_CODE
from CUSTOMER
where CUST_CODE='C00013');

/*3*/
select CUST_NAME
from CUSTOMER
where OPENING_AMT=(select max(OPENING_AMT)
from CUSTOMER);

/*4*/
select CUST_NAME, AGENT_NAME
from CUSTOMER, AGENTS
where CUSTOMER.AGENT_CODE=AGENTS.AGENT_CODE
order by AGENT_NAME;

/*5*/
select CUST_NAME
from CUSTOMER
where AGENT_CODE=(select AGENT_CODE
from AGENTS
where AGENT_NAME='Santakumar');

/*6*/
select AGENT_NAME, count(CUST_NAME)
from AGENTS, CUSTOMER
where CUSTOMER.AGENT_CODE=AGENTS.AGENT_CODE
group by AGENT_NAME;

/*7*/
select CUST_NAME
from CUSTOMER
where CUST_CITY='London' and OUTSTANDING_AMT=(select min(OUTSTANDING_AMT)
    from CUSTOMER
    where CUST_CITY='London');

/*8*/
select CUST_NAME
from CUSTOMER
where CUST_NAME like 'A%';

/*9*/
select count(CUST_CODE)
from CUSTOMER
where WORKING_AREA='Chennai';

/*10*/
select count(CUST_CODE)
from CUSTOMER
where CUST_CITY='London';

/*11*/
select CUST_CITY, count(CUST_CODE)
from CUSTOMER
group by CUST_CITY;

/*12*/
select CUST_CITY
from (select CUST_CITY, count(CUST_CODE) as CC
    from CUSTOMER
    group by CUST_CITY)
where CC=(select max(CC)
from (select CUST_CITY, count(CUST_CODE) as CC
    from CUSTOMER
    group by CUST_CITY));

/*13*/
select count(CUST_CODE)
from CUSTOMER
where CUST_NAME like '%i%';

/*14*/
select count(distinct CUST_CITY)
from CUSTOMER
where CUST_CITY like '%ew%';

/*15*/
select GRADE, count(CUST_CODE)
from CUSTOMER
group by GRADE;

/*16*/
select avg(OUTSTANDING_AMT)
from CUSTOMER
where CUST_CITY='New York';

/*17*/
/*Unsure*/
select GRADE, sum(OUTSTANDING_AMT)
from (SELECT *
    from CUSTOMER
    where grade in (select grade
    from CUSTOMER
    group by GRADE
    having count(CUST_CODE)>=3))
where OPENING_AMT>6000
group by GRADE;





