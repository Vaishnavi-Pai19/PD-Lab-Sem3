//Vaishnavi B220070CS : Assignment 7 Modification Question 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct operators_stack
{
    int max;
    int top;
    char* data;
};

typedef struct operators_stack* stack;

stack new_create (int capcity)             //Function to create a new stack
{
    stack new = (stack) malloc(sizeof(struct operators_stack));
    new->top =-1;
    new->max = capcity;
    new->data = (char*) malloc(capcity * sizeof(char));
    return new;
   
}

int if_operator (char x)        //Checks if a given character is an operator
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '%' || x == '#' || x == '^')
       return 1;
    return 0;
}

int precedence (char x)              //Determines the precedence of the operator passed as parameter to the function
{
    if (x == '%' || x == '#')
       return 10;
    else if (x == '+' ||x == '-')
       return 9;
    else if (x == '*' ||x == '/')
       return 7;
    else if (x == '^')
       return 6;
    else
       return 0;
}

int is_alphanum (char c)
{
    if (c >= '0' && c <= '9')
       return 1;
    else if (c >= 'A' && c <= 'Z')
       return 1;
    else if (c >= 'a' && c <= 'z')
       return 1;
    else
       return 0;
}

int empty_stack (stack cxhek)
{
    if (cxhek->top == -1)
       return 1;
    else
       return 0;
}

void push_char (stack operate, char d)
{
    operate->top++;
    operate->data[operate->top] = d;
}

char pop_char (stack operators)
{
    if (empty_stack(operators) != 1)
    {
        char key = operators->data[operators->top];
        operators->top--;
        return key;
    }
    else
    {  return '\0';  }
}

void SHOW (char* infix)
{
    int n = strlen(infix);
    stack hi = new_create (n+1);
   
    char key[1000]={0};
    int k=0;
   
    for (int i =0; i<n; i++)
    {
        char x = infix[i];
       
        if (x == ' ')
        {  continue;  }

        else if (is_alphanum(x))               //Alphanumerical characters get printed as they are
        {  
            key[k]=x;
            k++;
        }
       
        else if (if_operator (x))
        {
            while (empty_stack(hi)==0 && precedence(x) <= precedence(hi->data[hi->top]))        //Operators are stored in the stack based on their precedence
            {
                key[k] = pop_char(hi);
                k++;
            }
            push_char(hi, x);
        }

        else if (x == '(')
        {
            push_char(hi, x);
        }

        else if (x == ')')
        {
            while (empty_stack(hi)==0 && hi->data[hi->top] != '(')
            {   key[k] = pop_char(hi);
                k++;  
            }

            if (empty_stack(hi)==0 && hi->data[hi->top] == '(')            //Gets rid of the open parentheses
            {  pop_char(hi);  }
        }
    }

    while (empty_stack(hi)!=1)          //Prints the operators at the end of the postfix expression
    {  key[k] = pop_char(hi);
       k++;  
    }

    for (int i=0; i<k-1; i++)
    {
        printf ("%c ", key[i]);
    }
    printf ("%c", key[k-1]);         //Done to avoid an extra space at the end of the output
}

int main ()
{

    char infix_exp[100];
    fgets (infix_exp, sizeof(infix_exp), stdin);

    int len = strlen(infix_exp);                        //Changes the last character of the input to null character instead of newline to avoid mistakes
    if (len>0 && infix_exp[len-1] == '\n')
    {  infix_exp[len-1] = '\0';  }
   
    //printf ("%s\n", infix_exp);
    SHOW (infix_exp);
    return 0;
}