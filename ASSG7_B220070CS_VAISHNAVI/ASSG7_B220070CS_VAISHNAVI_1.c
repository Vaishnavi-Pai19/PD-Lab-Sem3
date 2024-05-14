//Vaishnavi B220070CS: Assignment 7, Question 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct operator_stack {
    int top;
    int capacity;
    char* arr;
};

typedef struct operator_stack* stack;

stack create_stack (int max)
{
    stack new = (stack)malloc(sizeof(struct operator_stack));
    new->top=-1;
    new->capacity=max;
    new->arr = (char*)malloc(max * sizeof(char));
    return new;
}

int operator (char c)
{
    if (c== '+' || c== '-' || c== '*' || c== '/' || c=='%')
      return 1;
    else
      return 0;
}

int precedence (char c)
{
    if (c == '+' || c == '-')
    {   return 1;   }
    if (c == '*' || c == '/' || c == '%')
    {   return 2;   }
    return 0;
}

int stack_empty (stack check)          //Checks if the stack is empty or not
{
    if (check->top == -1)
      return 1;
    else
      return 0;
}

void push_element (stack hello, char x)      //Adds in a element at the end of the stack if it's not full yet
{
    hello->top++;
    hello->arr[hello->top]=x;
}

char pop_element (stack vision)         //Function to pop and display the last element of the stack
{
    if (stack_empty(vision)!=1)
    {
        char val = vision->arr[vision->top];
        vision->top--;
        return val;
    }
    else
    {  return '\0';  }
}

//Function to change infix expression to postfix
void change_to_postfix (char* str)
{
    int i, n;
    n = strlen(str);
    stack Stack = create_stack(n+1);

    char data[1000]={0};
    int k=0;

    for (i=0; i<n; i++)
    {
        char x = str[i];

        if (x == '(')
        {
            push_element(Stack, x);
        }
        
        else if (operator (x))
        {
            while (stack_empty(Stack)==0 && precedence(x) <= precedence(Stack->arr[Stack->top]))
            {
                data[k] = pop_element(Stack);
                k++;
            }
            push_element(Stack, x);
        }

        else if (x == ')')
        {
            while (stack_empty(Stack)==0 && Stack->arr[Stack->top] != '(')
            {   data[k] = pop_element(Stack);
                k++;  
            }

            if (stack_empty(Stack)==0 && Stack->arr[Stack->top] == '(')
            {  pop_element(Stack);  }
        }
        else if (x >= 'A' && x <= 'Z')
        {  data[k]=x;
           k++; 
        }
    }

    while (stack_empty(Stack)!=1)
    {  data[k] = pop_element(Stack);
       k++;  
    }

    for (int i=0; i<k-1; i++)
    {
        printf ("%c ", data[i]);
    }
    printf ("%c", data[k-1]);

}

int main ()
{
    int n;
    scanf ("%d", &n);
    char extra;
    scanf ("%c", &extra);

    char infix_exp[100];
    fgets (infix_exp, sizeof(infix_exp), stdin);

    int len = strlen(infix_exp);
    if (len>0 && infix_exp[len-1] == '\n')
    {  infix_exp[len-1] = '\0';  }

    char infix[100];             //Getting a string without any spaces in between
    int k=0;
    for (int i=0; i<100; i++)
    {
        if (infix_exp[i]!=' ')
        {  
            infix[k]=infix_exp[i];
            k++;
        }
        else 
          continue;
    }
    
    //printf ("%s\n", infix_exp);
    //printf ("%s\n", infix);
    change_to_postfix (infix);
    return 0;
}