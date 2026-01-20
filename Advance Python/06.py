class student:
    name = "raj"
    div = "A"
    sub = "maths"
    marks = 85

    def __init__(self,name,div,sub,marks):
        print("Good morning!")
        self.name = name
        self.div = div
        self.sub = sub
        self.marks = marks
        self.x = 10

    def getinfo(self):
        self.x = 10
        print("suraj is of div and sub is  and marks is  ")
        print("Good morning!")

suraj = student("suraj","B","English",100)
suraj.getinfo()
abhi = student("abhi","D","chemistry",200)
print(suraj.name, suraj.div, suraj.sub, suraj.marks, suraj.x)
print(abhi.name, abhi.div, abhi.sub, abhi.marks, abhi.x)



# rohan = student()
# rohan.name = "rohan"
# print(rohan.name,rohan.div,rohan.sub,rohan.marks)

















