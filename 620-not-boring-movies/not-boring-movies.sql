# Write your MySQL query statement below
SELECT id, movie, description, rating
FROM Cinema
WHERE description <> 'boring'
AND MOD(id, 2) <> 0
ORDER BY rating DESC;