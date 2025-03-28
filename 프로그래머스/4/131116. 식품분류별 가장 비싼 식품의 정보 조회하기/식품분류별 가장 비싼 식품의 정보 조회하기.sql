-- "식품 분류 별" "제일 비싼 식품"은?
SELECT CATEGORY, PRICE AS MAX_PRICE, PRODUCT_NAME
FROM (SELECT *, RANK() OVER (PARTITION BY CATEGORY ORDER BY PRICE DESC) RNK FROM FOOD_PRODUCT) FOOD_PRODUCT2
GROUP BY CATEGORY HAVING CATEGORY IN ('과자', '국', '김치', '식용유')
ORDER BY MAX_PRICE DESC