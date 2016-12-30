SELECT P.ProductName, SUM(OD.Quantity)
FROM Products AS P
INNER JOIN OrderDetails AS OD ON P.ProductID = OD.ProductID
INNER JOIN Orders AS O ON OD.OrderID = O.OrderID
GROUP BY P.ProductName
