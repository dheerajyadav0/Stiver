SELECT
  s.student_id,
  s.student_name,
  su.subject_name,
  COUNT(e.subject_name) AS attended_exams
FROM
  Students AS s
CROSS JOIN
  Subjects AS su
LEFT JOIN
  Examinations AS e
  ON s.student_id = e.student_id AND su.subject_name = e.subject_name
GROUP BY
  s.student_id, s.student_name, su.subject_name
ORDER BY
  student_id;
