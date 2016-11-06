
import re

def ReverseAnInt(x):

    """ Reversing an integer even if it's negative
    """

    # Verify if 'x'' is an integer
    if not isinstance(x, int):
        raise TypeError("You must enter an integer!")

    # Reverse integer x
    return -int(str(x)[1::][::-1]) if bool(re.search(r"\-\d", str(x))) \
        else int(str(x)[::-1])

#
# End of 'ReverseAnInt'
#####


if __name__ == '__main__':

    # Examples
    print(ReverseAnInt(12345))
    print(ReverseAnInt(-12345))
    print(ReverseAnInt(12345.)) # This throws an error message!!!
