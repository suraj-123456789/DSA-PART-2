# take class student with name & marks of three subject and calculate the avg of that 

class student:
    def __init__(self,name,marks):
        self.name = name
        self.marks = marks
    def get_avg(self):
        sum = 0
        for val in self.marks:
            sum += val
        return f"{self.name} your avg score is {sum/3}"
        
a = student("suraj",[76,78,88])
print(a.get_avg())
