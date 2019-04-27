__________________________________________________________________________________________________
create table tree(id int,p_id int)
 
insert into tree values (1,null)
insert into tree values (2,1)
insert into tree values (3,1)
insert into tree values (4,2)
insert into tree values (5,2)
 
+----+------+
| id | p_id |
+----+------+
| 1  | null |
| 2  | 1    |
| 3  | 1    |
| 4  | 2    |
| 5  | 2    |
+----+------+
 
select id, 'ROOT' as Type from tree
where p_id is null
union
select id,'Leaf' as Type from tree
where id not in (select p_id from tree where p_id is not null)
union
select id, 'Inner' as Type from tree
where id in (select p_id from tree where p_id is not null)
and p_id is not null
__________________________________________________________________________________________________

__________________________________________________________________________________________________
