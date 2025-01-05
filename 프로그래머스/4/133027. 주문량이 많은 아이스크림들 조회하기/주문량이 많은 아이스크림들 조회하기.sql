-- "7월" 아이스크림 "총 주문량"과 "상반기"의 아이스크림 "총 주문량"을 "더한 값"이 "큰 순서대로 상위 3개"의 맛
SELECT H.FLAVOR
FROM FIRST_HALF H INNER JOIN 
    (SELECT *, SUM(TOTAL_ORDER) T
    FROM JULY
    GROUP BY FLAVOR
    ) F
ON H.FLAVOR = F.FLAVOR
ORDER BY (H.TOTAL_ORDER + F.T) DESC
LIMIT 3