__________________________________________________________________________________________________
select  ranking.id, ranking.company, ranking.salary,ranking.rank,cnt

FROM (

SELECT e1.id,e1.company,e1.salary,count(*) rank

FROM [employee569] e1,

(select distinct company, salary from [employee569]) e2

where e1.company = e2.company and e1.salary >= e2.salary

group by  e1.id,e1.company,e1.salary

) ranking

inner join

(

SELECT company,count(id) cnt FROM [employee569] group by company

) companycount

on companycount.company = ranking.company

where (cnt%2=0 and (rank=(cnt/2)-1 or rank=(cnt/2)+1))

or (cnt%2<>0 and rank=(cnt/2)+1);
__________________________________________________________________________________________________

__________________________________________________________________________________________________
