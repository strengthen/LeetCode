__________________________________________________________________________________________________
select
round(
    ifnull(
    (select count(*) from (select distinct requester_id, accepter_id from request_accepted) as A)
    /
    (select count(*) from (select distinct sender_id, send_to_id from friend_request) as B),
    0)
, 2) as accept_rate;　
__________________________________________________________________________________________________
select coalesce(round
(count(distinct requester_id, accepter_id)
/
count(distinct sender_id, send_to_id),2),
0)
as accept_rate
from friend_request, request_accepted
__________________________________________________________________________________________________
