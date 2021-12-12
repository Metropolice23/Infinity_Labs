

def capital_read(path):
    with open(path, 'r') as file:
        cont = file.read().upper()
        print(cont)


def capital_read1(path):
    file = open(path, 'r')
    cont = file.read().upper()
    print(cont)
    file.close()


capital_read('/home/omri/Documents/git_repos/omri-shur/python_context_management/text.txt')