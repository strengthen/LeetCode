__________________________________________________________________________________________________
# Write your MySQL query statement below
SELECT
    DISTINCT t1.*
FROM
    stadium t1,
    stadium t2,
    stadium t3
WHERE
    t1.people >= 100
AND t2.people >= 100
AND t3.people >= 100
AND (
    (
        t1.id - t2.id = 1
        AND t1.id - t3.id = 2
        AND t2.id - t3.id = 1
    )
    OR (
        t2.id - t1.id = 1
        AND t2.id - t3.id = 2
        AND t1.id - t3.id = 1
    )
    OR (
        t3.id - t2.id = 1
        AND t2.id - t1.id = 1
        AND t3.id - t1.id = 2
    )
)
ORDER BY
    t1.id
__________________________________________________________________________________________________
select id, date, people 
 from (select id, date, people,
	case when consecutive >= 3 then @pending := 3
         else @pending := @pending - 1
	end as tmp,
    if(@pending > 0, 1, 0) as include
 from (select id, date, people, 
      case when people >= 100 then @count := @count + 1
		   else @count := 0
	  end as consecutive
      from stadium, (select @count := 0) init1
) tmp, (select @pending := 0) init2
order by 1 desc
) otmp where include = 1
order by 1;
__________________________________________________________________________________________________