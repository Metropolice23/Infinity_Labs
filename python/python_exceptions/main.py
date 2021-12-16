from numbers import Number


class TypeIsNotNumber(Exception):
    """Error class for non-number values"""
    def __init__(self):
        print("one of the vars isn't a number")


def div(a, b):
    """Get two numbers a and b, divide a by b"""
    result = None
    try:
        if isinstance(a, Number) and isinstance(b, Number):
            result = a / b
        else:
            raise TypeIsNotNumber
    except TypeIsNotNumber:
        pass
    except ZeroDivisionError:
        print("tried to divide by sero")
    finally:
        return result

print(div(10, 0))
print(div(10, 'tsg'))
print(div(50, 2))
