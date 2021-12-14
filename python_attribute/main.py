class X:
     # __slots__ = ['a']
    _flag = False

    def _freeze(self):
         self._flag = True

    def __init__(self, a):
        self.a = a
        self._freeze()

    def __setattr__(self, key, value):
        if self._flag and not hasattr(self, key):
            raise AttributeError('Denied.')
        else:
            self.__dict__[key] = value

    def __getattr__(self, item):
        raise AttributeError(f"Impossible to find an attribute named '{item}'.")


x = X(1)
x.d = 5
