-- 코드를 입력하세요
# SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
# FROM ANIMAL_INS
# WHERE NAME REGEXP "Lucy|Ella|Pickle|Rogan|Sabrina|Mitty"
# ORDER BY ANIMAL_ID

SELECT
    animal_id,
    name,
    sex_upon_intake
FROM
    animal_ins
WHERE
    name IN ('Lucy', 'Ella', 'Pickle', 'Rogan', 'Sabrina', 'Mitty');