__________________________________________________________________________________________________
# Write your MySQL query statement below
select id, max(case when month = 'Jan' then revenue end) as Jan_Revenue,
max(case when month = 'Feb' then revenue end) as Feb_Revenue,
max(case when month = 'Mar' then revenue end) as Mar_Revenue,
max(case when month = 'Apr' then revenue end) as Apr_Revenue,
max(case when month = 'May' then revenue end) as May_Revenue,
max(case when month = 'Jun' then revenue end) as Jun_Revenue,
max(case when month = 'Jul' then revenue end) as Jul_Revenue,
max(case when month = 'Aug' then revenue end) as Aug_Revenue,
max(case when month = 'Sep' then revenue end) as Sep_Revenue,
max(case when month = 'Oct' then revenue end) as Oct_Revenue,
max(case when month = 'Nov' then revenue end) as Nov_Revenue,
max(case when month = 'Dec' then revenue end) as Dec_Revenue

from Department
group by id
__________________________________________________________________________________________________

__________________________________________________________________________________________________
