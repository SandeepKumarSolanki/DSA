# Write your MySQL query statement below
SELECT c.name as Customers FROM Customers AS c
LEFT JOIN Orders o
on c.id = o.customerId
WHERE o.customerID is NULL;