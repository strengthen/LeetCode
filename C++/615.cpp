__________________________________________________________________________________________________
select date_formate(pay_date,'%Y-%m') pay_month, e.department_id,

　　(case when avg(amount) = com_avg  then 'same'

　　when avg(amount) > com_avg  then 'higher'

　　else 'lower' end) comparison  

from salary s1

left join employee e on s.employee_id  = e.employee_id 

inner join

(select date_format(pay_date, '%Y-%m') pay_month, avg(amount) com_avg from salary group by date_formate(pay_date,'%Y-%m')) s2

on s2.pay_month= date_formate(s1.pay_date,'%Y-%m')

group by e.department_id,date_formate(pay_date,'%Y-%m')
__________________________________________________________________________________________________

__________________________________________________________________________________________________
