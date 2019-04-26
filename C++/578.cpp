__________________________________________________________________________________________________
drop table survey_log
create table survey_log (uid int,action varchar(25),question_id int,answer_id int,q_num int,timestamp int)
 
insert into survey_log values(5,'show',285,null,1,123)
insert into survey_log values(5,'answer',285,124124,1,124)
insert into survey_log values(5,'show',369,null,2,125)
insert into survey_log values(5,'skip',369,null,2,126)
 
select * from survey_log
 
with cte1 as(
select question_id,count(*) as answer_cnt from survey_log
where action='answer'
group by question_id
),cte2 as(
select question_id,count(*) as question_cnt from survey_log
where action='show'
group by question_id
)select top 1 c1.question_id
from cte1 c1 join cte2  c2 on c1.question_id=c2.question_id
order by (answer_cnt/question_cnt) desc
 
select top 1 question_id from 
(
select question_id,
sum(case when action='answer' then 1 else 0 end) as answer_cnt,
sum(case when action='show' then 1 else 0 end) as question_cnt
from survey_log
group by question_id
) as tpl
order by answer_cnt/question_cnt desc
 
select top 1 question_id
from survey_log
group by question_id
order by count(answer_id)/sum(case when action='show' then 1 else 0 end) desc
__________________________________________________________________________________________________

__________________________________________________________________________________________________
