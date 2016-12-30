SELECT C.CategoryName, COUNT(OD.OrderID)
FROM Categories AS C
INNER JOIN Products AS P ON P.CategoryID = C.CategoryID
INNER JOIN OrderDetails AS OD ON OD.ProductID = P.ProductID
GROUP BY C.CategoryName
