// reverce a string using stack.

#include<stdio.h>
#include<string.h>
#define max 100
char stack[max];
int top = -1;

void pushchar(char item) // 'item' stores the character from the input string
{
    if (top == max - 1)
    {
        printf("stack is full.");
    }
    else
    {
        top++;
        stack[top] = item; // Store the character in stack
    }
}
char popchar()
{
    if (top == -1)
    { 
        printf("stack is empty.");
        return '\0'; // Return null character to avoid garbage value
    }
    else
    {
        return stack[top--]; // Return the top element and then decrease top--.
    }
}
int main()
{
    int i;
    char str[max];
    printf("enter a string to reverse :");
    scanf("%s", str);
    int string_length = strlen(str);
    for (i = 0; i < string_length; i++)
    {
        pushchar(str[i]); // Push each character from str into stack
    }

    for (i = 0; i < string_length; i++) // Pop each character from the stack and put back into str
    {
        str[i] = popchar(); // Since stack is LIFO (Last In, First Out), characters will come out reversed
    }
    printf("reverse string : %s", str);
    return 0;
}
