from numbers import Number


class TypeIsNotNumber(Exception):
    """Error class for non-number values"""
    @staticmethod
    def error_print():
        print("one of the vars isn't a number")


def div(a, b):
    """Get two numbers a and b, divide a by b"""
    result = None
    try:
        result = a / b
    except TypeError:
        TypeIsNotNumber.error_print()
    except ZeroDivisionError:
        print("tried to divide by sero")
    finally:
        return result

print(div(10, 0))
print(div(10, 'tsg'))
print(div(50, 2))
