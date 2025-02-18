-- 부모의 형질을 모두 보유한 대장균?

# 부모가 있다.
# 부도의 형질을 모두 보유하고 있다.

-- 부모가 있는 애들
WITH E1 AS (
    SELECT ID, PARENT_ID, GENOTYPE
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NOT NULL
)

SELECT E1.ID, E1.GENOTYPE, E2.GENOTYPE PARENT_GENOTYPE
FROM E1 INNER JOIN ECOLI_DATA E2 ON E1.PARENT_ID = E2.ID 
                                AND (E1.GENOTYPE & E2.GENOTYPE = E2.GENOTYPE)
ORDER BY E1.ID
                                   


    