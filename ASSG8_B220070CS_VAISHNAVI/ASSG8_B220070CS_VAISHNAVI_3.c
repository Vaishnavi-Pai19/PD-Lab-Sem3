//Vaishnavi B220070CS: Assignment 8, Question 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree_node
{
    int data;
    struct tree_node* left;
    struct tree_node* right;
    struct tree_node* parent;
};

typedef struct tree_node* node;

node crete_nde (int value)
{
    node new = (node)malloc(sizeof(struct tree_node));
    new->left = new->right = new->parent = NULL;
    new->data = value;
    return new;
}

int check_empty (node hi)
{
    if (hi == NULL)
       return 1;
    return 0;
}

node insert_node_bst (node root, int key)
{
    if (root == NULL)
    {
        root = crete_nde (key);
        return root;
    }

    if (key < root->data)
    {
        root->left = insert_node_bst (root->left, key);
        root->left->parent = root;                      //root->left is assigned the value of root after its data value is assigned
    }

    else if (key > root->data)
    {
        root->right = insert_node_bst (root->right, key);
        root->right->parent = root;                           //root->right is assigned the value of root
    }

    return root;                        //Returns the original root node of the binary search tree
}

void parenthesize (node root, node og_root)
{
    //int flag = 0;
    if (root == NULL)
    {  
        printf ("( )");
        return;  
    }

        printf ("( %d ", root->data);

        parenthesize (root->left, og_root);
        printf (" ");
        parenthesize (root->right, og_root);

        if ((root->left != NULL && root->right != NULL) && root != og_root)       //If we are not considering the root node, we need to move on the next subtree and print only a space
        {  printf (" ");  }

        if (root->left == NULL || root->right == NULL) 
        {  printf (" )");  }

        else if (root->left != NULL && root->right != NULL && root == og_root)      //If we are considering subtrees of root node, there shouldn't be a space after the last bracket
        {  printf (" )");  }
}

int main ()
{
    node root = NULL;
    char op;
    int val;

    while (1)
    {
        scanf (" %c", &op);

        switch (op)
        {
            case 'p':
               /*if (check_empty (root) == 1)
               {  printf ("( )\n");  }*/

               /*if (check_empty (root) != 1)*/
                parenthesize (root, root);  
                printf ("\n");  
                break;

            case 'i':
                scanf ("%d", &val);
                root = insert_node_bst (root, val);
                break;

            case 'e':
                exit (0);
                break;
        }
    }
    return 0;
}