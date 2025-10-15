#include <stdio.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c)
{
    if (top == MAX - 1)
    {
        return;
    }
    stack[++top] = c;
}
char pop()
{
    if (top == -1)
    {
        return '\0';
    }
    return stack[top--];
}
int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

int issame(char *expr)
{
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[')
            push(c);
        else if (c == ')' || c == '}' || c == ']')
        {
            char popp = pop();
            if (!isMatchingPair(popp, c))
                return 0;
        }
    }
    return (top == -1);
}

int main()
{
    char expr[] = "{[(a+b),(c*d)]";
    if (issame(expr))
        printf("Same\n");
    else
        printf("Not Same\n");
    return 0;
}
