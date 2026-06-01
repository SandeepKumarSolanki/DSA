# Write your MySQL query statement below
SELECT score, DENSE_RANK() OVER (ORDER BY score Desc) as `rank` FROM Scores;

-- SELECT score, 
--        DENSE_RANK() OVER (ORDER BY score DESC) AS `rank`
-- FROM Scores;
