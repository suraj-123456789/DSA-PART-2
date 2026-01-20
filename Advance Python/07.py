# create a class programmer for 
# storing information of few programmers working at microsoft

class programmer:
    company = "microsoft"
    def __init__(self, name, salary, pin):
        self.name = name
        self.salary = salary
        self.pin = pin

ajay = programmer("ajay", 12000, 292738)
print(ajay.company,ajay.name, ajay.salary, ajay.pin)

vijay = programmer("vijay", 20000, 291138)
print(vijay.company,vijay.name, vijay.salary, vijay.pin)