-- "대여 시작일"이 "2022년 9월"에 속하는 대여 기록
SELECT HISTORY_ID, CAR_ID, 
       DATE_FORMAT(START_DATE, '%Y-%m-%d') START_DATE, DATE_FORMAT(END_DATE, '%Y-%m-%d') END_DATE,
       IF(DATEDIFF(END_DATE+1, START_DATE) >= 30, "장기 대여", "단기 대여") RENT_TYPE
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY HIS
WHERE YEAR(START_DATE) = 2022 AND MONTH(START_DATE) = 9 
ORDER BY HISTORY_ID DESC