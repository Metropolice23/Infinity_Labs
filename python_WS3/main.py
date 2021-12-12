import mypackage
import python2
from test1 import *


def global_check(name):
    """Receive a var name and tell if it's exist in the global scope"""
    if name in globals():
        print(f"{name} is exist in global")
    else:
        print(f"{name} does not exit in global")


if __name__ == '__main__':
    print(python2.squared_loop())
    print(python2.str_index('topolopompo'))
    print(python2.even_loop())
    global_check('yyy')
    mypackage._bar()


