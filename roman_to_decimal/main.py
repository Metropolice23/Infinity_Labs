def roman_to_num(roman):
    char_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    i = len(roman)-1
    result = 0
    sub = False
    while i >= 0:
        if result != 0 and sub is False and char_dict.get(roman[i]) < char_dict.get(roman[i + 1]):
            sub = True
        if sub is False:
            result += char_dict.get(roman[i])
        else:
            result -= char_dict.get(roman[i])
        i -= 1
    return result


if __name__ == "__main__":
    print(roman_to_num("LMVIII"))
