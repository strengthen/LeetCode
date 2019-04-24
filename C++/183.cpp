__________________________________________________________________________________________________
SELECT Name AS Customers FROM Customers 
WHERE Id NOT IN (SELECT CustomerId FROM Orders);
__________________________________________________________________________________________________
SELECT Name AS Customers FROM Customers
LEFT JOIN Orders ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;
__________________________________________________________________________________________________
SELECT Name AS Customers FROM Customers c
WHERE NOT EXISTS (SELECT * FROM Orders o WHERE o.CustomerId = c.Id);