WITH weekly_hours AS (
    SELECT
        employee_id,
        YEAR(meeting_date) AS yr,
        WEEK(meeting_date, 1) AS wk,
        SUM(duration_hours) AS total_hours
    FROM meetings
    GROUP BY employee_id, YEAR(meeting_date), WEEK(meeting_date, 1)
),
heavy_weeks AS (
    SELECT
        employee_id,
        COUNT(*) AS meeting_heavy_weeks
    FROM weekly_hours
    WHERE total_hours > 20
    GROUP BY employee_id
)
SELECT
    e.employee_id,
    e.employee_name,
    e.department,
    h.meeting_heavy_weeks
FROM heavy_weeks h
JOIN employees e
    ON e.employee_id = h.employee_id
WHERE h.meeting_heavy_weeks >= 2
ORDER BY h.meeting_heavy_weeks DESC, e.employee_name ASC;