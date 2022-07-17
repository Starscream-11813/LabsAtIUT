/*Task-1*/
create or replace function total_items_shipped(inYear int)
	return int
	is
	total_items int:=0;
	flag int:=1;
	begin
	select sum(QUANTITY) INTO total_items from ORDERS,ORDER_ITEMS
	where ORDERS.ORDER_ID=ORDER_ITEMS.ORDER_ID and ORDERS.ORDER_YEAR=inYear and ORDERS.STATUS=flag;
	return total_items;
	end;
	/

select total_items_shipped(2002) from dual;
select total_items_shipped(2006) from dual;
select total_items_shipped(2017) from dual;
/*
Task-1 Output:
2002 - 467
2006 - 339
2017 - 80
*/

/*Task-2*/
create or replace function most_sold_item(inYear int)
	return int
	is
	resID int;
	flag int:=1;
	begin
	select ITEM_ID into resID from
	(select ITEM_ID,SUM_QUANTITY from 
		(select ORDER_YEAR,ITEM_ID,sum(QUANTITY) as SUM_QUANTITY from ORDER_ITEMS,ORDERS where ORDERS.ORDER_ID=ORDER_ITEMS.ORDER_ID and ORDERS.STATUS=flag group by ORDER_YEAR,ITEM_ID order by ORDER_YEAR asc)
		where ORDER_YEAR=inYear order by SUM_QUANTITY desc)
	where rownum=1;
	return resID;
	end;
	/

select most_sold_item(2002) from dual;
select most_sold_item(2006) from dual;
select most_sold_item(2017) from dual;
/*
Task-2 Output:
2002 - 1
2006 - 3
2017 - 4
*/

/*Task-3*/
set serveroutput on;

create or replace function profit_estimation(inYear int)
	return numeric
	is
	revenue_generated numeric(10,2):=0;
	revenue_lost numeric(10,2):=0;
	flagGain int:=1;
	flagLoss int:=0;
	gainPercentage numeric(10,2):=0;
	lossPercentage numeric(10,2):=0;
	verdict varchar2(20);
	begin
	select sum(QUANTITY*PPU) INTO revenue_generated from ORDERS,ORDER_ITEMS
	where ORDERS.ORDER_ID=ORDER_ITEMS.ORDER_ID and ORDERS.ORDER_YEAR=inYear and ORDERS.STATUS=flagGain;
	select sum(QUANTITY*PPU) INTO revenue_lost from ORDERS,ORDER_ITEMS
	where ORDERS.ORDER_ID=ORDER_ITEMS.ORDER_ID and ORDERS.ORDER_YEAR=inYear and ORDERS.STATUS=flagLoss;
	gainPercentage:=((revenue_generated*100.0)/(revenue_generated+revenue_lost));
	lossPercentage:=((revenue_lost*100.0)/(revenue_generated+revenue_lost));
	IF gainPercentage>=50.0 and gainPercentage<=65.0 then
		verdict:='Average Year';
	ELSIF gainPercentage>=66.0 and gainPercentage<=79.0 then
		verdict:='Good Year';
	ELSIF gainPercentage>79.0 then
		verdict:='Excellent Year';
	ELSIF gainPercentage<50.0 then
		verdict:='A year of losses';
	ELSE
		verdict:='';
	end if;
	DBMS_OUTPUT.PUT_LINE('Verdict: '|| verdict);
	--DBMS_OUTPUT.PUT_LINE('gain: '|| gainPercentage);
	--DBMS_OUTPUT.PUT_LINE('loss: '|| lossPercentage);
	return revenue_generated;
	end;
	/

select profit_estimation(2002) from dual;
select profit_estimation(2006) from dual;
select profit_estimation(2017) from dual;
/*
Task-3 Output:
2002 - 3023 (Average Year)
2006 - 2405 (A year of losses)
2017 - 332 (A year losses)
*/