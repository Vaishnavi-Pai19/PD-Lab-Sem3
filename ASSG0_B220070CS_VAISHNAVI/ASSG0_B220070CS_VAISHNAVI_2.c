//Code that evaluates the answer of a postfix expression with single digit operands

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    int capacity;
    int* array;
};

typedef struct Stack *stack;

stack createNew (int capacity)
{
    stack new = (struct Stack*)malloc(sizeof(struct Stack));
 
    new->top = -1;
    new->capacity = capacity;
    new->array = (int*)malloc(new->capacity * sizeof(int));
 
    return new;
}
 
int isEmpty(stack word)
{
    return word->top == -1;
}
 
char peek(stack check)
{
    return check->array[check->top];
}
 
char pop(stack hello)
{
    if (!isEmpty(hello))
        return hello->array[hello->top--];
}
 
void push(stack green, char x)
{
    green->array[++green->top] = x;
}

char alphaNum (char x)
{
    if (x >= 65 && x <= 90)
      return 1;
    else if (x >= 97 && x <= 122)
      return 2;
    else if (x >= 48 && x <= 57)
      return 3;
    else
      return 0;
}

int postfixEval (char* exp)
{
    stack op = createNew (strlen(exp));
    int i;
   
    for (int i = 0; exp[i]; ++i)
    {
        if (alphaNum(exp[i]))
        push (op, exp[i]-'0');

    else {
            int val1 = pop(op);
            int val2 = pop(op);
            switch (exp[i])
            {
            case '+':
                push(op, val2 + val1);
                break;

            case '-':
                push(op, val2 - val1);
                break;

            case '*':
                push(op, val2 * val1);
                break;
               
            case '/':
                push(op, val2 / val1);
                break;
            }
        }
    }
    return pop(op);
}

int main ()
{
    char exp[100];
    fgets (exp, sizeof(exp), stdin);

    int len = strlen(exp);
    if (len>0 && exp[len-1] == '\n')
    {  exp[len-1] = '\0';  }
    
    printf ("%d", postfixEval (exp));
    return 0;
}
