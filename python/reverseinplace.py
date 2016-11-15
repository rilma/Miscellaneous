

def ReverseInPlace(string):

    """
        Strings are inmutable in Python, so we reverse a list of characters then 
        convert them back to a string 
    """

    List = list(string)
    nChars = len(List)

    for i in range(nChars // 2):
        List[i], List[nChars - i - 1] = List[nChars - i - 1], List[i]

    return ''.join(List)


if __name__ == '__main__':

    print(ReverseInPlace('Welcome to Github'))

