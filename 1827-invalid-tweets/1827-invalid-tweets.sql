-- # Write your MySQL query statement below
-- SELECT  tweet_id 
-- COUNT(content) from Tweets 
-- group by tweet_id 
-- having 
-- COUNT(content) < 15;
SELECT tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15;
