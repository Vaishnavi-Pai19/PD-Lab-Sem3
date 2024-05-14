#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct double_list {
    char data[100];
    char language[50];
    struct double_list* next;
    struct double_list* prev;
};

typedef struct double_list* node;

node createnode(char data[], char lang[])
{
    node temp;
    temp = (node)malloc(sizeof(struct double_list));
    if (temp == NULL)
    {
        exit(0);
    }
    strcpy(temp->data, data);
    strcpy(temp->language, lang);
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
   
void list_display(node head)
{
    if (head==NULL)
    {  printf ("-1\n");  }
    else 
    {  
        while (head!=NULL)
       {  printf ("%s %s\n",head->data,head->language);
          head=head->next;
       }
    }
}

node list_search (node head, char arr[])
{
    node current=head;
    while (current!=NULL)
    {
        if (strcmp(current->data, arr)==0)
        { return current; }
        else
        { current=current->next; }
    }
    return NULL;  //Element not present in the list
}

node insert_tail(node head, char data[], char language[]) 
{
    node newNode = createnode(data, language);
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    node current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head; 
}


node insert_after (node head, char song[], char lang[], char brr[])
{
    node brrnode=list_search (head, brr);
    if (brrnode==NULL)
    {
        printf ("-1\n");
        return head;
    }
    
    node newnode=createnode(song, lang);
    
    if (brrnode->next == NULL) 
    {
        newnode->next = NULL;
        newnode->prev = brrnode;
        brrnode->next = newnode;
    } 
    else 
    {
        newnode->next = brrnode->next;
        newnode->prev = brrnode;
        brrnode->next->prev = newnode;
        brrnode->next = newnode;
    }
    return head;
}

node removesong (node head, char toremove[]) 
{
    if (head == NULL) 
    {
        return NULL; // Empty list, nothing to remove
    }

    // If node to remove is the only node in the list
    if (strcmp(head->data, toremove) == 0) {
        node temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp); 
        return head;
    }

    node current = head;
    while (current->next != NULL) 
    {
        if (strcmp(current->next->data, toremove) == 0) 
        {
            node temp = current->next;
            current->next = temp->next;
            if (temp->next != NULL) 
            {
                temp->next->prev = current;
            }
            free(temp); // Free memory for the removed node
            return head; // Return the updated head
        }
        current = current->next;
        
    }
    if (current->next==NULL)
    printf ("-1\n");

    return head;
}

void display_next (node head, char arr[])
{
    node current=head;
    while (current!=NULL)
    {
        if (strcmp(current->data, arr)==0)
        {
            if (current->next!=NULL)
            {  printf ("%s %s\n", current->next->data, current->next->language);  }
            else
            {  printf ("-1\n");  }  //In case the given song has no song after it in the list
            return;
        }
            current=current->next;
    }
    printf ("-1\n"); //In case the given song is not found in the list
}

void display_previous(node head, char arr[]) 
{
    node current = head;

    while (current != NULL) 
    {
        if (strcmp(current->data, arr) == 0) 
        {
            if (current->prev != NULL) 
            {   printf("%s %s\n", current->prev->data, current->prev->language);  }
            else 
            {   printf("-1\n");  } // Given song has no previous song
            return; 
        }
        current = current->next;
    }

    printf("-1\n"); // Given song is not found in the list
}


int main()
{
    node head=NULL;
    
    char val;
    while (1)
    { scanf (" %c", &val);
    
    
     if (val=='a')
     {
        char newsong[100], lang[50], existing[100];
        scanf ("%s %s", newsong, lang);
        
        if (getchar()!='\n')
        {  scanf ("%s", existing);  }
        
        if (strcmp(existing,"")==0 || (list_search(head, existing)==NULL))
        {  head=insert_tail (head, newsong, lang);  }
        else 
        {  head=insert_after (head, newsong, lang, existing);  }
        
    }
    
    else if (val=='r')
    {
        char tbr[100];
        scanf ("%s", tbr);
        removesong (head, tbr);
    }
    
    else if (val=='n')
    {
        char song[100];
        scanf ("%s", song);
        display_next (head, song);
    }
    
    else if (val=='p')
    {
        char song[100];
        scanf ("%s", song);
        display_previous (head, song);
    }
    
    else if (val=='d')
    {
        list_display (head);
    }
    
    else if (val=='e')
       break; 
    }
    
    return 0;
}
    
    
