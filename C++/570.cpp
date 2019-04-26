__________________________________________________________________________________________________
drop table employee
create table employee (Id int, Name varchar(10),Department varchar(2), ManagerId int)
 
 
insert into employee values(101,'John','A',null)
insert into employee values(102,'Dan','A',101)
insert into employee values(103,'James','A',101)
insert into employee values(104,'Amy','A',101)
insert into employee values(105,'Anne','A',101)
insert into employee values(106,'Ron','B',101)
 
+------+----------+-----------+----------+
|Id    |Name 	  |Department |ManagerId |
+------+----------+-----------+----------+
|101   |John 	  |A 	      |null      |
|102   |Dan 	  |A 	      |101       |
|103   |James 	  |A 	      |101       |
|104   |Amy 	  |A 	      |101       |
|105   |Anne 	  |A 	      |101       |
|106   |Ron 	  |B 	      |101       |
+------+----------+-----------+----------+
 
select * from employee
 
with cte as(
select ManagerId from employee
group by ManagerId
having count(Id)>=5
) select Name from employee e join cte c on e.Id=c.ManagerId 
__________________________________________________________________________________________________

__________________________________________________________________________________________________
