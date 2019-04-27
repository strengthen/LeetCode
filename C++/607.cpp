__________________________________________________________________________________________________
drop table salesperson
create table salesperson (sales_id int,name varchar(25),salary int,commission_rate int,hire_date date)
 
insert into salesperson values (1,'John',100000,6,'2006-04-01')
insert into salesperson values (2,'Amy',120000,5,'2010-05-01')
insert into salesperson values (3,'Mark',65000,6,'2008-12-25')
insert into salesperson values (4,'Pam',25000,25,'2005-01-01')
insert into salesperson values (5,'Alex',50000,10,'2007-02-03')
 
Table: salesperson
 
+----------+------+--------+-----------------+-----------+
| sales_id | name | salary | commission_rate | hire_date |
+----------+------+--------+-----------------+-----------+
|   1      | John | 100000 |     6           | 4/1/2006  |
|   2      | Amy  | 120000 |     5           | 5/1/2010  |
|   3      | Mark | 65000  |     12          | 12/25/2008|
|   4      | Pam  | 25000  |     25          | 1/1/2005  |
|   5      | Alex | 50000  |     10          | 2/3/2007  |
+----------+------+--------+-----------------+-----------+
 
select * from salesperson
 
Table: company
+---------+--------+------------+
| com_id  |  name  |    city    |
+---------+--------+------------+
|   1     |  RED   |   Boston   |
|   2     | ORANGE |   New York |
|   3     | YELLOW |   Boston   |
|   4     | GREEN  |   Austin   |
+---------+--------+------------+
 
create table company(com_id int, name varchar(20),city varchar(20))
 
insert into company values (1,'Red','Boston')
insert into company values (2,'ORANGE','New York')
insert into company values (3,'YELLO','Boston')
insert into company values (4,'GREEN','Austin')
 
select * from company
 
Table: orders
 
+----------+----------+---------+----------+--------+
| order_id |  date    | com_id  | sales_id | amount |
+----------+----------+---------+----------+--------+
| 1        | 1/1/2014 |    3    |    4     | 100000 |
| 2        | 2/1/2014 |    4    |    5     | 5000   |
| 3        | 3/1/2014 |    1    |    1     | 50000  |
| 4        | 4/1/2014 |    1    |    4     | 25000  |
+----------+----------+---------+----------+--------+
 
create table orders (order_id int,[date] date,com_id int,sales_id int,amount int)
 
insert into orders values (1,'2014-01-01',3,4,100000)
insert into orders values (2,'2014-02-01',4,5,5000)
insert into orders values (3,'2014-03-01',1,1,50000)
insert into orders values (4,'2014-04-01',1,4,25000)
 
select * from orders
 
select name from salesperson where sales_id not in(
select sales_id from orders
where com_id = (select com_id from company where name='Red'))
 
 
select name from salesperson where sales_id not in
(
select o.sales_id from orders o left join company c on o.com_id=c.com_id
where c.name='Red'
)

__________________________________________________________________________________________________

__________________________________________________________________________________________________
