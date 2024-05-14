//Vaishnavi B220070CS : Assignment 7 Modification Question 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treenode 
{
    char data;
    struct treenode* left;
    struct treenode* right;
};

typedef struct treenode* node;

node create_new (char key)           //Function to create a new node for the expression tree
{
    node new = (node)malloc(sizeof(struct treenode));
    new->data = key;
    new->left = new->right = NULL;
    return new;
}

int if_operator (char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '%' || x == '^')
       return 1;
    return 0;
}

/*int stack_empty (stack check)       //Function to check if stack is empty or not
{
    if (check->top_index>=0)
    {  return 1;  }
    else
    {  return -1;  }
}


int stack_full (stack fullornot)           //Function to check whether stack is full
{
    if (fullornot->top_index==(fullornot->max-1))
    {  return -1;  }
    else
    {  return 1;  }
}*/

node construct_tree (char postfix[])        //Function to build expression tree from the given postfix expression
{
    node stack[40];
    int top = -1;

    for (int i =0; postfix[i] != '\0'; i++)
    {
        node treenode = create_new (postfix[i]);

        if (if_operator(postfix[i]) == 0)             //Operators are always the parents and never the leaves of an expression tree
        {  
            top++;
            stack[top] = treenode;
        }

        else
        {
            treenode->right = stack[top--];
            treenode->left = stack[top--];
            top++;
            stack[top] = treenode;
        }
    }
    return stack[top];       //This returns the root node of the tree
}

void inorder_traversal (node root)
{
    char data[40] = {0};
    int k=0;

    if (root)                  //Algorithm for inorder traversal of an expression tree
    {
       inorder_traversal(root->left);
       printf ("%c", root->data);
       inorder_traversal(root->right);
    }

    /*for (int x = 0; x<k; x++)
    {
        printf ("%c", data[x]);
    }*/
}

int main ()
{
    char postfix_exp[40];
    int len;

    scanf ("%d", &len);
    scanf ("%s", postfix_exp);

    node root = construct_tree (postfix_exp);

    inorder_traversal(root);
    return 0;
}