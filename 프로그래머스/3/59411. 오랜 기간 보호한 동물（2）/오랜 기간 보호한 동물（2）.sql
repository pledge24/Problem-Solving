-- 코드를 입력하세요
SELECT INS.ANIMAL_ID, INS.NAME
FROM ANIMAL_INS INS INNER JOIN ANIMAL_OUTS OUTS ON INS.ANIMAL_ID = OUTS.ANIMAL_ID
ORDER BY DATEDIFF(OUTS.DATETIME, INS.DATETIME) DESC
LIMIT 2