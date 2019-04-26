__________________________________________________________________________________________________

with cumulativeSalary as(
select e1.Id,e1.Month,
isnull(e1.salary,0)+ISNULL(e2.salary,0)+ISNULL(e3.salary,0) as CumulativeSalary
from employees2 e1 
left join employees2 e2 on e1.Id=e2.Id and e2.Month=e1.Month-1
left join employees2 e3 on e3.Id=e2.Id and e3.Month=e2.Month-1
),MostRecentMonth as
(
select id,max(Month) as MaxMonth from employees2 group by Id having(count(*)>1)
)
select c.Id,c.Month,c.CumulativeSalary from cumulativeSalary c join MostRecentMonth m on c.Id=m.Id and m.MaxMonth>c.Month
order by Id asc, Month desc
__________________________________________________________________________________________________

__________________________________________________________________________________________________
