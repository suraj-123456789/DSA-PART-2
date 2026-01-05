'''
sum of n natural numbers
'''
def addition(n):
    total = 0
    for i in range(n+1):
        total += i
    return total

n = int(input("enter a no. :"))
if(n<0):
    print("natural numbers should be non-negavtive")
else:
    print(addition(n))