# Write your MySQL query statement below

with cte as
(select * , 
lead(num ,1 ) over() as next,
lead(num ,2) over() as next2next
from logs)

select distinct num as
 ConsecutiveNums
from cte 
where 
num = next 
AND num = next2next;


