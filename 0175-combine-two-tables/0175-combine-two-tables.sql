# Write your MySQL query statement below
SELECT p.firstname as firstName, p.lastName as lastName, ads.city, ads.state from Person as p
LEFT JOIN Address as ads
ON p.personId = ads.personId;