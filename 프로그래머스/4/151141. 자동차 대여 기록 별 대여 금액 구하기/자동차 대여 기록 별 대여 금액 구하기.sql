# CAR_RENTAL_COMPANY_CAR 테이블과 CAR_RENTAL_COMPANY_RENTAL_HISTORY 테이블과 CAR_RENTAL_COMPANY_DISCOUNT_PLAN 테이블에서 자동차 종류가 '트럭'인 자동차의 대여 기록에 대해서 대여 기록 별로 대여 금액(컬럼명: FEE)을 구하여 대여 기록 ID와 대여 금액 리스트를 출력하는 SQL문을 작성해주세요. 결과는 대여 금액을 기준으로 내림차순 정렬하고, 대여 금액이 같은 경우 대여 기록 ID를 기준으로 내림차순 정렬해주세요.
WITH F AS (
    SELECT H.*, C.CAR_TYPE, (DATEDIFF(END_DATE, START_DATE) + 1) DAYS, (DATEDIFF(END_DATE, START_DATE) + 1) * DAILY_FEE AS TOTAL_FEE
    FROM CAR_RENTAL_COMPANY_CAR C INNER JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY H ON C.CAR_ID = H.CAR_ID                 
    WHERE C.CAR_TYPE = '트럭'
), P AS (
    SELECT *, 
        CASE 
            WHEN duration_type = '7일 이상' THEN 7
            WHEN duration_type = '30일 이상' THEN 30
            WHEN duration_type = '90일 이상' THEN 90
        END AS MIN_DAYS,
        CASE 
            WHEN duration_type = '7일 이상' THEN 30
            WHEN duration_type = '30일 이상' THEN 90
            WHEN duration_type = '90일 이상' THEN NULL
        END AS MAX_DAYS
    FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN P
    WHERE P.CAR_TYPE = '트럭'
)

SELECT F.HISTORY_ID, IF(P.DISCOUNT_RATE IS NULL, F.TOTAL_FEE, CAST(TOTAL_FEE * (1 - P.DISCOUNT_RATE / 100) AS DECIMAL)) FEE
FROM F LEFT JOIN P ON F.DAYS >= P.MIN_DAYS AND 
                       (P.MAX_DAYS IS NULL OR F.DAYS < MAX_DAYS) AND
                       F.CAR_TYPE = P.CAR_TYPE
ORDER BY FEE DESC, F.HISTORY_ID DESC

# F.HISTORY_ID, CAST(TOTAL_FEE * (1 - discount_rate / 100) AS DECIMAL) FEE