-- "2021년에 가입한 전체 회원들" 중 상품을 구매한 "회원수"와 상품을 "구매한 회원의 비율"을 년, 월 별로 출력
WITH Y2021 AS (
    SELECT *
    FROM USER_INFO
    WHERE YEAR(JOINED) = 2021
), PC AS (
    SELECT Y2021.USER_ID, YEAR(SALE.SALES_DATE) YY, MONTH(SALE.SALES_DATE) MM
    FROM Y2021 INNER JOIN ONLINE_SALE SALE ON Y2021.USER_ID = SALE.USER_ID
    GROUP BY Y2021.USER_ID, YEAR(SALE.SALES_DATE), MONTH(SALE.SALES_DATE)
)


SELECT YY YEAR, MM MONTH, COUNT(*) PURCHASED_USERS, ROUND((COUNT(*) / (SELECT COUNT(*) FROM Y2021)), 1) PUCHASED_RATIO
FROM PC
GROUP BY YY, MM
ORDER BY YEAR ASC, MONTH ASC


