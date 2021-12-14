class Property:
    "Emulate PyProperty_Type() in Objects/descrobject.c"
    counter = 0

    def __init__(self, fget=None, fset=None, fdel=None):
        self.fget = fget
        self.fset = fset
        self.fdel = fdel
        print(f"counter = {self.counter}")
        self.__class__.counter += 1

    def __get__(self, obj, objtype=None):
        return self.fget(obj)

    def __set__(self, obj, value):
        self.fset(obj, value)

    def __delete__(self, obj):
        self.fdel(obj)

    def Getter(self, fget):
        return type(self)(fget, self.fset, self.fdel)

    def Setter(self, fset):
        return type(self)(self.fget, fset, self.fdel)

    def Deleter(self, fdel):
        return type(self)(self.fget, self.fset, fdel)


class X:
    def __init__(self, val):
        self.__x = int(val)

    @Property
    def x(self):
        return self.__x

    @x.Setter
    def x(self, val):
        self.__x = int(val)

    @x.Deleter
    def x(self):
        del self.__x


a = X(0)
print(a.x)
a.x = 1
print(a.x)
del(a.x)
#print(a.x)
