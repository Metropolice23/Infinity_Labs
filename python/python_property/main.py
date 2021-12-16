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
      """

    def __init__(self, x, y):
        """Create a new point"""
        if isinstance(x, Number) and isinstance(y, Number):
            self.__x = float(x)
            self.__y = float(y)
        else:
            print("Error - expecting float type")

    @property
    def x(self):
        return self.__x

    @x.setter
    def x(self, value):
        if isinstance(value, Number):
            self.__x = float(value)
        else:
            self.__x = 0.0
            print("Error - expecting float type")

    @property
    def y(self):
        return self.__y

    @y.setter
    def y(self, value):
        if isinstance(value, Number):
            self.__y = float(value)
        else:
            self.__y = 0.0
            print("Error - expecting float type")


p1 = Point(4, 3)
print(p1.y)
p1.y = 7
print(p1.y)