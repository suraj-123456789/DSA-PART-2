# take class student with name & marks of three subject and calculate the avg of that 

class student:
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks
    def get_avg(self):
        sum = 0
        for val in  self.marks:
            sum += val
        print(f"Hi {self.name} Your avg score is {sum/3} ")
        
s1 = student("suraj",[65,67,98])
s1.get_avg()