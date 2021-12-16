from math import sqrt
from numbers import Number


class Point:
    """
      A class to represent a point.

      ...

      Attributes
      ----------
      x : float
          x value of a point (0.0 default)
      y : float
          y value of a point (0.0 default)

      Methods
      -------
      instance_from_origin
          Return the distance of a point from origin.
      """
    _instance_counter = 0

    def __init__(self, x=0.0, y=0.0):
        """Create a new point"""
        try:
            if isinstance(x, Number) and isinstance(y, Number):
                self.x = float(x)
                self.y = float(y)
            else:
                raise TypeError
        except TypeError:
            self.__del__()
            print("error - expecting float type")
        finally:
            Point._instance_counter += 1

    def __del__(self):
        Point._instance_counter -= 1

    @classmethod
    def get_counter(cls):
        """Return the number of instance"""
        return Point._instance_counter

    def __len__(self):
        """Return the number of point parameters"""
        return len(self.__dict__)

    def __str__(self):
        """Return the Point for print"""
        return f"Point({self.x}, {self.y})"

    def __add__(self, other):
        """Return the Point plus other point"""
        x = self.x + other.x
        y = self.y + other.y
        return Point(x, y)

    def __iadd__(self, other):
        """Add point to another point"""
        self.x = self.x + other.x
        self.y = self.y + other.y
        return self

    def __sub__(self, other):
        """Return the Point minus other point"""
        x = self.x - other.x
        y = self.y - other.y
        return Point(x, y)

    def __isub__(self, other):
        """Sub point from another point"""
        self.x = self.x - other.x
        self.y = self.y - other.y
        return self

    def __mul__(self, other):
        """Return multiple point by scalar"""
        try:
            x = self.x * other
            y = self.y * other
            return Point(x, y)
        except TypeError:
            print("non-number!")

    def __imul__(self, other):
        """Multiple point by scalar"""
        try:
            self.x = self.x * other
            self.y = self.y * other
        except TypeError:
            print("non-number!")
        finally:
            return self

    def __truediv__(self, other):
        """Return point divide by scalar"""
        try:
            x = self.x / other
            y = self.y / other
            return Point(x, y)
        except TypeError:
            print("non-number!")
        except ZeroDivisionError:
            print("tried to divide by sero")

    def __idiv__(self, other):
        """Divide point by scalar"""
        try:
            self.x = self.x / other
            self.y = self.y / other
        except TypeError:
            print("non-number!")
        except ZeroDivisionError:
            print("tried to divide by sero")
        finally:
            return self

    def instance_from_origin(self):
        """"Calculate the distance between given point and point (0, 0)"""
        return sqrt(self.x**2 + self.y**2)

# p1 = Point(1.0, 1.0)
# p2 = Point(4.0, 3.0)
# p3 = Point(7, 7)
# p4 = Point("o", "s")
#
# print("----------dinstance test----------")
# print("p1 distance from origin:")
# print(p1.instance_from_origin())
# print("p2 distance from origin:")
# print(p2.instance_from_origin())
#
# print("----------add/sub test----------")
# print("p1 + p2:")
# print(p1 + p2)
# print("p3 - p1:")
# print(p3 + p1)
#
# print("----------mul/div test----------")
# print("p1 * 3:")
# print(p1 * 3)
# print("p1 * 8:")
# p1 *= 8
# print(p1)
# print("p3 / 2:")
# print(p3 / 2)
# print("p1 / 2:")
# p1 /= 2
# print(p1)
#
#
# print("----------counter/del test----------")
# print("counter is:")
# print(Point.get_counter())
# print("delete p3:")
# del p3
# print("counter is:")
# print(Point.get_counter())
#
#
# print("----------len test----------")
# print("p1 length is:")
# print(len(p1))
#
# print("-----------------------------")
