__________________________________________________________________________________________________
SELECT DISTINCT c1.seat_id FROM cinema AS c1 JOIN cinema AS c2 WHERE abs(c1.seat_id - c2.seat_id) = 1 and c1.free = True and c2.free = True 
order by c1.seat_id
__________________________________________________________________________________________________
select distinct a.seat_id 
from cinema a join cinema b 
on abs(a.seat_id - b.seat_id) = 1
and a.free = true
and b.free = true
order by a.seat_id
__________________________________________________________________________________________________
