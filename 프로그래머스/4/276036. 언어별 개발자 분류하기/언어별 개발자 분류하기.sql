-- GRADE가 존재하는 개발자
-- A : Front End 스킬과 Python 스킬을 함께 가지고 있는 개발자
-- B : C# 스킬을 가진 개발자 
-- C : 그 외의 Front End 개발자 
-- FE(1), C#(2), PYTHON(3), ELSE(0)

WITH FE_CODE AS (
    SELECT SUM(CODE) CODE
    FROM SKILLCODES
    WHERE CATEGORY = 'Front End'
), GRADE_RES AS(
    SELECT *,
        CASE 
            WHEN SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'Python') > 0 AND
                 SKILL_CODE & (SELECT CODE FROM FE_CODE) > 0
            THEN 'A'
            WHEN SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'C#') > 0
            THEN 'B'
            WHEN SKILL_CODE & (SELECT CODE FROM FE_CODE) > 0
            THEN 'C'
            ELSE NULL
        END GRADE
    FROM DEVELOPERS
)

SELECT GRADE, ID, EMAIL
FROM GRADE_RES
WHERE GRADE IS NOT NULL
ORDER BY GRADE ASC, ID ASC
