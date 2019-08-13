__________________________________________________________________________________________________
SELECT Salary FROM Employee GROUP BY Salary
UNION ALL (SELECT NULL AS Salary)
ORDER BY Salary DESC LIMIT 1 OFFSET 1;
__________________________________________________________________________________________________
SELECT MAX(Salary) FROM Employee 
WHERE Salary NOT IN
(SELECT MAX(Salary) FROM Employee);
__________________________________________________________________________________________________
SELECT MAX(Salary) FROM Employee
Where Salary <
(SELECT MAX(Salary) FROM Employee);
__________________________________________________________________________________________________
SELECT MAX(Salary) FROM Employee E1
WHERE 1 =
(SELECT COUNT(DISTINCT(E2.Salary)) FROM Employee E2
WHERE E2.Salary > E1.Salary);