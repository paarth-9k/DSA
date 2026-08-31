# Write your MySQL query statement below
WITH sec_sal AS (
    SELECT  salary, 
    DENSE_RANK() OVER (
        ORDER BY salary DESC
    ) AS rnk
    FROM Employee
)

SELECT (
    SELECT salary 
    FROM sec_sal
    WHERE rnk = 2 LIMIT 1
) AS SecondHighestSalary;