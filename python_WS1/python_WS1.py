def even(num):
    """Receive a number and print if it's even or not"""
    if num % 2 == 0:
        print ('Even')
    else:
        print ('Not Even')


def loop(name, num1=1):
    """Receive a name and number and print the name "number" times"""
    for i in range(num1):
        print(name)


def leap(year):
    """Receive a year and print if it leap year or not"""
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        print ("Leap year")
    else:
        print ("Not leap year")


def flip(num):
    """Receive a number and return the flip-number"""
    num1 = int(num)
    num2 = 0
    while num1 != 0:
        num2 *= 10
        num2 += num1 % 10
        num1 //= 10
    return num2


def grade(grd):
    """Receive a grade and return the match char"""
    if 0 <= grd < 10:
        return 'F'
    elif 10 <= grd < 30:
        return 'E'
    elif 30 <= grd < 50:
        return 'D'
    elif 50 <= grd < 70:
        return 'C'
    elif 70 <= grd < 90:
        return 'B'
    elif 90 <= grd <= 100:
        return 'A'
    else:
        return "Error"


def factorial(num):
    """Receive a number and return the factorial"""
    if num == 1:
        return num
    else:
        return num * factorial(num - 1)

