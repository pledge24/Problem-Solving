-- 코드를 입력하세요
SELECT DATE_FORMAT(DATETIME, '%H') HOUR, COUNT(*)
FROM ANIMAL_OUTS
GROUP BY HOUR
HAVING HOUR BETWEEN 9 AND 19
ORDER BY HOUR