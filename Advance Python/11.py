from tkinter import *
from PIL import Image, ImageTk

root = Tk()
root.geometry("1000x500")
image = Image.open("luffy.jpg")
photo = ImageTk.PhotoImage(image)
label = Label(image=photo).pack()
root.mainloop()