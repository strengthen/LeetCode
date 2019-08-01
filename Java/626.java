__________________________________________________________________________________________________
# Write your MySQL query statement below
select (case
       when id%2 != 0 and id != counts then id+1   
       when id%2 != 0 and id = counts then id
       else id-1 end) as id,student
       from seat, (select count(*) as counts from seat) as s order by id asc
__________________________________________________________________________________________________
SELECT
    s.id,
    s.student
FROM
    (SELECT id - 1 AS id, student FROM seat WHERE id%2 = 0
     UNION
     SELECT
     (CASE WHEN (cnt%2=1) AND id=cnt THEN id ELSE id + 1 END) AS id, student
     FROM seat, (select count(*) as cnt from seat) as seatcnt
     WHERE id%2 = 1) s
GROUP BY
    s.id ASC
__________________________________________________________________________________________________