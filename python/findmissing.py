
from random import randint
from scipy import where

def FindMissing(N, k):

    """
        INPUT:
        N -> No. of consucutive numbers
        k -> No. of numbers to be removed out
    """

    x = list(range(1, N + 1))

    # Remove 'k' numbers from list
    for _ in range(k):
        # Random integer number between 0 and len(x) - 1, including limits
        index = randint(0, len(x) - 1)
        print(x[index])
        x.pop(index)

    numbers = []

    # Numbers lower than 'x[0]'
    for num in range(1, x[0]):
      numbers.append(num)

    # Numbers in between
    for i in range(1, len(x)):
      for num in range(x[i-1] + 1, x[i]):
        numbers.append(num)

    # Numbers larger than x[N-1]
    for num in range(x[-1], N):
      numbers.append(num)

    return numbers


if __name__ == '__main__':

    print(FindMissing(100000, 20))
