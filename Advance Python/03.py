'''
print this pattern

***
**
*
'''

n = int(input("enter a no. :"))
for i in range(n+1,0,-1):
    print("*" * (i),end="")
    print("")
