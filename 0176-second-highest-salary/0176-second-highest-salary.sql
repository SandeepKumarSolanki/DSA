# Write your MySQL query statement below
With RankedSalaries AS (
    SELECT salary, DENSE_RANK() OVER(ORDER BY salary DESC) as salary_rank
    FROM Employee       
) 
SELECT Max(salary) as SecondHighestSalary
FROM RankedSalaries
where salary_rank = 2;

-- SELECT Max(salary) as SecondHighestSalary FROM Employee WHERE salary < (
--     SELECT MAX(salary) FROM Employee
-- );

-- SELECT (
--     SELECT salary FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET 1
-- ) AS SecondHighestSalary;