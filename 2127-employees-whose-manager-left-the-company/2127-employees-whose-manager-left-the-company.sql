# Write your MySQL query statement below
SELECT employee_id
FROM Employees e
WHERE salary < 30000 AND manager_id IS NOT NULL
  AND NOT exists (
    SELECT 1
    FROM Employees m
    WHERE m.employee_id = e.manager_id 
  )
  order by employee_id ;
