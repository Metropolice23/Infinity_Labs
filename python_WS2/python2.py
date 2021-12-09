import math

def squared_loop():
    sqrt_list = []
    i = 1
    while i < 100:
        if math.sqrt(i).is_integer():
            sqrt_list.append(i)
        i += 1
    return sqrt_list


def even_loop():
    even_list = []
    for j in range(1, 100):
        if (j / 2).is_integer():
            even_list.append(j)
    return even_list


def str_index(word):
    char_dict = {}
    for i in range(len(word)):
        char_dict[word[i]] = word.count(word[i])
    return char_dict


def elements_list(dict1):
    for k, v in enumerate(dict1.items(), 1):
        print(k, v)


def same_elements(list1, list2):
    filtered_list = [string for string in list1 if string in list2]
    return filtered_list

def left_rotation(original):
    temp = original[0]
    slice_object = slice(1, len(original))
    original = original[slice_object]
    original.append(temp)
    return original




if __name__ == '__main__':
    reshima = {'a': 'omri', 'b': 'doron', 'c': 'alon', 'd': 'arye', 'e': 'olga'}
    list_a = ['dog', 'cat', 'monkey', 'bird', 'mouse']
    list_b = ['bird', 'horse', 'snail', 'cat', 'lion']
    print(squared_loop())
    print(even_loop())
    print(str_index("klavikula"))
    elements_list(reshima)
    print(same_elements(list_a, list_b))
    print(left_rotation(list_a))
