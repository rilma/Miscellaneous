
from functools import reduce
from operator import mul
from random import randint

def FindMissing(N, k):

    """
    
      INPUT:
      N -> No. of consecutive integer numbers
      k -> No. of numbers to be removed out or a list of numbers (either 1 or 2)
    
    """

    S0 = int((N-1) * ((N-1) + 1) * .5)

    x = list(range(1, N))

    if not isinstance(k, list):

        for _ in range(k):
            index = randint(0, len(x) - 1)
            print(x[index])
            x.pop(index)
        
        if k == 1:
            return S0 - sum(x)
        elif k == 2:
            d = S0 - sum(x)
            m = reduce(mul, range(1, N), 1) // reduce(mul, x, 1)
            b1 = d + int((d**2 - 4*m)**.5)
            b2 = d - int((d**2 - 4*m)**.5)
            b = (b1 if b1 > b2 else b2) // 2
            return [d - b, b]
        else:
            return None

    else:

        for tmp in k:
            print(x[tmp - 1])            
            x.pop(tmp - 1)

        if len(k) == 1:
            return S0 - sum(x)
        elif len(k) == 2:
            d = S0 - sum(x)
            m = reduce(mul, range(1, N), 1) // reduce(mul, x, 1)
            b1 = d + int((d**2 - 4*m)**.5)
            b2 = d - int((d**2 - 4*m)**.5)
            b = (b1 if b1 > b2 else b2) // 2
            return [d - b, b]            
        else:
            return None            


if __name__ == '__main__':

    print(FindMissing(100, 1))
    print(FindMissing(100, [61]))

    print(FindMissing(100, 2))
    print(FindMissing(100, [54, 32]))
