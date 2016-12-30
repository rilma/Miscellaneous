SELECT H.hacker_id, H.name, SUM(T2.max_score) AS total_score
FROM Hackers AS H
INNER JOIN (
    SELECT S.hacker_id AS hacker_id, S.challenge_id AS challenge_id, MAX(S.score) AS max_score
    FROM Submissions AS S
    GROUP BY S.hacker_id, S.challenge_id
) AS T2
ON H.hacker_id = T2.hacker_id
GROUP BY H.hacker_id HAVING total_score > 0
ORDER BY total_score DESC, H.hacker_id ASC
