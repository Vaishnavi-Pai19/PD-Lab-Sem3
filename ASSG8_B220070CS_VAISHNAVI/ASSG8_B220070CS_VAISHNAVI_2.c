//Vaishnavi B220070CS: Assignment 8, Question 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treenode
{
    int key;
    struct treenode* left;
    struct treenode* right;
    struct treenode* parent;
};

typedef struct treenode* node;

node create_node (int data)
{
    node new = (node)malloc(sizeof(struct treenode));
    new->left = new->right = NULL;
    new->parent = NULL;
    new->key = data;
    return new;
}

node insert_key (node root, int key)
{
    if (root == NULL)
    {
        root = create_node (key);
        return root;
    }

    if (key > root->key)
    {
        root->left = insert_key(root->left, key);
        root->left->parent = root;
    }

    else if (key < root->key)
    {
        root->right = insert_key(root->right, key);
        root->right->parent = root;
    }

    return root;
}

node find_minimum (node tree)
{
    if (tree == NULL)
    {  return 0;  }

    else
    {
        while (tree->right != NULL)
        {  tree = tree->right;  }
    }
    return tree;
}

node find_maximum (node root)
{
    if (root == NULL)
    {  return NULL;  }

    else
    {
        while (root->left != NULL)
        {  root = root->left;  }
    }
    return root;
}

node search_key (node root, int val)
{
    if (root == NULL)
    {  
       return NULL;
    }

    if (root->key == val)
    {  
       //printf ("F\n");
       return root;
    }

    if (val >= root->key)
    {   
        if (root->left == NULL)
        {  
            //printf ("N\n");
            return NULL;
        }
        return search_key (root->left, val);  
    }
    if (val <= root->key)
    {  
        if (root->right == NULL)
        {  
            //printf ("N\n");
            return NULL;
        }
        return search_key (root->right, val);
    }
    
}

int preorder_traversal (node tree_root)
{
    if (tree_root == NULL)
    {  return 0;  }

    /*else if (root->left == NULL && root->right == NULL)
    {
        printf ("%d\n", root->key);
    }*/

    printf ("%d ", tree_root->key);
    preorder_traversal (tree_root->left);
    preorder_traversal (tree_root->right);

    return 1;
}

node tree_successor (node root, int x)
{
    node pos = search_key (root, x);

    if (pos == NULL)
    {
        return NULL;
    }
    
    else 
    {
        int found = 0;
        if (pos->right !=  NULL)
        {
            return find_maximum (pos->right);
        }

        node y = pos->parent;

        while (y != NULL && pos == y->right)
        {
            pos = y;
            y = y->parent;
        }

        if (y == NULL)
        {  return NULL;  }
        return y;
    }
}

node tree_predecessor (node tree, int val)
{
    node position = search_key (tree, val);

    if (position == NULL)
    {
        return NULL;
    }
    
        if (position->left !=  NULL)
        {
            return find_minimum (position->left);
        }

        node y = position->parent;

        while (y != NULL && position == y->left)
        {
            position = y;
            y = y->parent;
        }
        
        if (y == NULL)
        {  return NULL;  }
        return y;
    }

int main ()
{
    node root = NULL;
    char val;
    int data;

    while (1)
    {
        scanf (" %c", &val);

        switch (val)
        {
            case 'a':
               scanf ("%d", &data);
               root = insert_key (root, data);
               break;
            
            case 'c':
               scanf ("%d", &data);
               node success = tree_successor (root, data);
               if (success)
               {  printf ("%d\n", success->key);  }
               else
               {  printf ("-1\n");  }
               break;
            
            case 'r':
               scanf ("%d", &data);
               node pred = tree_predecessor (root, data);
               if (pred)
               {  printf ("%d\n", pred->key);  }
               else
               {  printf ("-1\n");  }
               break;
            
            case 'p':
               //preorder_traversal (root);
               int flag2 = preorder_traversal (root);
               if (flag2 == 1)
               {  printf ("\n");  }
               else if (flag2 == 0)
               {  printf ("-1\n");  }
               break;


            case 'e':
              exit (0);
              break;
        }
    }
    return 0;
}