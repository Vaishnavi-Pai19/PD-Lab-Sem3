//Vaishnavi B220070CS: Assignment 8, Question 1

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

node search_key (node root, int val)
{
    if (root == NULL)
    {  
       return NULL;
    }

    if (root->key == val)
    {  
       printf ("F\n");
       return root;
    }

    if (val >= root->key)
    {   
        if (root->left == NULL)
        {  
            printf ("N\n");
            return NULL;
        }
        return search_key (root->left, val);  
    }
    if (val <= root->key)
    {  
        if (root->right == NULL)
        {  
            printf ("N\n");
            return NULL;
        }
        return search_key (root->right, val);
    }
    
}

int find_minimum (node tree)
{
    if (tree == NULL)
    {  return 0;  }

    else
    {
        while (tree->right != NULL)
        {  tree = tree->right;  }
    }
    return tree->key;
}

int find_maximum (node root)
{
    if (root == NULL)
    {  return 0;  }

    else
    {
        while (root->left != NULL)
        {  root = root->left;  }
    }
    return root->key;
}

int inorder_traversal (node root)
{
    if (root == NULL)
    {  return 0;  }

    /*else if (root->left == NULL && root->right == NULL)
    {
        printf ("%d\n", root->key);
    }*/

    int arr[100] = {0};
    int count = 0;

    inorder_traversal (root->left);
    printf ("%d ", root->key);
    inorder_traversal (root->right);
    return 1;
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

int postorder_traversal (node tree)
{
    if (tree == NULL)
    {  return 0;  }

    /*else if (root->left == NULL && root->right == NULL)
    {
        printf ("%d\n", root->key);
    }*/

    postorder_traversal (tree->left);
    postorder_traversal (tree->right);
    printf ("%d ", tree->key);

    return 1;
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

            case 's':
               scanf ("%d", &data);
               if (root == NULL)
               {  continue;  }
               else
               {  search_key (root, data);  }
               break;

            case 'x':
               int max = find_maximum (root);
               if (max != 0)
               {  printf ("%d\n", max);  }
               break;
            
            case 'n':
               int min = find_minimum (root);
               if (min != 0)
               {  printf ("%d\n", min);  }
               break;
            
            case 'i':
               //inorder_traversal (root);
               int flag1 = inorder_traversal (root);
               if (flag1 == 1)
               {  printf ("\n");  }
               break;

            case 'p':
               //preorder_traversal (root);
               int flag2 = preorder_traversal (root);
               if (flag2 == 1)
               {  printf ("\n");  }
               break;

            case 't':
               //postorder_traversal (root);
               int flag3 = postorder_traversal (root);
               if (flag3 == 1)
               {  printf ("\n");  }
               break;

            case 'e':
              exit (0);
              break;
        }
    }
    return 0;
}