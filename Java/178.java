__________________________________________________________________________________________________
SELECT Score, 
(SELECT COUNT(DISTINCT Score) FROM Scores WHERE Score >= s.Score) Rank 
FROM Scores s ORDER BY Score DESC;
__________________________________________________________________________________________________
SELECT Score,
(SELECT COUNT(*) FROM (SELECT DISTINCT Score s FROM Scores) t WHERE s >= Score) Rank
FROM Scores ORDER BY Score DESC;
__________________________________________________________________________________________________
SELECT s.Score, COUNT(DISTINCT t.Score) Rank
FROM Scores s JOIN Scores t ON s.Score <= t.Score
GROUP BY s.Id ORDER BY s.Score DESC;
__________________________________________________________________________________________________
SELECT Score,
@rank := @rank + (@pre <> (@pre := Score)) Rank
FROM Scores, (SELECT @rank := 0, @pre := -1) INIT 
ORDER BY Score DESC;