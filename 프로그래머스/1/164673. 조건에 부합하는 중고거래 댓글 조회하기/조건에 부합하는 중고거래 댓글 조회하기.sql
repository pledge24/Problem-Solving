-- 2022년 10월에 작성된 게시글
SELECT B.TITLE, B.BOARD_ID, R.REPLY_ID, R.WRITER_ID, R.CONTENTS, DATE_FORMAT(R.CREATED_DATE, '%Y-%m-%d') CREATED_DATE
FROM USED_GOODS_BOARD B INNER JOIN USED_GOODS_REPLY R ON B.BOARD_ID = R.BOARD_ID
WHERE YEAR(B.CREATED_DATE) = 2022 AND MONTH(B.CREATED_DATE) = 10
ORDER BY CREATED_DATE ASC, B.TITLE ASC