-- 헤비 유저(공간을 둘 이상 등록한 사람)가 등록한 공간의 정보
SELECT ID, NAME, HOST_ID
FROM (
    SELECT *, COUNT(*) OVER (PARTITION BY HOST_ID) X
    FROM PLACES 
) P
WHERE X >= 2
ORDER BY ID