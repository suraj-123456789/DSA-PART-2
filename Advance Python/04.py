'''
inch into cm
cm = inch * 2.54
'''
def convert(n):
    return n * 2.54

n = int(input("Enter inche :"))
print(f"{n}inch = {convert(n)}cm")

