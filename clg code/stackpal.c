#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for stack node
struct Node
{
    char data;
    struct Node *next;
};

// Global pointer for top of stack
struct Node *top = NULL;

// Function to push a character onto the stack
void push(char c)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

// Function to pop a character from the stack
char pop()
{
    if (top == NULL)
        return '\0';

    struct Node *temp = top;
    char c = top->data;
    top = top->next;
    free(temp);

    return c;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str)
{
    int len = strlen(str);

    // Push all characters onto stack
    for (int i = 0; i < len; i++)
        push(str[i]);

    // Compare string with reversed characters
    for (int i = 0; i < len; i++)
    {
        if (str[i] != pop())
            return 0;
    }

    return 1;
}

// Main function
int main()
{
    char str[] = "madam";

    if (isPalindrome(str))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}