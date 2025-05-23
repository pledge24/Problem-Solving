-- 코드를 작성해주세요

WITH Q AS (
    SELECT ID,
        CASE 
            WHEN MONTH(DIFFERENTIATION_DATE) BETWEEN 1 AND 3 THEN '1Q'
            WHEN MONTH(DIFFERENTIATION_DATE) BETWEEN 4 AND 6 THEN '2Q'
            WHEN MONTH(DIFFERENTIATION_DATE) BETWEEN 7 AND 9 THEN '3Q'
            WHEN MONTH(DIFFERENTIATION_DATE) BETWEEN 10 AND 12 THEN '4Q'
            ELSE NULL
        END QUARTER
    FROM ECOLI_DATA
)

SELECT Q.QUARTER, COUNT(*) ECOLI_COUNT
FROM ECOLI_DATA D INNER JOIN Q ON D.ID = Q.ID
GROUP BY Q.QUARTER
ORDER BY Q.QUARTER
