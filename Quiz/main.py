def biggest_five(num):
    digit = 0
    tens = 1
    newnum = 0
    while num // tens > 10:
        tens *= 10
    while tens >= 1:
        digit = num // tens
        num = num % tens
        if digit < 5:
            return newnum + 5*tens + num
        else:
            newnum += digit * tens
            tens /= 10


def reverse1(name):
    return name[::-1]


def reverse2(name):
    name = list(name)
    right = len(name) - 1
    left = 0
    while left < right:
        temp = name[right]
        name[right] = name[left]
        name[left] = temp
        right -= 1
        left += 1
    newstr = ''
    for i in name:
        newstr += i
    return newstr


print(reverse2('omri'))

