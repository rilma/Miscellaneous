SELECT ROUND(S1.LAT_N, 4) FROM STATION S1, STATION S2
GROUP BY S1.LAT_N
HAVING SUM(SIGN(1 - SIGN(S2.LAT_N - S1.LAT_N))) / COUNT(*) > 0.5
LIMIT 1
