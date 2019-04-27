__________________________________________________________________________________________________
select America,Asia, Europe from

(

select @row_id:=@row_id+1 as row_id, name as America

from student, (select @row_id:=0) r

where continent = 'America'

order by name 

) ame

 left join (

select @row_id:=@row_id+1 as row_id, name as Asia

from student, (select @row_id:=0) r

where continent = 'Asia'

order by name 

) asi on ame.row_id = asi.row_id

 left join (

select @row_id:=@row_id+1 as row_id, name as Europe

from student, (select @row_id:=0) r

where continent = 'Europe'

order by name 

) eur on eur. row_id = ame.row_id
__________________________________________________________________________________________________

__________________________________________________________________________________________________
