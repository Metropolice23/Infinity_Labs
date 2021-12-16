import unittest
from python_Point import Point


class TestPoint(unittest.TestCase):

    def test_init(self):
        """Create a new point"""
        testp = Point(2, 4)
        self.assertTrue(testp.x == 2)
        self.assertTrue(testp.y == 4)
        testp1 = Point(2, "ram")
        self.assertNotIn('y', testp1.__dict__.keys())

    def test_get_counter(self):
        """Return the number of instance"""
        testp = Point()
        testp1 = Point()
        testp2 = Point()
        self.assertTrue(Point.get_counter() == 3)

    def test_len(self):
        """Return the number of point parameters"""
        testp = Point()
        self.assertTrue(testp.__len__() == 2)

    def test_str(self):
        """Return the Point for print"""
        testp = Point()
        self.assertEqual(testp.__str__(), 'Point(0.0, 0.0)')

    def test_add(self):
        """Return the Point plus other point"""
        testp1 = Point(1, 1)
        testp2 = Point(0.5, 0.75)
        self.assertTrue((testp1.__add__(testp2)).x == 1.5)
        self.assertTrue((testp1.__add__(testp2)).y == 1.75)

    def test_iadd(self):
        """Add point to another point"""
        testp1 = Point(1, 1)
        testp2 = Point(0.5, 0.75)
        self.assertTrue((testp1.__iadd__(testp2)).x == 1.5)
        self.assertTrue(testp1.y == 1.75)

    def test_sub(self):
        """Return the Point minus other point"""
        testp1 = Point(1, 1)
        testp2 = Point(0.5, 0.75)
        self.assertTrue((testp1.__sub__(testp2)).x == 0.5)
        self.assertTrue((testp1.__sub__(testp2)).y == 0.25)

    def test_isub(self):
        """Sub point from another point"""
        testp1 = Point(1, 1)
        testp2 = Point(0.36, 0.75)
        self.assertTrue((testp1.__isub__(testp2)).x == 0.64)
        self.assertTrue(testp1.y == 0.25)

    def test_mul(self):
        """Return multiple point by scalar"""
        testp = Point(2, 3)
        self.assertTrue((testp.__mul__(3)).x == 6)
        self.assertTrue((testp.__mul__(3)).y == 9)

    def test_imul(self):
        """Multiple point by scalar"""
        testp = Point(4, 5)
        self.assertTrue((testp.__imul__(2)).x == 8)
        self.assertTrue(testp.y == 10)

    def test_truediv(self):
        """Return point divide by scalar"""
        testp = Point(20, 15)
        self.assertTrue((testp.__truediv__(5)).x == 4)
        self.assertTrue((testp.__truediv__(5)).y == 3)

    def test_idiv(self):
        """Divide point by scalar"""
        testp = Point(16, 8)
        self.assertTrue((testp.__idiv__(4)).x == 4)
        self.assertTrue(testp.y == 2)

    def test_instance_from_origin(self):
        """"Calculate the distance between given point and point (0, 0)"""
        testp = Point(3, 4)
        self.assertTrue(testp.instance_from_origin() == 5)


if __name__ == "__main__":
    unittest.main()
