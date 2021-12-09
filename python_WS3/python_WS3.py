from test import *
import python2
path = python2.spec_from_file_location('python2',
                                       '/home/omri/Documents/git_repos/omri-shur/python_WS2/python2.py')



def global_check(name):
    if name in globals():
        print(f"{name} is exist in global")
    else:
        print(f"{name} does not exit in global")


if __name__ == '__main__':
    t = 20
    global_check('alon')

