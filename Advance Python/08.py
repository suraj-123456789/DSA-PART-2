# write a class calculator capable
# of finding square, cube, and square root of a number

class calculator:
    def __init__(self,n):
        self.n = n
    def square(self):
        return self.n ** 2
    def cube(self):
        return self.n ** 3
        

n1 = calculator(5)
print(n1.square())

n2 = calculator(6)
print(n2.cube())