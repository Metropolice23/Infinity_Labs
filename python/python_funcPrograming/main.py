import functools


def sum_for(lis):
    """"Calculate the sum of a list"""
    result = 0
    for i in range(len(lis)):
        result += lis[i]
    return result


def sum_red(lis):
    """"Calculate the sum of a list"""
    return(functools.reduce(lambda a, b: a+b, lis))


def sum_sum(lis):
    """"Calculate the sum of a list"""
    return sum(lis)


def list_comp(hundred):
    """"Receive list of numbers to even numbers list"""
    newlist = [x if x % 2 == 0 else "odd" for x in hundred]
    return newlist


def seven_boom(num):
    """Receive a num and return 7Boom list"""
    seven_list = ["boom" if "7" in (str(x)) or x % 7 == 0 else x for x in range(num)]
    return seven_list


def seven_boom_map(nums1):
    """Receive a num and return 7Boom list"""
    seven_list = map(lambda x: "boom" if "7" in (str(x)) or x % 7 == 0 else x, range(nums1))
    return seven_list


def list_to_dict(list1):
    """Turn a list to dictionary"""
    dict_from_list = {num: list1[num] for num in range(len(list1))}
    return dict_from_list


def how_many_arguments(*args):
    """Receive arguments and return the number of arguments."""
    counter = 0
    for arg in args:
        counter += 1
    return counter


def print_name(*args, **kwargs):
    """Receive arguments and print the value of key name."""
    for key, value in kwargs.items():
        if key == 'name':
            print("%s" %(value))
        else:
            pass


def make_adder(n):
    """Create a increasing function for given num"""
    return lambda a: a + n


nums = [6, 7, 14, 3, 20]
print(sum_for(nums))
print(sum_red(nums))
print(sum_sum(nums))

hundred = list(range(1, 101))
even_list = list_comp(hundred)
print(even_list)

print(seven_boom(50))

num1 = list(range(22))
list_seven = seven_boom_map(len(num1))
print(list(list_seven))

print(list_to_dict(nums))

print(how_many_arguments('fd', 'dsg', 'sgsgdfg', 'ret', 'bbb', 5, 3, 6))

print_name(1, 2, 3, 4, name='omri')

add_3 = make_adder(3)
print(add_3(5))
print(add_3(3))
add_5 = make_adder(5)
print(add_5(5))
print(add_5(8))
