# Write your MySQL query statement below
SELECT name AS Customers FROM Customers AS c
WHERE NOT EXISTS (
    SELECT 1 FROM Orders o
    where o.customerId = c.id
);