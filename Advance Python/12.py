import tkinter as tk
from tkinter import messagebox

def convert():
    celsius = entry.get()

    # Validation
    if celsius == "":
        messagebox.showerror("Error", "Please enter a value")
        return

    try:
        c = float(celsius)
        f = (9/5) * c + 32
        result_label.config(text=f"Fahrenheit: {f:.2f}")
    except ValueError:
        messagebox.showerror("Error", "Enter a valid number")

# Main Window
root = tk.Tk()
root.title("Temperature Converter")
root.geometry("300x200")

# UI Elements
tk.Label(root, text="Enter Celsius:").pack(pady=5)

entry = tk.Entry(root)
entry.pack(pady=5)

tk.Button(root, text="Convert", command=convert).pack(pady=10)

result_label = tk.Label(root, text="Fahrenheit: ")
result_label.pack(pady=5)

root.mainloop()