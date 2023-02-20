#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;
void push_ele(char x)
{
    stack[++top] = x;
}

char pop_ele()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority_check(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Infix Expression : ");
    scanf("%s", exp);
    printf("\n");
    e = exp;
    printf("Postfix expression : ");
    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c ", *e);
        else if (*e == '(')
            push_ele(*e);
        else if (*e == ')')
        {
            while ((x = pop_ele()) != '(')
                printf("%c ", x);
        }
        else
        {
            while (priority_check(stack[top]) >= priority_check(*e))
                printf("%c ", pop_ele());
            push_ele(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c ", pop_ele());
    }
    return 0;
}