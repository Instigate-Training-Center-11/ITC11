from copy import copy
import sys

class A:
    __popA = 10
    _pop = 100
    def __init__(self,x,y):
        self.x = x
        self.y = y

    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y
        return A(x, y)

    def __sub__(self, other):
        x = self.x - other.x
        y = self.y - other.y
        return A(x, y)

    def __str__(self):
           return "{0}, \t  {1}".format(self.x, self.y)
    
    @staticmethod
    def __o1(sel = 10, cl = 20):
        return sel, cl

    def __o2(self):
        return self.x

    @classmethod
    def __o3(cls):
        return cls._pop

a = A(10, 20)
# b = A(20, 30)
# a.name ='serj'
# print(a + b)
# print(a - b)

# print(a._A__popA)
# print(a._pop)

# print(a.__dict__)

print(a._A__o1())
print(a._A__o2())
print(a._A__o3())
print(A._A__o1())
#print(A._A__o2())
print(A._A__o3())
b = copy(a)


print(a.x)
print(b.x)



def lalala():
    pass

cc = lalala()

print(type(lalala))
print(isinstance(lalala, object))
print(dir(lalala))
print(sys.getsizeof(lalala))



















# class B(A):
#     popB = 20

#     def __init__(self, x, y, z):
#         super().__init__(x, y)
#         self.z = z

#     def __add__(self, other):
#         x = self.x + other.x
#         y = self.y + other.y
#         z = self.z + other.z
#         return B(x, y, z)

#     def __sub__(self, other):
#         x = self.x - other.x
#         y = self.y - other.y
#         z = self.z - other.z
#         return B(x, y, z)

#     def __str__(self):
#        return "{0}\t{1}\t{2} ".format(self.x, self.y, self.z)
        