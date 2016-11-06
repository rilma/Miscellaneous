
from sys import maxsize


def FindMaxProfit(x):

    """ 
        Finds the maximum profit to buy and sell a stock

        INPUT:
        x : A list which element represent the price of a stock on a given day

    """

    min_x, max_p = maxsize, 0

    for i in range(len(x)):
        if min_x > x[i]: min_x = x[i]            
        elif (x[i] - min_x) > max_p: max_p = x[i] - min_x

    return max_p

#
# End of 'exercise03b'
#####    


if __name__ == '__main__':

    print(FindMaxProfit([7, 1, 5, 3, 6, 4]))
    print(FindMaxProfit([7, 6, 4, 3, 1]))
