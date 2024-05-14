//Vaishnavi B220070CS : Assignment 7, Question 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addition (int a, int b)
{
    return a+b;
}

int subtraction (int a, int b)
{
    return a-b;
}

int multi (int a, int b)
{
    return a*b;
}

int division (int a, int b)
{
    return a/b;
}

struct stack_struct {
    int top;
    int* arr;
};

typedef struct stack_struct* stack;

stack crete_stck (int capacity)
{
    stack new = (stack) malloc (sizeof(struct stack_struct));
    new->top = -1;
    new->arr = (int*)malloc(capacity * sizeof(int));
    return new;
}

int stack_empty (stack check)          //Checks if the stack is empty or not
{
    return (check->top == -1);
}

void push_elem (stack s1, int x)      //Adds in a element at the end of the stack if it's not full yet
{
    s1->top++;
    s1->arr[s1->top]=x;
}

int pop_elem (stack s2)         //Function to pop and display the last element of the stack
{
    if (stack_empty(s2)!=1)
    {
        int val = s2->arr[s2->top];
        s2->top--;
        return val;
    }
    else
    {  return -1;  }
}

int number (char c)
{ 
    if (c >= '0' && c <= '9')
       return 1;
    else
       return 0;
}

int operator (char c)
{
    if (c== '+' || c== '-' || c== '*' || c== '/')
      return 1;
    else
      return 0;
}

int operation (int x, int y, char operator)
{
    if (operator == '+')
    {  return addition (x,y);  }

    else if (operator == '-')
    {  return subtraction (x,y);  }

    else if (operator == '*')
    {  return multi (x,y);  }

    else if (operator == '/')
    {  return division(x,y);  }
}

int calculator (char* postfix)
{
    int len = strlen (postfix);
    stack operands = crete_stck(len);
    int operator_count = 0;
    int operands_count = 0;

    for (int i=0; i<len; i++)
    {
        if (postfix[i] == ' ')       //Checking if character is a white space
        {  continue; }
        
        else if (number(postfix[i]))    //Checking if character is a number
        {  int acc_num = 0;
           while (i<len && number(postfix[i]))
           {    
               acc_num = acc_num*10 + (postfix[i] - '0');  
               i++;
            }
            i--;
            push_elem (operands, acc_num);
            operands_count++;
        }

        else if (operator(postfix[i]))    //Checking if character is an operator
        {
            if (stack_empty(operands) == 0)
            {
                //printf ("%c\n", postfix[i]);
                int op2 = pop_elem(operands);
                int op1 = pop_elem(operands);

                if (postfix[i] == '/' && op2 == 0)       //Returns -1 if division by 0 is present in the expression
                {
                    return -1;
                    break;
                }

                int result = operation (op1, op2, postfix[i]);
                //printf ("%d\n", result);
                push_elem(operands, result);
                operator_count++;
            }
            else
            {  return -1;  }   //Not enough operators for the correct postfix expression
        }

        else if (number(postfix[i])==0 && operator(postfix[i])==0)    //Checking if character is invalid
        {  return -1;  }   
    }
    
    //printf ("%d operands\n", operands_count);
    //printf ("%d operators\n", operator_count);

    if (operands_count != operator_count+1)
    {  return -1;  }

    if (stack_empty(operands) == 0)
    {
        int final = pop_elem(operands);
        if (stack_empty(operands) == 1)
        {
            return final;
        } 
    }
}


int main ()
{
    char postfix[100];
    fgets (postfix, sizeof(postfix), stdin);

    int len = strlen(postfix);
    if (len>0 && postfix[len-1] == '\n')
    {  postfix[len-1] = '\0';  }
    
    printf ("%d", calculator (postfix));
    return 0;
}