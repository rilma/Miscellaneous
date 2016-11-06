
def FindMaxProfit(x):

    """ 
        Find the best periods to buy and sell a stock

        INPUT:
        x : A list of stock prices on consecutive days

    """

    class Interval:

        """ Solution class """

        def __init__(self, buy=None, sell=None):

            self.buy = buy
            self.sell = sell

    #
    # End of 'Interval'
    #####


    count = 0

    y = []

    #
    # Implementation of the peak valley approach
    #

    n = len(x)
    i = 0
    while i < (n - 1):

        # Local minima
        while (i < (n - 1)) and (x[i+1] <= x[i]): i += 1

        if i == (n - 1): break

        buy = i
        i += 1

        # Local maxima
        while (i < n) and (x[i] >= x[i-1]): i += 1

        sell = i - 1

        # Store index (class)
        y.append(Interval(buy=buy, sell=sell))

        count += 1

    # Computes total profit per period
    #
    print('Stock prices:\n', x)
    max_profit = 0
    for tmp in y:
        print('Buy on day {:d}, sell on day {:d}  -- Profit: {:d}'.format(tmp.buy, tmp.sell, x[tmp.sell] - x[tmp.buy]))
        max_profit += (x[tmp.sell] - x[tmp.buy])
    print('Total profit: {:d}'.format(max_profit))
            
#
# End of 'FindMaxProfit' 
#####


if __name__ == '__main__':

    # Examples
    #
    print('Finds the best period to buy and sell stocks!!!')
    for _ in range(1): print(' ')
    FindMaxProfit([100, 180, 260, 310, 40, 535, 695])
    for _ in range(2): print(' ')
    FindMaxProfit([1, 2, 4, 2, 5, 7, 2, 4, 9, 0])
    for _ in range(2): print(' ')
    print('End of program!!!')
