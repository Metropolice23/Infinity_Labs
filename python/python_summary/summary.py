import math

def return_file_name(path):
    while '/' in path:
        path = path[1:]
    return path


def capital_letters_file(path):
    counter = 0
    with open(path, 'r') as file:
        lines = file.readlines()
    for i in lines:
        lines[counter] = lines[counter].upper()
        counter += 1
    with open(path, 'w') as file:
        for i in lines:
            file.write(i)


def check_if_prime(number):
    for i in range(2, int(number / 2)):
        if number % i == 0:
            return False
    return True


def lambda1():
    return lambda a: math.sqrt(a)


def lambda2():
    return lambda a, b: a + b


def __dunders_out__(index):
    if '__' not in index:
        return True
    return False


def dir_list_no_dunder(lis):
    nlist = filter(__dunders_out__, lis)
    return list(nlist)


def increment_list(ls):
    for i in range(len(ls)):
        ls[i] += 1
    return ls


def remove_not_str_from_list(ls):
    nlist = [i for i in ls if isinstance(i, str)]
    return nlist


def enum_print(ls):
    print(list(enumerate(ls)))


def dict_print(dic):
    for key, value in dic.items():
        print(key, ':', value)


def list_to_dict(ls):
    dic = {i: ls[i] for i in range(len(ls))}
    return dic


class DefaultDict:
    def __init__(self, num):
        self.default = num
        self.key = list()
        self.value = list()

    def set_item(self, key1, value):
        if key1 not in self.key:
            self.key.append(key1)
            self.value.append(value)
        else:
            self.value[self.key.index(key1)] = value

    def get_item(self, key1):
        if key1 in self.key:
            return self.value[self.key.index(key1)]
        else:
            return self.default


