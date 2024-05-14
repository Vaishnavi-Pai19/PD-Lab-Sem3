//Vaishnavi B220070CS: Assignment 7, Question 2

#include <stdio.h>
#include <stdlib.h>

struct node_subtree              //Struct for a node of subtree
{
    char data;
    struct node_subtree* right;
    struct node_subtree* left;
};

typedef struct node_subtree* subtree;

subtree create_stree (char x)
{
    subtree new = (subtree)malloc(sizeof(struct node_subtree));
    new->data = x;
    new->right = NULL;
    new->left = NULL;
    return new;
}

struct arr_stack           //Struct for the stack to hold operators
{
    int top;
    int capacity;
    subtree* data;
};

typedef struct arr_stack* stack;

stack create_stack (int max)
{
    stack new = (stack)malloc(sizeof(struct arr_stack));
    new->data = (subtree*)malloc(sizeof(subtree) * max);
    new->top=-1;
    new->capacity = max;
    return new;
}

int operator (char c)
{
    if (c== '+' || c== '-' || c== '*' || c== '/');
      return 1;
    return 0;
}

int precedence (char c)
{
    if (c == '+' || c == '-')
    {   return 10;   }
    if (c == '*' || c == '/')
    {   return 15;   }
    return 0;
}

int empty_stack (stack check)
{
    if (check->top == -1)
      return 1;
    return 0;
}

void push (stack hello, subtree tri)
{
    if (hello->top < hello->capacity -1)
    {
        hello->top++;
        hello->data[hello->top] = tri;
    }  
}

subtree pop(stack s)
{
    if (s->top >= 0)
    {
        subtree val=s->data[s->top];
        s->top--;
        return val;
    }
    else if (empty_stack(s)==1)
    {
        return NULL;
    }
}

//Function to build subtrees
subtree build_tree (char postfix[])
{
    stack new = create_stack (100);
    for (int j=0; postfix[j]!='\0'; j++)
    {
        if (postfix[j]>='0' && postfix[j]<='9')
        {
            subtree tri = create_stree(postfix[j]);
            push (new, tri);
        }
        else if (operator(postfix[j]))
        {
            subtree t = create_stree (postfix[j]);
            t->right = pop(new);
            t->left = pop(new);
            push (new, t);
        }
    }
    return pop(new);
}

//Function to get the infix expression
void infixexpression (subtree root_node, subtree root)
{
    if (root_node)
    {
        int high = precedence(root_node->data);
        if (root_node->left != NULL && precedence(root_node->left->data)<high && (root_node!=root))
        {
            printf ("(");
        }

        infixexpression(root_node->left, root);
        printf ("%c", root_node->data);
        infixexpression(root_node->right, root);

        if (root_node->right != NULL && precedence(root_node->right->data)<high && (root_node!=root))
        {
            printf (")");
        }
    }
}

int main ()
{
    char postfixexp[100];
    scanf ("%s", postfixexp);

    subtree root = build_tree (postfixexp);
    infixexpression (root, root);
    return 0;
}