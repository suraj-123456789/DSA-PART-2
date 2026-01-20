'''
rock = 1
paper = -1
scissor = 0
'''
def game(you,computer):
    u = 0
    comp = 0
    if(you == 1 and computer == -1):
        print("Paper beats Rock, computer won!")
        comp += 1
        print(f"computer :{comp}")
        print(f"you :{u}")
    elif(you == -1 and computer == 1):
        print("Paper beats Rock, you won!")
        u += 1
        print(f"computer :{comp}")
        print(f"you :{u}")
    elif(you == -1 and computer == 0):
        print("Scissors beats Paper, computer won")
        comp += 1
        print(f"computer :{comp}")
        print(f"you :{u}")
    elif(you == 0 and computer == -1):
        print("Scissors beats Paper, you won")
        u += 1
        print(f"computer :{comp}")
        print(f"you :{u}")
    elif(you == 1 and computer == 0):
        print("rock beats scissor, you won")
        u += 1
        print(f"computer :{comp}")
        print(f"you :{u}")
    elif(you == 0 and computer == 1):
        print("rock beats scissor, computer won")
        comp += 1
        print(f"computer :{comp}")
        print(f"you :{u}")
    else:
        print("Draw!")

you = int(input("Enter your choice :"))
computer = int(input("Enter computers choice :"))
p = game(you,computer)
print(p)

