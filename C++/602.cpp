__________________________________________________________________________________________________
SELECT t.id, COUNT(t.id) AS num FROM
(SELECT requester_id AS id FROM request_accepted
UNION ALL
SELECT accepter_id AS id FROM request_accepted) AS t
GROUP BY t.id
ORDER BY num DESC LIMIT 1;
__________________________________________________________________________________________________

select  top 1 id1, count(*) as num 
from 
(
select requester_id as id1, accepter_id as id2 from request_accepted
union all
select accepter_id as id1, requester_id as id2 from request_accepted
) as tpl
group by id1
order by num desc
__________________________________________________________________________________________________
