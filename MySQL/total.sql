SELECT C.CategoryName, ROUND(SUM(D2.OrderValue), 2) FROM 
	Categories C, 
    (SELECT OD.Quantity * P.Price AS OrderValue, P.CategoryID AS CategoryID FROM 
    	OrderDetails OD, Products P WHERE OD.ProductID = P.ProductID) D2 
    WHERE C.CategoryID = D2.CategoryID GROUP BY C.CategoryID
