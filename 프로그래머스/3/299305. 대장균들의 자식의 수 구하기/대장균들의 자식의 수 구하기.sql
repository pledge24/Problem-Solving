-- 코드를 작성해주세요
WITH P_DATA AS (
    SELECT PARENT_ID
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NOT NULL
)

SELECT D.ID, COUNT(P_DATA.PARENT_ID) CHILD_COUNT
FROM ECOLI_DATA D LEFT JOIN P_DATA ON D.ID = P_DATA.PARENT_ID
GROUP BY D.ID
ORDER BY D.ID